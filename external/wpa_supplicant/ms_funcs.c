
#include "includes.h"

#include "common.h"
#include "sha1.h"
#include "ms_funcs.h"
#include "crypto.h"
#include "rc4.h"


static void challenge_hash(const u8 *peer_challenge, const u8 *auth_challenge,
			   const u8 *username, size_t username_len,
			   u8 *challenge)
{
	u8 hash[SHA1_MAC_LEN];
	const unsigned char *addr[3];
	size_t len[3];

	addr[0] = peer_challenge;
	len[0] = 16;
	addr[1] = auth_challenge;
	len[1] = 16;
	addr[2] = username;
	len[2] = username_len;

	sha1_vector(3, addr, len, hash);
	os_memcpy(challenge, hash, 8);
}


void nt_password_hash(const u8 *password, size_t password_len,
		      u8 *password_hash)
{
	u8 buf[512], *pos;
	size_t i, len;

	if (password_len > 256)
		return;

	/* Convert password into unicode */
	for (i = 0; i < password_len; i++) {
		buf[2 * i] = password[i];
		buf[2 * i + 1] = 0;
	}

	len = password_len * 2;
	pos = buf;
	md4_vector(1, (const u8 **) &pos, &len, password_hash);
}


void hash_nt_password_hash(const u8 *password_hash, u8 *password_hash_hash)
{
	size_t len = 16;
	md4_vector(1, &password_hash, &len, password_hash_hash);
}


void challenge_response(const u8 *challenge, const u8 *password_hash,
			u8 *response)
{
	u8 zpwd[7];
	des_encrypt(challenge, password_hash, response);
	des_encrypt(challenge, password_hash + 7, response + 8);
	zpwd[0] = password_hash[14];
	zpwd[1] = password_hash[15];
	os_memset(zpwd + 2, 0, 5);
	des_encrypt(challenge, zpwd, response + 16);
}


void generate_nt_response(const u8 *auth_challenge, const u8 *peer_challenge,
			  const u8 *username, size_t username_len,
			  const u8 *password, size_t password_len,
			  u8 *response)
{
	u8 challenge[8];
	u8 password_hash[16];

	challenge_hash(peer_challenge, auth_challenge, username, username_len,
		       challenge);
	nt_password_hash(password, password_len, password_hash);
	challenge_response(challenge, password_hash, response);
}


void generate_nt_response_pwhash(const u8 *auth_challenge,
				 const u8 *peer_challenge,
				 const u8 *username, size_t username_len,
				 const u8 *password_hash,
				 u8 *response)
{
	u8 challenge[8];

	challenge_hash(peer_challenge, auth_challenge, username, username_len,
		       challenge);
	challenge_response(challenge, password_hash, response);
}


void generate_authenticator_response_pwhash(
	const u8 *password_hash,
	const u8 *peer_challenge, const u8 *auth_challenge,
	const u8 *username, size_t username_len,
	const u8 *nt_response, u8 *response)
{
	static const u8 magic1[39] = {
		0x4D, 0x61, 0x67, 0x69, 0x63, 0x20, 0x73, 0x65, 0x72, 0x76,
		0x65, 0x72, 0x20, 0x74, 0x6F, 0x20, 0x63, 0x6C, 0x69, 0x65,
		0x6E, 0x74, 0x20, 0x73, 0x69, 0x67, 0x6E, 0x69, 0x6E, 0x67,
		0x20, 0x63, 0x6F, 0x6E, 0x73, 0x74, 0x61, 0x6E, 0x74
	};
	static const u8 magic2[41] = {
		0x50, 0x61, 0x64, 0x20, 0x74, 0x6F, 0x20, 0x6D, 0x61, 0x6B,
		0x65, 0x20, 0x69, 0x74, 0x20, 0x64, 0x6F, 0x20, 0x6D, 0x6F,
		0x72, 0x65, 0x20, 0x74, 0x68, 0x61, 0x6E, 0x20, 0x6F, 0x6E,
		0x65, 0x20, 0x69, 0x74, 0x65, 0x72, 0x61, 0x74, 0x69, 0x6F,
		0x6E
	};

	u8 password_hash_hash[16], challenge[8];
	const unsigned char *addr1[3];
	const size_t len1[3] = { 16, 24, sizeof(magic1) };
	const unsigned char *addr2[3];
	const size_t len2[3] = { SHA1_MAC_LEN, 8, sizeof(magic2) };

	addr1[0] = password_hash_hash;
	addr1[1] = nt_response;
	addr1[2] = magic1;

	addr2[0] = response;
	addr2[1] = challenge;
	addr2[2] = magic2;

	hash_nt_password_hash(password_hash, password_hash_hash);
	sha1_vector(3, addr1, len1, response);

	challenge_hash(peer_challenge, auth_challenge, username, username_len,
		       challenge);
	sha1_vector(3, addr2, len2, response);
}


void generate_authenticator_response(const u8 *password, size_t password_len,
				     const u8 *peer_challenge,
				     const u8 *auth_challenge,
				     const u8 *username, size_t username_len,
				     const u8 *nt_response, u8 *response)
{
	u8 password_hash[16];
	nt_password_hash(password, password_len, password_hash);
	generate_authenticator_response_pwhash(password_hash,
					       peer_challenge, auth_challenge,
					       username, username_len,
					       nt_response, response);
}


void nt_challenge_response(const u8 *challenge, const u8 *password,
			   size_t password_len, u8 *response)
{
	u8 password_hash[16];
	nt_password_hash(password, password_len, password_hash);
	challenge_response(challenge, password_hash, response);
}


