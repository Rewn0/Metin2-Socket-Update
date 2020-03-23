// 1.) Find this (void AuctionManager::LoadAuctionItem()):
		"SELECT id, owner_id, count, vnum, socket0, socket1, socket2, "

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
		"SELECT id, owner_id, count, vnum, socket0, socket1, socket2, socket3, "
#else
		"SELECT id, owner_id, count, vnum, socket0, socket1, socket2, "
#endif

// 1.) Find this:
		str_to_number(item.alSockets[2], row[cur++]);

// 2.) Add after this:
#ifdef ENABLE_SOCKET_UPDATE
		str_to_number(item.alSockets[3], row[cur++]);
#endif