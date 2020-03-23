// 1.) Find this (void ItemAwardManager::RequestLoad()):
	snprintf(szQuery, sizeof(szQuery), "SELECT id,login,vnum,count,socket0,socket1,socket2,mall,why FROM item_award WHERE taken_time IS NULL and id > %d", g_dwLastCachedItemAwardID);

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
	snprintf(szQuery, sizeof(szQuery), "SELECT id,login,vnum,count,socket0,socket1,socket2,socket3,mall,why FROM item_award WHERE taken_time IS NULL and id > %d", g_dwLastCachedItemAwardID);
#else
	snprintf(szQuery, sizeof(szQuery), "SELECT id,login,vnum,count,socket0,socket1,socket2,mall,why FROM item_award WHERE taken_time IS NULL and id > %d", g_dwLastCachedItemAwardID);
#endif

// 1.) Find this:
		str_to_number(kData->dwSocket2, row[col++]);

// 2.) Add after this:
#ifdef ENABLE_SOCKET_UPDATE
		str_to_number(kData->dwSocket3, row[col++]);
#endif