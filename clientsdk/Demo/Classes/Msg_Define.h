// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-07 14:00:35 by jiangtao> */

/* @file Msg_Define.h
 * $Id: Msg_Define.h 2015-05-07 05:58:54 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef MSG_DEFINE_H
#define MSG_DEFINE_H

#include "GP_Client/Net_Msg_Base.h"

USING_NS_GP_CLIENT;

enum
{
	CMD_CHAT = 0x00030001,
  CMD_GAME
};

class Cmd_Chat
	: public Net_Msg_Base
{
public:
  Cmd_Chat();
  virtual ~Cmd_Chat ();
	virtual int parse_data (const char* sender,
													char* msg,
													size_t length);
};

#endif /* MSG_DEFINE_H */
