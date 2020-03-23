// 1.) Find this:
		if (isSocket)
		{
			iLen += snprintf(szColumns + iLen, sizeof(szColumns) - iLen, ", socket0, socket1, socket2");
			iValueLen += snprintf(szValues + iValueLen, sizeof(szValues) - iValueLen, ", %lu, %lu, %lu", p->alSockets[0], p->alSockets[1], p->alSockets[2]);
			iUpdateLen += snprintf(szUpdate + iUpdateLen, sizeof(szUpdate) - iUpdateLen, ", socket0=%lu, socket1=%lu, socket2=%lu", p->alSockets[0], p->alSockets[1], p->alSockets[2]);
		}

// 2.) And replace with this:
#ifdef ENABLE_SOCKET_UPDATE
		if (isSocket)
		{
			iLen += snprintf(szColumns + iLen, sizeof(szColumns) - iLen, ", socket0, socket1, socket2, socket3");
			iValueLen += snprintf(szValues + iValueLen, sizeof(szValues) - iValueLen, ", %lu, %lu, %lu, %lu", p->alSockets[0], p->alSockets[1], p->alSockets[2], p->alSockets[3]);
			iUpdateLen += snprintf(szUpdate + iUpdateLen, sizeof(szUpdate) - iUpdateLen, ", socket0=%lu, socket1=%lu, socket2=%lu, socket3=%lu", p->alSockets[0], p->alSockets[1], p->alSockets[2], p->alSockets[3]);
		}
#else
		if (isSocket)
		{
			iLen += snprintf(szColumns + iLen, sizeof(szColumns) - iLen, ", socket0, socket1, socket2");
			iValueLen += snprintf(szValues + iValueLen, sizeof(szValues) - iValueLen, ", %lu, %lu, %lu", p->alSockets[0], p->alSockets[1], p->alSockets[2]);
			iUpdateLen += snprintf(szUpdate + iUpdateLen, sizeof(szUpdate) - iUpdateLen, ", socket0=%lu, socket1=%lu, socket2=%lu", p->alSockets[0], p->alSockets[1], p->alSockets[2]);
		}
#endif