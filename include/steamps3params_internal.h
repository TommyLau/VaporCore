/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef STEAM_PS3PARAMSINTERNAL_API_H
#define STEAM_PS3PARAMSINTERNAL_API_H
#ifdef _WIN32
#pragma once
#endif


//-----------------------------------------------------------------------------
// Purpose: Params used only internally at Valve. This is the reserved pointer of SteamPS3Params_t
//-----------------------------------------------------------------------------
struct SteamPS3ParamsInternal_t
{
	int m_nVersion;
	EUniverse m_eUniverse;
	const char *m_pchCMForce;		// list of CMs in form "IP:port;IP:port" or "IP;IP"
};

#define STEAM_PS3_PARAMS_INTERNAL_VERSION 1


#endif // STEAM_PS3PARAMSINTERNAL_API_H
