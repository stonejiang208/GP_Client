// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-09 13:59:38 by jiangtao> */

/* @file Net_Msg_Base.h
 * $Id: Net_Msg_Base.h 2015-04-01 06:45:45 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef NET_MSG_BASE_H
#define NET_MSG_BASE_H
#include "GP_Client/Namespace.h"
#include <string>


NS_GP_CLIENT_BEGIN
class Net_Msg_Base
{
public:
	Net_Msg_Base ();
	virtual ~Net_Msg_Base ();

	virtual int parse_data (const char* sender,
													char* msg, size_t length);

	virtual int parse_data (const char* sender);

	virtual int parse_data (unsigned int, char*, size_t);

	virtual int parse_data (unsigned int);
};

NS_GP_CLIENT_END

#endif /* NET_MSG_BASE_H */
