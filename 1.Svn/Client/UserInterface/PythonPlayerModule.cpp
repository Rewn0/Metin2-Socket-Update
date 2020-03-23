// 1.) Find this (PyObject * playerGetItemLink(PyObject * poSelf, PyObject * poArgs)):
		len = snprintf(itemlink, sizeof(itemlink), "item:%x:%x:%x:%x:%x", pPlayerItem->vnum, pPlayerItem->flags, pPlayerItem->alSockets[0], pPlayerItem->alSockets[1], pPlayerItem->alSockets[2]);

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
		len = snprintf(itemlink, sizeof(itemlink), "item:%x:%x:%x:%x:%x:%x", pPlayerItem->vnum, pPlayerItem->flags, pPlayerItem->alSockets[0], pPlayerItem->alSockets[1], pPlayerItem->alSockets[2], pPlayerItem->alSockets[3]);
#else
		len = snprintf(itemlink, sizeof(itemlink), "item:%x:%x:%x:%x:%x", pPlayerItem->vnum, pPlayerItem->flags, pPlayerItem->alSockets[0], pPlayerItem->alSockets[1], pPlayerItem->alSockets[2]);
#endif