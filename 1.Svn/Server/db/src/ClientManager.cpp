// 1.) Find this (void CClientManager::RESULT_SAFEBOX_LOAD(CPeer * pkPeer, SQLMsg * msg)):
				"SELECT id, window+0, pos, count, vnum, socket0, socket1, socket2, "

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
				"SELECT id, window+0, pos, count, vnum, socket0, socket1, socket2, socket3, "
#else
				"SELECT id, window+0, pos, count, vnum, socket0, socket1, socket2, "
#endif

// 1.) Find this:
					DWORD dwSocket2 = 0;
					if (pItemTable->bType == ITEM_UNIQUE)
					{
						if (pItemAward->dwSocket2 != 0)
							dwSocket2 = pItemAward->dwSocket2;
						else
							dwSocket2 = pItemTable->alValues[0];
					}

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
					DWORD dwSocket3 = 0;
					if (pItemTable->bType == ITEM_UNIQUE)
					{
						if (pItemAward->dwSocket3 != 0)
							dwSocket3 = pItemAward->dwSocket3;
						else
							dwSocket3 = pItemTable->alValues[0];
					}
#else
					DWORD dwSocket2 = 0;
					if (pItemTable->bType == ITEM_UNIQUE)
					{
						if (pItemAward->dwSocket2 != 0)
							dwSocket2 = pItemAward->dwSocket2;
						else
							dwSocket2 = pItemTable->alValues[0];
					}
#endif

// 1.) Find this:
								if (pItemAward->dwSocket2 == 0)
								{
									dwSocket2 = pItemTable->alValues[0];
								}
								else
								{
									dwSocket2 = pItemAward->dwSocket2;
								}
								break;

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
								if (pItemAward->dwSocket3 == 0)
								{
									dwSocket3 = pItemTable->alValues[0];
								}
								else
								{
									dwSocket3 = pItemAward->dwSocket3;
								}
								break;
#else
								if (pItemAward->dwSocket2 == 0)
								{
									dwSocket2 = pItemTable->alValues[0];
								}
								else
								{
									dwSocket2 = pItemAward->dwSocket2;
								}
								break;
#endif

// 1.) Find this:
						snprintf(szQuery, sizeof(szQuery),
								"INSERT INTO item%s (id, owner_id, window, pos, vnum, count, socket0, socket1, socket2) "
								"VALUES(%u, %u, '%s', %d, %u, %u, %u, %u, %u)",
								GetTablePostfix(),
								GainItemID(),
								pi->account_id,
								pi->ip[0] == 0 ? "SAFEBOX" : "MALL",
								iPos,
								pItemAward->dwVnum, pItemAward->dwCount, pItemAward->dwSocket0, pItemAward->dwSocket1, dwSocket2);

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
						snprintf(szQuery, sizeof(szQuery), 
								"INSERT INTO item%s (id, owner_id, window, pos, vnum, count, socket0, socket1, socket2, socket3) "
								"VALUES(%u, %u, '%s', %d, %u, %u, %u, %u, %u, %u)",
								GetTablePostfix(),
								GainItemID(),
								pi->account_id,
								pi->ip[0] == 0 ? "SAFEBOX" : "MALL",
								iPos,
								pItemAward->dwVnum, pItemAward->dwCount, pItemAward->dwSocket0, pItemAward->dwSocket1, pItemAward->dwSocket2, dwSocket3);
#else
						snprintf(szQuery, sizeof(szQuery),
								"INSERT INTO item%s (id, owner_id, window, pos, vnum, count, socket0, socket1, socket2) "
								"VALUES(%u, %u, '%s', %d, %u, %u, %u, %u, %u)",
								GetTablePostfix(),
								GainItemID(),
								pi->account_id,
								pi->ip[0] == 0 ? "SAFEBOX" : "MALL",
								iPos,
								pItemAward->dwVnum, pItemAward->dwCount, pItemAward->dwSocket0, pItemAward->dwSocket1, dwSocket2);
#endif

// 1.) Find this:
					item.alSockets[2] = dwSocket2;

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
					item.alSockets[2] = pItemAward->dwSocket2;
					item.alSockets[3] = dwSocket3;
#else
					item.alSockets[2] = dwSocket2;
#endif

// 1.) Find this (void CClientManager::QUERY_ITEM_SAVE(CPeer * pkPeer, const char * c_pData)):
			"REPLACE INTO item%s (id, owner_id, window, pos, count, vnum, socket0, socket1, socket2, "

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
			"REPLACE INTO item%s (id, owner_id, window, pos, count, vnum, socket0, socket1, socket2, socket3, "
#else
			"REPLACE INTO item%s (id, owner_id, window, pos, count, vnum, socket0, socket1, socket2, "
#endif

// 1.) Find this:
			"VALUES(%u, %u, %d, %d, %u, %u, %ld, %ld, %ld, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)",

#ifdef ENABLE_SOCKET_UPDATE
			"VALUES(%u, %u, %d, %d, %u, %u, %ld, %ld, %ld, %ld, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)",
#else
			"VALUES(%u, %u, %d, %d, %u, %u, %ld, %ld, %ld, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)",
#endif

// 1.) Find this:
			p->alSockets[2],

// 2.) Add after this:
#ifdef ENABLE_SOCKET_UPDATE
			p->alSockets[3],
#endif







