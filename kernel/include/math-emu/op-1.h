

#ifndef    __MATH_EMU_OP_1_H__
#define    __MATH_EMU_OP_1_H__

#define _FP_FRAC_DECL_1(X)	_FP_W_TYPE X##_f=0
#define _FP_FRAC_COPY_1(D,S)	(D##_f = S##_f)
#define _FP_FRAC_SET_1(X,I)	(X##_f = I)
#define _FP_FRAC_HIGH_1(X)	(X##_f)
#define _FP_FRAC_LOW_1(X)	(X##_f)
#define _FP_FRAC_WORD_1(X,w)	(X##_f)

#define _FP_FRAC_ADDI_1(X,I)	(X##_f += I)
#define _FP_FRAC_SLL_1(X,N)			\
  do {						\
    if (__builtin_constant_p(N) && (N) == 1)	\
      X##_f += X##_f;				\
    else					\
      X##_f <<= (N);				\
  } while (0)
#define _FP_FRAC_SRL_1(X,N)	(X##_f >>= N)

/* Right shift with sticky-lsb.  */
#define _FP_FRAC_SRS_1(X,N,sz)	__FP_FRAC_SRS_1(X##_f, N, sz)

#define __FP_FRAC_SRS_1(X,N,sz)						\
   (X = (X >> (N) | (__builtin_constant_p(N) && (N) == 1		\
		     ? X & 1 : (X << (_FP_W_TYPE_SIZE - (N))) != 0)))

#define _FP_FRAC_ADD_1(R,X,Y)	(R##_f = X##_f + Y##_f)
#define _FP_FRAC_SUB_1(R,X,Y)	(R##_f = X##_f - Y##_f)
#define _FP_FRAC_DEC_1(X,Y)	(X##_f -= Y##_f)
#define _FP_FRAC_CLZ_1(z, X)	__FP_CLZ(z, X##_f)

/* Predicates */
#define _FP_FRAC_NEGP_1(X)	((_FP_WS_TYPE)X##_f < 0)
#define _FP_FRAC_ZEROP_1(X)	(X##_f == 0)
#define _FP_FRAC_OVERP_1(fs,X)	(X##_f & _FP_OVERFLOW_##fs)
#define _FP_FRAC_CLEAR_OVERP_1(fs,X)	(X##_f &= ~_FP_OVERFLOW_##fs)
#define _FP_FRAC_EQ_1(X, Y)	(X##_f == Y##_f)
#define _FP_FRAC_GE_1(X, Y)	(X##_f >= Y##_f)
#define _FP_FRAC_GT_1(X, Y)	(X##_f > Y##_f)

#define _FP_ZEROFRAC_1		0
#define _FP_MINFRAC_1		1
#define _FP_MAXFRAC_1		(~(_FP_WS_TYPE)0)


#define _FP_UNPACK_RAW_1(fs, X, val)				\
  do {								\
    union _FP_UNION_##fs _flo; _flo.flt = (val);		\
								\
    X##_f = _flo.bits.frac;					\
    X##_e = _flo.bits.exp;					\
    X##_s = _flo.bits.sign;					\
  } while (0)

