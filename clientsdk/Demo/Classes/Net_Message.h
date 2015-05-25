// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-19 10:49:28 by jiangtao> */

/* @file Net_Message.h
 * $Id: Net_Message.h 2015-05-19 02:49:27 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef NET_MESSAGE_H
#define NET_MESSAGE_H

#include "GP_Client/Net_Msg_Base.h"
USING_NS_GP_CLIENT;

class Net_Message
: public Net_Msg_Base
{
public:
  Net_Message ();
  virtual ~Net_Message ();
  virtual int parse_data (const char* sender,
                          char* msg, size_t length);
  
private:
  
  
};

#endif /* NET_MESSAGE_H */