void get_master_key(const u8 *password_hash_hash, const u8 *nt_response,
		    u8 *master_key)
{
	static const u8 magic1[27] = {
		0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x74,
		0x68, 0x65, 0x20, 0x4d, 0x50, 0x50, 0x45, 0x20, 0x4d,
		0x61, 0x73, 0x74, 0x65, 0x72, 0x20, 0x4b, 0x65, 0x79
	};
	const unsigned char *addr[3];
	const size_t len[3] = { 16, 24, sizeof(magic1) };
	u8 hash[SHA1_MAC_LEN];

	addr[0] = password_hash_hash;
	addr[1] = nt_response;
	addr[2] = magic1;

	sha1_vector(3, addr, len, hash);
	os_memcpy(master_key, hash, 16);
}


void get_asymetric_start_key(const u8 *master_key, u8 *session_key,
			     size_t session_key_len, int is_send,
			     int is_server)
{
	static const u8 magic2[84] = {
		0x4f, 0x6e, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x6c, 0x69,
		0x65, 0x6e, 0x74, 0x20, 0x73, 0x69, 0x64, 0x65, 0x2c, 0x20,
		0x74, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x74, 0x68,
		0x65, 0x20, 0x73, 0x65, 0x6e, 0x64, 0x20, 0x6b, 0x65, 0x79,
		0x3b, 0x20, 0x6f, 0x6e, 0x20, 0x74, 0x68, 0x65, 0x20, 0x73,
		0x65, 0x72, 0x76, 0x65, 0x72, 0x20, 0x73, 0x69, 0x64, 0x65,
		0x2c, 0x20, 0x69, 0x74, 0x20, 0x69, 0x73, 0x20, 0x74, 0x68,
		0x65, 0x20, 0x72, 0x65, 0x63, 0x65, 0x69, 0x76, 0x65, 0x20,
		0x6b, 0x65, 0x79, 0x2e
	};
	static const u8 magic3[84] = {
		0x4f, 0x6e, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x6c, 0x69,
		0x65, 0x6e, 0x74, 0x20, 0x73, 0x69, 0x64, 0x65, 0x2c, 0x20,
		0x74, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x74, 0x68,
		0x65, 0x20, 0x72, 0x65, 0x63, 0x65, 0x69, 0x76, 0x65, 0x20,
		0x6b, 0x65, 0x79, 0x3b, 0x20, 0x6f, 0x6e, 0x20, 0x74, 0x68,
		0x65, 0x20, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x20, 0x73,
		0x69, 0x64, 0x65, 0x2c, 0x20, 0x69, 0x74, 0x20, 0x69, 0x73,
		0x20, 0x74, 0x68, 0x65, 0x20, 0x73, 0x65, 0x6e, 0x64, 0x20,
		0x6b, 0x65, 0x79, 0x2e
	};
	static const u8 shs_pad1[40] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

	static const u8 shs_pad2[40] = {
		0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2,
		0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2,
		0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2,
		0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2
	};
	u8 digest[SHA1_MAC_LEN];
	const unsigned char *addr[4];
	const size_t len[4] = { 16, 40, 84, 40 };

	addr[0] = master_key;
	addr[1] = shs_pad1;
	if (is_send) {
		addr[2] = is_server ? magic3 : magic2;
	} else {
		addr[2] = is_server ? magic2 : magic3;
	}
	addr[3] = shs_pad2;

	sha1_vector(4, addr, len, digest);

	if (session_key_len > SHA1_MAC_LEN)
		session_key_len = SHA1_MAC_LEN;
	os_memcpy(session_key, digest, session_key_len);
}


#define PWBLOCK_LEN 516

static void encrypt_pw_block_with_password_hash(
	const u8 *password, size_t password_len,
	const u8 *password_hash, u8 *pw_block)
{
	size_t i, offset;
	u8 *pos;

	if (password_len > 256)
		return;

	os_memset(pw_block, 0, PWBLOCK_LEN);
	offset = (256 - password_len) * 2;
	os_get_random(pw_block, offset);
	for (i = 0; i < password_len; i++)
		pw_block[offset + i * 2] = password[i];
	/*
	 * PasswordLength is 4 octets, but since the maximum password length is
	 * 256, only first two (in little endian byte order) can be non-zero.
	 */
	pos = &pw_block[2 * 256];
	WPA_PUT_LE16(pos, password_len * 2);
	rc4(pw_block, PWBLOCK_LEN, password_hash, 16);
}


void new_password_encrypted_with_old_nt_password_hash(
	const u8 *new_password, size_t new_password_len,
	const u8 *old_password, size_t old_password_len,
	u8 *encrypted_pw_block)
{
	u8 password_hash[16];

	nt_password_hash(old_password, old_password_len, password_hash);
	encrypt_pw_block_with_password_hash(new_password, new_password_len,
					    password_hash, encrypted_pw_block);
}


static void nt_password_hash_encrypted_with_block(const u8 *password_hash,
						  const u8 *block,
						  u8 *cypher)
{
	des_encrypt(password_hash, block, cypher);
	des_encrypt(password_hash + 8, block + 7, cypher + 8);
}


void old_nt_password_hash_encrypted_with_new_nt_password_hash(
	const u8 *new_password, size_t new_password_len,
	const u8 *old_password, size_t old_password_len,
	u8 *encrypted_password_hash)
{
	u8 old_password_hash[16], new_password_hash[16];

	nt_password_hash(old_password, old_password_len, old_password_hash);
	nt_password_hash(new_password, new_password_len, new_password_hash);
	nt_password_hash_encrypted_with_block(old_password_hash,
					      new_password_hash,
					      encrypted_password_hash);
}