#define _FP_UNPACK_RAW_1_P(fs, X, val)				\
  do {								\
    union _FP_UNION_##fs *_flo =				\
      (union _FP_UNION_##fs *)(val);				\
								\
    X##_f = _flo->bits.frac;					\
    X##_e = _flo->bits.exp;					\
    X##_s = _flo->bits.sign;					\
  } while (0)


#define _FP_PACK_RAW_1(fs, val, X)				\
  do {								\
    union _FP_UNION_##fs _flo;					\
								\
    _flo.bits.frac = X##_f;					\
    _flo.bits.exp  = X##_e;					\
    _flo.bits.sign = X##_s;					\
								\
    (val) = _flo.flt;						\
  } while (0)

#define _FP_PACK_RAW_1_P(fs, val, X)				\
  do {								\
    union _FP_UNION_##fs *_flo =				\
      (union _FP_UNION_##fs *)(val);				\
								\
    _flo->bits.frac = X##_f;					\
    _flo->bits.exp  = X##_e;					\
    _flo->bits.sign = X##_s;					\
  } while (0)




#define _FP_MUL_MEAT_1_imm(wfracbits, R, X, Y)				\
  do {									\
    R##_f = X##_f * Y##_f;						\
    /* Normalize since we know where the msb of the multiplicands	\
       were (bit B), we know that the msb of the of the product is	\
       at either 2B or 2B-1.  */					\
    _FP_FRAC_SRS_1(R, wfracbits-1, 2*wfracbits);			\
  } while (0)

/* Given a 1W * 1W => 2W primitive, do the extended multiplication.  */

#define _FP_MUL_MEAT_1_wide(wfracbits, R, X, Y, doit)			\
  do {									\
    _FP_W_TYPE _Z_f0, _Z_f1;						\
    doit(_Z_f1, _Z_f0, X##_f, Y##_f);					\
    /* Normalize since we know where the msb of the multiplicands	\
       were (bit B), we know that the msb of the of the product is	\
       at either 2B or 2B-1.  */					\
    _FP_FRAC_SRS_2(_Z, wfracbits-1, 2*wfracbits);			\
    R##_f = _Z_f0;							\
  } while (0)

/* Finally, a simple widening multiply algorithm.  What fun!  */

#define _FP_MUL_MEAT_1_hard(wfracbits, R, X, Y)				\
  do {									\
    _FP_W_TYPE _xh, _xl, _yh, _yl, _z_f0, _z_f1, _a_f0, _a_f1;		\
									\
    /* split the words in half */					\
    _xh = X##_f >> (_FP_W_TYPE_SIZE/2);					\
    _xl = X##_f & (((_FP_W_TYPE)1 << (_FP_W_TYPE_SIZE/2)) - 1);		\
    _yh = Y##_f >> (_FP_W_TYPE_SIZE/2);					\
    _yl = Y##_f & (((_FP_W_TYPE)1 << (_FP_W_TYPE_SIZE/2)) - 1);		\
									\
    /* multiply the pieces */						\
    _z_f0 = _xl * _yl;							\
    _a_f0 = _xh * _yl;							\
    _a_f1 = _xl * _yh;							\
    _z_f1 = _xh * _yh;							\
									\
    /* reassemble into two full words */				\
    if ((_a_f0 += _a_f1) < _a_f1)					\
      _z_f1 += (_FP_W_TYPE)1 << (_FP_W_TYPE_SIZE/2);			\
    _a_f1 = _a_f0 >> (_FP_W_TYPE_SIZE/2);				\
    _a_f0 = _a_f0 << (_FP_W_TYPE_SIZE/2);				\
    _FP_FRAC_ADD_2(_z, _z, _a);						\
									\
    /* normalize */							\
    _FP_FRAC_SRS_2(_z, wfracbits - 1, 2*wfracbits);			\
    R##_f = _z_f0;							\
  } while (0)




#define _FP_DIV_MEAT_1_imm(fs, R, X, Y, doit)		\
  do {							\
    _FP_W_TYPE _q, _r;					\
    X##_f <<= (X##_f < Y##_f				\
	       ? R##_e--, _FP_WFRACBITS_##fs		\
	       : _FP_WFRACBITS_##fs - 1);		\
    doit(_q, _r, X##_f, Y##_f);				\
    R##_f = _q | (_r != 0);				\
  } while (0)


#define _FP_DIV_MEAT_1_udiv_norm(fs, R, X, Y)				\
  do {									\
    _FP_W_TYPE _nh, _nl, _q, _r, _y;					\
									\
    /* Normalize Y -- i.e. make the most significant bit set.  */	\
    _y = Y##_f << _FP_WFRACXBITS_##fs;					\
									\
    /* Shift X op correspondingly high, that is, up one full word.  */	\
    if (X##_f < Y##_f)							\
      {									\
	R##_e--;							\
	_nl = 0;							\
	_nh = X##_f;							\
      }									\
    else								\
      {									\
	_nl = X##_f << (_FP_W_TYPE_SIZE - 1);				\
	_nh = X##_f >> 1;						\
      }									\
    									\
    udiv_qrnnd(_q, _r, _nh, _nl, _y);					\
    R##_f = _q | (_r != 0);						\
  } while (0)

#define _FP_DIV_MEAT_1_udiv(fs, R, X, Y)		\
  do {							\
    _FP_W_TYPE _nh, _nl, _q, _r;			\
    if (X##_f < Y##_f)					\
      {							\
	R##_e--;					\
	_nl = X##_f << _FP_WFRACBITS_##fs;		\
	_nh = X##_f >> _FP_WFRACXBITS_##fs;		\
      }							\
    else						\
      {							\
	_nl = X##_f << (_FP_WFRACBITS_##fs - 1);	\
	_nh = X##_f >> (_FP_WFRACXBITS_##fs + 1);	\
      }							\
    udiv_qrnnd(_q, _r, _nh, _nl, Y##_f);		\
    R##_f = _q | (_r != 0);				\
  } while (0)
  
  
 
#define _FP_SQRT_MEAT_1(R, S, T, X, q)			\
  do {							\
    while (q != _FP_WORK_ROUND)				\
      {							\
        T##_f = S##_f + q;				\
        if (T##_f <= X##_f)				\
          {						\
            S##_f = T##_f + q;				\
            X##_f -= T##_f;				\
            R##_f += q;					\
          }						\
        _FP_FRAC_SLL_1(X, 1);				\
        q >>= 1;					\
      }							\
    if (X##_f)						\
      {							\
	if (S##_f < X##_f)				\
	  R##_f |= _FP_WORK_ROUND;			\
	R##_f |= _FP_WORK_STICKY;			\
      }							\
  } while (0)


#define _FP_FRAC_ASSEMBLE_1(r, X, rsize)	(r = X##_f)
#define _FP_FRAC_DISASSEMBLE_1(X, r, rsize)	(X##_f = r)



#define _FP_FRAC_CONV_1_1(dfs, sfs, D, S)				\
  do {									\
    D##_f = S##_f;							\
    if (_FP_WFRACBITS_##sfs > _FP_WFRACBITS_##dfs)			\
      {									\
	if (S##_c != FP_CLS_NAN)					\
	  _FP_FRAC_SRS_1(D, (_FP_WFRACBITS_##sfs-_FP_WFRACBITS_##dfs),	\
			 _FP_WFRACBITS_##sfs);				\
	else								\
	  _FP_FRAC_SRL_1(D, (_FP_WFRACBITS_##sfs-_FP_WFRACBITS_##dfs));	\
      }									\
    else								\
      D##_f <<= _FP_WFRACBITS_##dfs - _FP_WFRACBITS_##sfs;		\
  } while (0)

#endif /* __MATH_EMU_OP_1_H__ */