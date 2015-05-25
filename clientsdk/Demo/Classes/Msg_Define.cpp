// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-07 14:01:26 by jiangtao> */

/* @file Msg_Define.cpp
 * $Id: Msg_Define.cpp 2015-05-07 05:59:03 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "Msg_Define.h"
#include "Game_Controller.h"
#include "GP_Client/Data_Manager.h"
#include "Data_Define.h"


#include "cocos2d.h"
USING_NS_CC;
Cmd_Chat::Cmd_Chat()
{
  CCLOG ("Cmd_Chat::Cmd_Chat()");
}

Cmd_Chat::~Cmd_Chat()
{
  CCLOG ("Cmd_Chat::~Cmd_Chat()");
}

int Cmd_Chat :: parse_data (const char* sender,
														char* msg,
														size_t length)
{

  Data_Manager* dm = Game_Controller::instance ()->data_manager();
  String_Data* data = (String_Data*) dm->find_data_by_id(kChat_Data);
  if (data)
  {
    std::string a = sender;
    if (a.length() > 8)
      a = a.substr(0,8);
    std::string b = msg;
    std::string c = a + " : " + b;
    
    data->value (c);
  }
  
	
	return 0;
}
