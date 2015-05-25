// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-11 17:59:07 by jiangtao> */

/* @file Lobby_Layer.cpp
 * $Id: Lobby_Layer.cpp 2015-05-11 09:24:47 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "Lobby_Layer.h"

#include "GP_Client/World_Factory.h"
#include "GP_Client/User.h"
#include "GP_Client/Data_Manager.h"
#include "Game_Controller.h"
#include "Msg_Define.h"
#include "Data_Define.h"
#include "TerrainTest.h"

USING_NS_GP_CLIENT;

Lobby_Layer::Lobby_Layer()
: room_list_view_ (nullptr)
{
}

Lobby_Layer::~Lobby_Layer()
{
  CC_SAFE_RELEASE(room_list_view_);
}

std::string Lobby_Layer::get_csb_filename()
{
	return "lobby/lobby.csb";
}

void Lobby_Layer::onEnter()
{
  Base::onEnter();
  
  Data_Manager* dm = Game_Controller::instance ()->data_manager();
  Game_Data* data = dm->find_data_by_id(kApp_List);
  this->subject(data);
  
  // get room list
  try
  {
    User* user = World_Factory::instance ()->get_user ();
    user->get_app_list ("a","key","demo_service");
  }
  catch (const std::exception& ex)
  {
    CCLOG ("Lobby_Layer::onEnter() exception: %s",ex.what());
  }
  CCLOG ("get room list");
  room_list_.push_back("001");
  room_list_.push_back("002");
}


void Lobby_Layer::update (const Subject* s)
{
  if (s == subject_)
  {
    String_List_Data* data = (String_List_Data*) s;
    const String_List_Data::Value_Type &  app_list = data->value ();
    
    room_list_.clear ();
    for (auto i : app_list)
    {
      room_list_.push_back(i);
    }
    show_app_list();
    
    
  }
}
void Lobby_Layer::set_callbacks(Root_Node_Type * node)
{
  Widget* root = static_cast<Widget*>(node);
  {
    std::string node_name ="Button_Close";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_quit, this));
      
    }
  }
  {
    std::string node_name ="Button_Game";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_enter_game, this));
      
    }
  }
  
  {
    std::string node_name = "ListView_1";
    auto node = static_cast <ListView*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      room_list_view_ = node;
      room_list_view_->retain();
      room_list_view_->removeAllChildren();
    }
  }
}

void Lobby_Layer::on_status(int status)
{
  CCLOG ("Lobby_Layer::on_status (%d)",status);
  
  if (status == 6)
  {
    auto action = Sequence::create (
                                    DelayTime::create (0.01),
                                    CallFunc::create (CC_CALLBACK_0 (Self::enter_game,this)),nullptr);
    this->runAction (action);

  }
}

void Lobby_Layer::enter_game()
{
  
   auto s = TerrainWalkThru::create ();
 // auto s = Demo_Scene::create ();
  Director::getInstance()->replaceScene(s);
}

void Lobby_Layer::on_btn_enter_game(Ref *node)
{
 
  Widget* w = (Widget*) node;
  std::string name = w->getName ();
  
  CCLOG ("Lobby_Layer::on_btn_enter_game (%s)",name.c_str());
  
  User* user = World_Factory::instance ()->get_user ();
  // baccart_lobby
  user->enter_into_app("a", "b","demo_service",name.c_str());

  room_list_view_->setVisible(false);
  
//	Director::getInstance()->replaceScene(Game_Scene::create ());
}

void Lobby_Layer::on_btn_quit(Ref *)
{
  World_Factory* wf = World_Factory::instance ();
  wf->shutdown ();
  
  
  Director::getInstance()->end();
  
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif
  
}

void Lobby_Layer::show_app_list()
{
  if (!room_list_view_)
  {
    return;
  }
  
  
  room_list_view_->removeAllChildren();
  size_t n = room_list_.size();
  if (n >0 && n < 3 )
  {
    room_list_view_->setContentSize(Size (n * 240, 200));
  }

  for (auto i : room_list_)
  {
    add_room(room_list_view_, i.c_str());
  }

}

void Lobby_Layer::add_room(ListView* lv, const char *room_id)
{
  CCLOG ("Lobby_Layer::show_app_list() ==> [%s]",room_id);
  
  Layout *item = Layout::create ();
  item->setContentSize(Size (200,200));
  item->setBackGroundColor(Color3B (123,123,123));
  item->setTouchEnabled(true);
  item->addClickEventListener(CC_CALLBACK_1(Self::on_btn_enter_game, this));
  item->setName(room_id);
  
  Text* txt = Text::create(room_id,"",24);
  item->addChild(txt);
  txt->setPosition (Vec2 (100,100));
  lv->pushBackCustomItem(item);
}

