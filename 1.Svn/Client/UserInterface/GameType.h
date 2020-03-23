// 1.) Find this:
	ITEM_SOCKET_SLOT_MAX_NUM = 3,

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
	ITEM_SOCKET_SLOT_MAX_NUM = 4,
#else
	ITEM_SOCKET_SLOT_MAX_NUM = 3,
#endif