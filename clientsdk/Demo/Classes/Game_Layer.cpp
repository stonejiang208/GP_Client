// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-26 14:42:33 by jiangtao> */

/* @file Game_Layer.cpp
 * $Id: Game_Layer.cpp 2015-05-07 04:37:47 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "Game_Layer.h"
#include "GP_Client/World_Factory.h"
#include "GP_Client/User.h"
#include "GP_Client/Data_Manager.h"
#include "Game_Controller.h"
#include "Msg_Define.h"
#include "Data_Define.h"

USING_NS_GP_CLIENT;


Game_Layer::Game_Layer()
: edit_box_ (nullptr)
, ui_scroll_ (nullptr)
{
}

Game_Layer::~Game_Layer()
{
  CC_SAFE_DELETE(ui_scroll_);
  CC_SAFE_RELEASE(edit_box_);
}

std::string Game_Layer::get_csb_filename()
{
	return "main/main.csb";
}

void Game_Layer::set_callbacks(Root_Node_Type * node)
{
  Widget* root = static_cast<Widget*>(node);
  Data_Manager* dm = Game_Controller::instance ()->data_manager();
  
  {
    //
    std::string node_name ="Button_Close";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_close, this));
     
    }
  }
  {
    //
    std::string node_name ="Panel_2";
    auto node = static_cast<Layout*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      auto s = node->getContentSize();
      CCLOG ("size = %f,%f",s.width,s.height);
			edit_box_ = EditBox::create (s,
																	 Scale9Sprite::create ("main/2.png"));
			edit_box_->setPosition (node->getPosition ());
			this->addChild (edit_box_);
			edit_box_->setDelegate (this);
			edit_box_->setReturnType (ui::EditBox::KeyboardReturnType::DONE);
		//	edit_box_->touchDownAction (this,Widget::TouchEventType::ENDED);
      edit_box_->setFontColor(Color4B::BLACK);
    }
  }
  
  {
    //
    std::string node_name ="Button_Send";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_send, this));
      
    }
  }
  
  {
    //
    std::string node_name ="ScrollView_1";
    auto node = static_cast<ScrollView*> (Helper::seekWidgetByName(root, node_name));
    Game_Data* data = dm->find_data_by_id (kChat_Data);

    if (node && data )
    {
      ui_scroll_ = new UI_String_Scroll (data,node);
    }
  }
  
  
  
}
#if 0
Game_Layer::CREATE_FUNC(Self)
{
}
#endif


void Game_Layer::on_btn_close(Ref*)
{
  World_Factory* wf = World_Factory::instance ();
  wf->shutdown ();
  
  
  Director::getInstance()->end();
  
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif
}




void Game_Layer::editBoxEditingDidEnd (EditBox* box)
{
	std::string s = box->getText ();
	//CCLOG ("input is [%s]",s.c_str());
}

void Game_Layer::editBoxEditingDidBegin(cocos2d::ui::EditBox *editBox)
{
  
}

void Game_Layer::editBoxReturn(cocos2d::ui::EditBox *editBox)
{
  
}

void Game_Layer::editBoxTextChanged(cocos2d::ui::EditBox *editBox, const std::string &text)
{
  
}


void Game_Layer::on_btn_send(Ref*)
{
  std::string s = edit_box_->getText ();
  
  if (s.length() > 0)
  {
    send_i (s);
  }
  
  edit_box_->setText("");
  
  
}

void Game_Layer::send_i(const std::string &msg)
{
  CCLOG ("the send message is [%s]",msg.c_str());
  User* user = World_Factory::instance ()->get_user();
  unsigned int cmd_id = CMD_CHAT;
  user->send_data(cmd_id,msg.c_str(), msg.length()+1);
}


