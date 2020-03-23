// 1.) Find this:
const int aiWeaponSocketQty[WEAPON_NUM_TYPES] =
{
	3, // WEAPON_SWORD,
	3, // WEAPON_DAGGER,
	3, // WEAPON_BOW,
	3, // WEAPON_TWO_HANDED,
	3, // WEAPON_BELL,
	3, // WEAPON_FAN,
	0, // WEAPON_ARROW,
	0, // WEAPON_MOUNT_SPEAR
#ifdef ENABLE_WOLFMAN_CHARACTER
	3, // WEAPON_CLAW
#endif
};

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
const int aiWeaponSocketQty[WEAPON_NUM_TYPES] =
{
	4, // WEAPON_SWORD,
	4, // WEAPON_DAGGER,
	4, // WEAPON_BOW,
	4, // WEAPON_TWO_HANDED,
	4, // WEAPON_BELL,
	4, // WEAPON_FAN,
	0, // WEAPON_ARROW,
	0, // WEAPON_MOUNT_SPEAR
#ifdef ENABLE_WOLFMAN_CHARACTER
	4, // WEAPON_CLAW
#endif
};
#else
const int aiWeaponSocketQty[WEAPON_NUM_TYPES] =
{
	3, // WEAPON_SWORD,
	3, // WEAPON_DAGGER,
	3, // WEAPON_BOW,
	3, // WEAPON_TWO_HANDED,
	3, // WEAPON_BELL,
	3, // WEAPON_FAN,
	0, // WEAPON_ARROW,
	0, // WEAPON_MOUNT_SPEAR
#ifdef ENABLE_WOLFMAN_CHARACTER
	3, // WEAPON_CLAW
#endif
};
#endif

// 1.) Find this:
const int aiArmorSocketQty[ARMOR_NUM_TYPES] =
{
	3, // ARMOR_BODY,
	1, // ARMOR_HEAD,
	1, // ARMOR_SHIELD,
	0, // ARMOR_WRIST,
	0, // ARMOR_FOOTS,
	0  // ARMOR_ACCESSORY
};

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
const int aiArmorSocketQty[ARMOR_NUM_TYPES] =
{
	4, // ARMOR_BODY,
	1, // ARMOR_HEAD,
	1, // ARMOR_SHIELD,
	0, // ARMOR_WRIST,
	0, // ARMOR_FOOTS,
	0  // ARMOR_ACCESSORY
};
#else
const int aiArmorSocketQty[ARMOR_NUM_TYPES] =
{
	3, // ARMOR_BODY,
	1, // ARMOR_HEAD,
	1, // ARMOR_SHIELD,
	0, // ARMOR_WRIST,
	0, // ARMOR_FOOTS,
	0  // ARMOR_ACCESSORY
};
#endif


