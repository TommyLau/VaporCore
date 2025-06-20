/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <steamencryptedappticket.h>
#include "logger.h"

S_API bool SteamEncryptedAppTicket_BDecryptTicket( const uint8 *rgubTicketEncrypted, uint32 cubTicketEncrypted,
						  uint8 *rgubTicketDecrypted, uint32 *pcubTicketDecrypted,
						  const uint8 rgubKey[k_nSteamEncryptedAppTicketSymmetricKeyLen], int cubKey )
{
    VLOG_DEBUG("SteamEncryptedAppTicket_BDecryptTicket called - cubTicketEncrypted: %d", cubTicketEncrypted);
    return true;
}

S_API bool SteamEncryptedAppTicket_BIsTicketForApp( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted, AppId_t nAppID )
{
    VLOG_DEBUG("SteamEncryptedAppTicket_BIsTicketForApp called - cubTicketDecrypted: %d, nAppID: %d", cubTicketDecrypted, nAppID);
    return true;
}

S_API RTime32 SteamEncryptedAppTicket_GetTicketIssueTime( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted )
{
    VLOG_DEBUG("SteamEncryptedAppTicket_GetTicketIssueTime called - cubTicketDecrypted: %d", cubTicketDecrypted);
    return 0;
}

S_API void SteamEncryptedAppTicket_GetTicketSteamID( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted, CSteamID *psteamID )
{
    VLOG_DEBUG("SteamEncryptedAppTicket_GetTicketSteamID called - cubTicketDecrypted: %d", cubTicketDecrypted);
}

S_API AppId_t SteamEncryptedAppTicket_GetTicketAppID( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted )
{
    VLOG_DEBUG("SteamEncryptedAppTicket_GetTicketAppID called - cubTicketDecrypted: %d", cubTicketDecrypted);
    return 0;
}

S_API bool SteamEncryptedAppTicket_BUserOwnsAppInTicket( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted, AppId_t nAppID )
{
    VLOG_DEBUG("SteamEncryptedAppTicket_BUserOwnsAppInTicket called - cubTicketDecrypted: %d, nAppID: %d", cubTicketDecrypted, nAppID);
    return true;
}

S_API bool SteamEncryptedAppTicket_BUserIsVacBanned( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted )
{
    VLOG_DEBUG("SteamEncryptedAppTicket_BUserIsVacBanned called - cubTicketDecrypted: %d", cubTicketDecrypted);
    return true;
}

S_API const uint8 *SteamEncryptedAppTicket_GetUserVariableData( uint8 *rgubTicketDecrypted, uint32 cubTicketDecrypted, uint32 *pcubUserData )
{
    VLOG_DEBUG("SteamEncryptedAppTicket_GetUserVariableData called - cubTicketDecrypted: %d", cubTicketDecrypted);
    return nullptr;
}
