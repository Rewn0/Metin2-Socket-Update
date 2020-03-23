// 1.) Find this:
		str_to_number(item.alSockets[2], row[cur++]);

// 2.) Add after this:
#ifdef ENABLE_SOCKET_UPDATE
		str_to_number(item.alSockets[3], row[cur++]);
#endif

// 1.) Find this (void CClientManager::QUERY_PLAYER_LOAD(CPeer * peer, DWORD dwHandle, TPlayerLoadPacket * packet)):
			snprintf(szQuery, sizeof(szQuery),
					"SELECT id,window+0,pos,count,vnum,socket0,socket1,socket2,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
					"FROM item%s WHERE owner_id=%d AND (window in ('INVENTORY','EQUIPMENT','DRAGON_SOUL_INVENTORY','BELT_INVENTORY'))",
					GetTablePostfix(), pTab->id);

			/*If can not find search this:
			CDBManager::instance().ReturnQuery(szQuery,
					QID_ITEM,
					peer->GetHandle(),
					new ClientHandleInfo(dwHandle, pTab->id));
			snprintf(szQuery, sizeof(szQuery),
					"SELECT dwPID, szName, szState, lValue FROM quest%s WHERE dwPID=%d",
					GetTablePostfix(), pTab->id);
			*/

// 2.) And replace with this:
			snprintf(szQuery, sizeof(szQuery),
#ifdef ENABLE_SOCKET_UPDATE
					"SELECT id,window+0,pos,count,vnum,socket0,socket1,socket2,socket3,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
#else
					"SELECT id,window+0,pos,count,vnum,socket0,socket1,socket2,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
#endif
					"FROM item%s WHERE owner_id=%d AND (window in ('INVENTORY','EQUIPMENT','DRAGON_SOUL_INVENTORY','BELT_INVENTORY'))",
					GetTablePostfix(), pTab->id);

// 1.) Find this:
		snprintf(queryStr, sizeof(queryStr),
				"SELECT id,window+0,pos,count,vnum,socket0,socket1,socket2,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
				"FROM item%s WHERE owner_id=%d AND (window in ('INVENTORY','EQUIPMENT','DRAGON_SOUL_INVENTORY','BELT_INVENTORY'))",
				GetTablePostfix(), packet->player_id);
		CDBManager::instance().ReturnQuery(queryStr, QID_ITEM, peer->GetHandle(), new ClientHandleInfo(dwHandle, packet->player_id));

// 2.) And replace with this:
		snprintf(queryStr, sizeof(queryStr),
#ifdef ENABLE_SOCKET_UPDATE
				"SELECT id,window+0,pos,count,vnum,socket0,socket1,socket2,socket3,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
#else
				"SELECT id,window+0,pos,count,vnum,socket0,socket1,socket2,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
#endif
				"FROM item%s WHERE owner_id=%d AND (window in ('INVENTORY','EQUIPMENT','DRAGON_SOUL_INVENTORY','BELT_INVENTORY'))",
				GetTablePostfix(), packet->player_id);
		CDBManager::instance().ReturnQuery(queryStr, QID_ITEM, peer->GetHandle(), new ClientHandleInfo(dwHandle, packet->player_id));