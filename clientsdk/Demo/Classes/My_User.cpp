// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-19 12:29:01 by jiangtao> */

/* @file My_User.cpp
 * $Id: My_User.cpp 2015-05-12 05:35:44 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "My_User.h"
#include "cocos2d.h"
#include "Game_Controller.h"
#include "Msg_Define.h"
#include "GP_Client/Message_Manager.h"
#include "GP_Client/Data_Manager.h"
#include "Data_Define.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"


using namespace rapidjson;

USING_NS_CC;
My_User* My_User::instance_ = nullptr;
My_User::My_User()
{
  CCLOG ("My_User::My_User()");
	My_User::instance_ = this;
}

My_User::~My_User()
{
	My_User::instance_ = nullptr;
  CCLOG ("My_User::~My_User()");
}

My_User* My_User::instance ()
{
	return My_User::instance_;
}


void My_User::on_system_msg (unsigned int cmd_id,
                   const char* msg,
                   size_t length)
{
  CCLOG ("My_User::on_system_msg (0x%08x, %s,%zu",
          cmd_id, msg,length);
  
  if (length > 0 && length < 1024 * 20)
  {
    Document d;
    d.Parse<0> (msg);
    if (d.HasParseError())
    {
      return ;
    }
    
    Game_Controller::instance ()->parse_data ("",d);
    
  }
  
}

void My_User::on_get_app_list_complete (const char* app_id,
                                        const String_List& app_list)
{
  Data_Manager* dm = Game_Controller::instance ()->data_manager();
  String_List_Data* data = (String_List_Data*) dm->find_data_by_id(kApp_List);
  if (data)
  {
    data->value (app_list);
  }
  

}


void My_User::move_to(float x, float y, float z,float a,float b)
{
  CCLOG ("My_User::move_to (%f,%f,%f)",x,y,z);
  Document d;
  d.SetObject();
  rapidjson::Value move;
  move.SetObject();
  move.AddMember("x",x,d.GetAllocator());
  move.AddMember("y",y,d.GetAllocator());
  move.AddMember("z",z,d.GetAllocator());
  move.AddMember("a",a,d.GetAllocator());
  move.AddMember("b",b,d.GetAllocator());

  d.AddMember("move",move,d.GetAllocator());
  StringBuffer buffer;
  Writer<StringBuffer> writer(buffer);
  d.Accept(writer);
  
  unsigned int cmd_id = CMD_GAME;
  const char* msg = buffer.GetString();
  
  this->send_data(cmd_id,msg, strlen(msg)+1);

  CCLOG ("msg==> [%s]",msg);
}