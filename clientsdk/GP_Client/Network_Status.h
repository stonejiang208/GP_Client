// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-03-09 13:50:10 by jiangtao> */

/* @file Network_Status.h
 * $Id: Network_Status.h 2015-03-03 07:38:10 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef NETWORK_STATUS_H
#define NETWORK_STATUS_H

#include "GP_Client/Game_Data_T.h"
NS_GP_CLIENT_BEGIN

enum Network_Type
{
	kNo_Network,
	kWWAN_Network,
	kWiFi_Network
};


// define the data


typedef Game_Data_T <Network_Type>  Network_Type_Data;


NS_GP_CLIENT_END

#endif /* NETWORK_STATUS_H */
