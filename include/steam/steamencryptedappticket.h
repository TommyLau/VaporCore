/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include "steam_api.h"

static const int k_nSteamEncryptedAppTicketSymmetricKeyLen = 32;				


S_API bool SteamEncryptedAppTicket_BDecryptTicket( const uint8 *rgubTicketEncrypted, uint32 cubTicketEncrypted,
						  uint8 *rgubTicketDecrypted, uint32 *pcubTicketDecrypted,
						  const uint8 rgubKey[k_nSteamEncryptedAppTicketSymmetricKeyLen], int cubKey );

S_API bool SteamEncryptedAppTicket_BIsTicketForApp( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted, AppId_t nAppID );

S_API RTime32 SteamEncryptedAppTicket_GetTicketIssueTime( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted );

S_API void SteamEncryptedAppTicket_GetTicketSteamID( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted, CSteamID *psteamID );

S_API AppId_t SteamEncryptedAppTicket_GetTicketAppID( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted );

S_API bool SteamEncryptedAppTicket_BUserOwnsAppInTicket( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted, AppId_t nAppID );

S_API bool SteamEncryptedAppTicket_BUserIsVacBanned( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted );

S_API const uint8 *SteamEncryptedAppTicket_GetUserVariableData( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted, uint32 *pcubUserData );

S_API bool SteamEncryptedAppTicket_BIsTicketSigned( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted, const uint8 *pubRSAKey, uint32 cubRSAKey );
