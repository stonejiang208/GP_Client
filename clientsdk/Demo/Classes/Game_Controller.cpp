// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-05 12:41:18 by jiangtao> */

/* @file Game_Controller.cpp
 * $Id: Game_Controller.cpp 2015-05-05 04:34:29 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "Game_Controller.h"
#include "Msg_Define.h"
#include "GP_Client/Message_Manager.h"
#include "GP_Client/Data_Manager.h"
#include "Data_Define.h"
#include "Net_Message.h"



Game_Controller* Game_Controller::instance_ = nullptr;
Game_Controller::Game_Controller()
{
	Game_Controller::instance_ = this;
}

Game_Controller::~Game_Controller()
{
	Game_Controller::instance_ = nullptr;
}

int Game_Controller::init()
{
  Base::init ();
  init_net_msg();
  init_game_data();
  return 0;
}

Game_Controller * Game_Controller::instance()
{
	return Game_Controller::instance_;
}

int Game_Controller::init_net_msg()
{
  Message_Manager* mm = this->message_manager();
  mm->register_message(CMD_CHAT, new Cmd_Chat);
  
 
  mm->register_message(CMD_GAME,new Net_Message());
  
  return 0;
}


int Game_Controller::parse_data(const char* uid,
                                const rapidjson::Document &d)
{
  if (!d.IsObject())
  {
    return -1;
  }
  
  if (d.HasMember("move") && d.IsObject())
  {
    float x = (float) d["move"]["x"].GetDouble();
    float y = (float) d["move"]["y"].GetDouble();
    float z = (float) d["move"]["z"].GetDouble();
    float a = (float) d["move"]["a"].GetDouble();
    float b = (float) d["move"]["b"].GetDouble();
    CCLOG ("%s  ===> (%f,%f,%f)",uid,x,y,z);
    Move_Msg v (x,y,z,a,b,uid);
  
    
    Data_Manager* dm = this->data_manager();
    Move_Msg_Data* data = (Move_Msg_Data*) dm->find_data_by_id(kMove_Msg);
    data->value (v);
    
  }
  return 0;
}

int Game_Controller::init_game_data()
{
  Data_Manager* dm = this->data_manager();
  dm->register_data (kChat_Data,new String_Data());
  dm->register_data (kApp_List,new String_List_Data());
  dm->register_data(kMove_Msg, new Move_Msg_Data);
  return 0;
}