// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-19 10:49:36 by jiangtao> */

/* @file Net_Message.cpp
 * $Id: Net_Message.cpp 2015-05-19 02:49:35 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#include "My_User.h"
#include "Net_Message.h"
#include "cocos2d.h"
USING_NS_CC;

#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include "Game_Controller.h"

using namespace rapidjson;

Net_Message::Net_Message()
{
  
}
Net_Message::~Net_Message()
{
  
}

int Net_Message::parse_data(const char *sender, char *msg, size_t length)
{
  CCLOG ("%s,%s,%zu",sender,msg,length);
  
  My_User* user = My_User::instance ();
  if (user->is_me(sender))
  {
    CCLOG ("this msg is mine");
  }
  
  if (length > 0 && length < 1024 * 20)
  {
    Document d;
    d.Parse<0> (msg);
    if (d.HasParseError())
    {
      return -1;
    }
    
    return Game_Controller::instance ()->parse_data (sender,d);
    
  }
  return 0;
}