// 1.) Find this:
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

// 2.) Add after this:
#ifdef ENABLE_SOCKET_UPDATE
	PyModule_AddIntConstant(poModule, "ENABLE_SOCKET_UPDATE", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SOCKET_UPDATE", 0);
#endif