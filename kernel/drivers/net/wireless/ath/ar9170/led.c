

#include "ar9170.h"
#include "cmd.h"

int ar9170_set_leds_state(struct ar9170 *ar, u32 led_state)
{
	return ar9170_write_reg(ar, AR9170_GPIO_REG_DATA, led_state);
}

int ar9170_init_leds(struct ar9170 *ar)
{
	int err;

	/* disable LEDs */
	/* GPIO [0/1 mode: output, 2/3: input] */
	err = ar9170_write_reg(ar, AR9170_GPIO_REG_PORT_TYPE, 3);
	if (err)
		goto out;

	/* GPIO 0/1 value: off */
	err = ar9170_set_leds_state(ar, 0);

out:
	return err;
}

#ifdef CONFIG_AR9170_LEDS
static void ar9170_update_leds(struct work_struct *work)
{
	struct ar9170 *ar = container_of(work, struct ar9170, led_work.work);
	int i, tmp, blink_delay = 1000;
	u32 led_val = 0;
	bool rerun = false;

	if (unlikely(!IS_ACCEPTING_CMD(ar)))
		return ;

	mutex_lock(&ar->mutex);
	for (i = 0; i < AR9170_NUM_LEDS; i++)
		if (ar->leds[i].registered && ar->leds[i].toggled) {
			led_val |= 1 << i;

			tmp = 70 + 200 / (ar->leds[i].toggled);
			if (tmp < blink_delay)
				blink_delay = tmp;

			if (ar->leds[i].toggled > 1)
				ar->leds[i].toggled = 0;

			rerun = true;
		}

	ar9170_set_leds_state(ar, led_val);
	mutex_unlock(&ar->mutex);

	if (!rerun)
		return;

	ieee80211_queue_delayed_work(ar->hw,
				     &ar->led_work,
				     msecs_to_jiffies(blink_delay));
}

static void ar9170_led_brightness_set(struct led_classdev *led,
				      enum led_brightness brightness)
{
	struct ar9170_led *arl = container_of(led, struct ar9170_led, l);
	struct ar9170 *ar = arl->ar;

	if (unlikely(!arl->registered))
		return ;

	if (arl->last_state != !!brightness) {
		arl->toggled++;
		arl->last_state = !!brightness;
	}

	if (likely(IS_ACCEPTING_CMD(ar) && arl->toggled))
		ieee80211_queue_delayed_work(ar->hw, &ar->led_work, HZ/10);
}

static int ar9170_register_led(struct ar9170 *ar, int i, char *name,
			       char *trigger)
{
	int err;

	snprintf(ar->leds[i].name, sizeof(ar->leds[i].name),
		 "ar9170-%s::%s", wiphy_name(ar->hw->wiphy), name);

	ar->leds[i].ar = ar;
	ar->leds[i].l.name = ar->leds[i].name;
	ar->leds[i].l.brightness_set = ar9170_led_brightness_set;
	ar->leds[i].l.brightness = 0;
	ar->leds[i].l.default_trigger = trigger;

	err = led_classdev_register(wiphy_dev(ar->hw->wiphy),
				    &ar->leds[i].l);
	if (err)
		printk(KERN_ERR "%s: failed to register %s LED (%d).\n",
		       wiphy_name(ar->hw->wiphy), ar->leds[i].name, err);
	else
		ar->leds[i].registered = true;

	return err;
}

void ar9170_unregister_leds(struct ar9170 *ar)
{
	int i;

	for (i = 0; i < AR9170_NUM_LEDS; i++)
		if (ar->leds[i].registered) {
			led_classdev_unregister(&ar->leds[i].l);
			ar->leds[i].registered = false;
			ar->leds[i].toggled = 0;
		}

	cancel_delayed_work_sync(&ar->led_work);
}

int ar9170_register_leds(struct ar9170 *ar)
{
	int err;

	INIT_DELAYED_WORK(&ar->led_work, ar9170_update_leds);

	err = ar9170_register_led(ar, 0, "tx",
				  ieee80211_get_tx_led_name(ar->hw));
	if (err)
		goto fail;

	err = ar9170_register_led(ar, 1, "assoc",
				 ieee80211_get_assoc_led_name(ar->hw));
	if (err)
		goto fail;

	return 0;

fail:
	ar9170_unregister_leds(ar);
	return err;
}

#endif /* CONFIG_AR9170_LEDS */
