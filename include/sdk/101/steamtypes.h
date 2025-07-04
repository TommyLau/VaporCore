//========= Copyright � 1996-2008, Valve LLC, All rights reserved. ============
//
// Purpose:
//
//=============================================================================

#ifndef STEAMTYPES_H
#define STEAMTYPES_H
#ifdef _WIN32
#pragma once
#endif

// Steam-specific types. Defined here so this header file can be included in other code bases.
#ifndef WCHARTYPES_H
typedef unsigned char uint8;
#endif


#if defined(__x86_64__) || defined(_WIN64)
#define X64BITS
#endif

typedef unsigned char uint8;
typedef signed char int8;

#if defined( _WIN32 )

typedef __int16 int16;
typedef unsigned __int16 uint16;
typedef __int32 int32;
typedef unsigned __int32 uint32;
typedef __int64 int64;
typedef unsigned __int64 uint64;

#ifdef X64BITS
typedef __int64 intp;				// intp is an integer that can accomodate a pointer
typedef unsigned __int64 uintp;		// (ie, sizeof(intp) >= sizeof(int) && sizeof(intp) >= sizeof(void *)
#else
typedef __int32 intp;
typedef unsigned __int32 uintp;
#endif

#else // _WIN32

typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;
#ifdef X64BITS
typedef long long intp;
typedef unsigned long long uintp;
#else
typedef int intp;
typedef unsigned int uintp;
#endif

#endif // else _WIN32

const int k_cubDigestSize = 20;							// CryptoPP::SHA::DIGESTSIZE
const int k_cubSaltSize   = 8;

typedef	uint8 SHADigest_t[ k_cubDigestSize ];
typedef	uint8 Salt_t[ k_cubSaltSize ];

typedef uint64 GID_t;		// globally unique identifier

// this is baked into client messages and interfaces as an int, 
// make sure we never break this.
typedef uint32 PackageId_t;
const PackageId_t k_uPackageIdInvalid = 0xFFFFFFFF;


// this is baked into client messages and interfaces as an int, 
// make sure we never break this.
typedef uint32 AppId_t;
const AppId_t k_uAppIdInvalid = 0x0;

// RTime32
// We use this 32 bit time representing real world time.
// It offers 1 second resolution beginning on January 1, 1970 (Unix time)
typedef uint32 RTime32;

typedef uint32 CellID_t;

#endif // STEAMTYPES_H
