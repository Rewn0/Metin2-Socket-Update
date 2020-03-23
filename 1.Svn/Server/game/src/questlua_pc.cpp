// 1.) Find this (pc_give_award_socket):
		DBManager::instance().Query("INSERT INTO item_award (login, vnum, count, given_time, why, mall, socket0, socket1, socket2)select '%s', %d, %d, now(), '%s', 1, %s, %s, %s from DUAL where not exists (select login, why from item_award where login = '%s' and why  = '%s') ;",

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
		DBManager::instance().Query("INSERT INTO item_award (login, vnum, count, given_time, why, mall, socket0, socket1, socket2, socket3)select '%s', %d, %d, now(), '%s', 1, %s, %s, %s, %s from DUAL where not exists (select login, why from item_award where login = '%s' and why  = '%s') ;", 
#else
		DBManager::instance().Query("INSERT INTO item_award (login, vnum, count, given_time, why, mall, socket0, socket1, socket2)select '%s', %d, %d, now(), '%s', 1, %s, %s, %s from DUAL where not exists (select login, why from item_award where login = '%s' and why  = '%s') ;",
#endif