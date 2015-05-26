// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-26 14:53:59 by jiangtao> */

/* @file Welcome_Layer.cpp
 * $Id: Welcome_Layer.cpp 2015-05-05 04:15:43 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "Welcome_Layer.h"
#include "GP_Client/World_Factory.h"
#include "GP_Client/Message_Manager.h"
#include "GP_Client/Data_Manager.h"
#include "GP_Client/User.h"
#include "GP_Client/Game_Data_T.h"
#include "Game_Controller.h"
#include "Game_Layer.h"
#include "Create_User_Layer.h"
#include "Lobby_Scene.h"
#include "GP_Client/World_Factory.h"
#include "GP_Client/Local_Storage.h"

//#define HOST_NAME "192.168.1.9"
#define HOST_NAME "198.12.87.192"

Welcome_Layer::Welcome_Layer()
{
}

Welcome_Layer::~Welcome_Layer()
{
 
  }

std::string Welcome_Layer::get_csb_filename()
{
  return "welcome/welcome.csb";
}


void Welcome_Layer::on_status (int status)
{
  update_ui_by_status (status);
}



void Welcome_Layer::update_ui_by_status(int status)
{
  CCLOG ("***** Welcome_Layer::update_ui_by_status(%d)",status);
  button_array_[0]->setVisible(status == 0);
  button_array_[1]->setVisible(status == 2);
  button_array_[3]->setVisible(status == 2);

  button_array_[2]->setVisible(status == 4);

	if (status == 6)
	{
    auto action = Sequence::create (
                                    DelayTime::create (0.01),
                                    CallFunc::create (CC_CALLBACK_0 (Self::enter_game,this)),nullptr);
    this->runAction (action);

	}
}

void Welcome_Layer::enter_game()
{
  
  auto s = Scene::create ();
  s->addChild (Game_Layer::create ());
  auto d = Director::getInstance ();
  d->replaceScene (s);
}
void Welcome_Layer::set_callbacks(Root_Node_Type * node)
{
  Widget* root = static_cast<Widget*>(node);
  
  {
    //
    std::string node_name ="Button_1";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_test, this));
      button_array_ [0] = node;
    }
  }
  {
    //
    std::string node_name ="Button_2";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_test2, this));
      button_array_ [1] = node;
    }
  }
  {
    //
    std::string node_name ="Button_3";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));

    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_test3, this));
      button_array_ [2] = node;
    }
  }
  
  {
    //
    std::string node_name ="Button_4";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_test4, this));
      button_array_ [3] = node;
    }
  }
  
  
  {
    //
    std::string node_name ="Button_5";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_lobby, this));
      
    }
  }
  
}

void Welcome_Layer::on_btn_test(Ref *)
{
  CCLOG ("Welcome_Layer::on_btn_test");
  World_Factory* wf = World_Factory::instance ();
  int retval = wf->init_game_cloud(
                                   HOST_NAME,
                                   2809,
                                   "World_Factory",
                                   "001");
  

  CCLOG ("init ===> %d",retval);


}

void Welcome_Layer::on_btn_test2(Ref *)
{
  CCLOG ("Welcome_Layer::on_btn_test2");
  Message_Manager* mm = Game_Controller::instance ()->message_manager();
  mm->local_msg(0,0, "hello world");
  
  World_Factory* wf = World_Factory::instance ();
  
  std::string uid = Local_Storage::instance ()->get_string_value ("user_id");
  int retval = wf->init_guest (uid.c_str());
  
  
  CCLOG ("init ===> %d",retval);

}

void Welcome_Layer::on_btn_test4(Ref *)
{
  CCLOG ("Welcome_Layer::on_btn_test4");
  Scene* s = Director::getInstance()->getRunningScene();
  s->addChild(Create_User_Layer::create());
  
}



void Welcome_Layer::on_btn_test3(Ref *)
{
  CCLOG ("Welcome_Layer::on_btn_test3");

  
   Director::getInstance()->replaceScene(Lobby_Scene::create ());
  
 // User* user = World_Factory::instance ()->get_user ();
  // baccart_lobby
 // user->enter_into_app("a", "b","baccart_lobby");
  
}


void Welcome_Layer::on_btn_lobby(Ref *)
{
  CCLOG ("Welcome_Layer::on_btn_lobby");
  
  Director::getInstance()->replaceScene(Lobby_Scene::create ());

}
