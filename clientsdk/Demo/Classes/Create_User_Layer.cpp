// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-09 14:54:10 by jiangtao> */

/* @file Create_User_Layer.cpp
 * $Id: Create_User_Layer.cpp 2015-05-09 06:46:02 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "Create_User_Layer.h"
#include "GP_Client/World_Factory.h"

USING_NS_GP_CLIENT;

Create_User_Layer::Create_User_Layer ()
: eb_name_(nullptr)
, eb_passwd_(nullptr)
, eb_passwd2_(nullptr)
{
}

Create_User_Layer::~Create_User_Layer ()
{
}

std::string Create_User_Layer::get_csb_filename ()
{
	return "welcome/create-user.csb";
}

void Create_User_Layer::set_callbacks (Root_Node_Type* node)
{
  Widget* root = static_cast<Widget*>(node);
  
  {
    //
    std::string node_name ="Button_OK";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_ok, this));
    }
  }
  
  {
    //
    std::string node_name ="Button_Cancel";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_cancel, this));
    }
  }
  
  {
    //
    std::string node_name ="Panel_1";
    auto node = static_cast<Layout*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      auto s = node->getContentSize();
      CCLOG ("size = %f,%f",s.width,s.height);
      eb_name_ = EditBox::create (s,
                                   Scale9Sprite::create ("Default/Button_Normal.png"));
      eb_name_->setPosition (node->getPosition ());
      node->getParent()->addChild (eb_name_);
      eb_name_->setDelegate (this);
      eb_name_->setReturnType (ui::EditBox::KeyboardReturnType::DONE);
      //	edit_box_->touchDownAction (this,Widget::TouchEventType::ENDED);
      eb_name_->setFontColor(Color4B::BLACK);
    }
  }

  {
    //
    std::string node_name ="Panel_1";
    auto node = static_cast<Layout*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      auto s = node->getContentSize();
      CCLOG ("size = %f,%f",s.width,s.height);
      eb_name_ = EditBox::create (s,
                                  Scale9Sprite::create ("Default/Button_Normal.png"));
      eb_name_->setPosition (node->getPosition ());
      node->getParent()->addChild (eb_name_);
      eb_name_->setDelegate (this);
      eb_name_->setReturnType (ui::EditBox::KeyboardReturnType::DONE);
      //	edit_box_->touchDownAction (this,Widget::TouchEventType::ENDED);
      eb_name_->setFontColor(Color4B::BLACK);
    }
  }
  {
    //
    std::string node_name ="Panel_1_0";
    auto node = static_cast<Layout*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      auto s = node->getContentSize();
      CCLOG ("size = %f,%f",s.width,s.height);
      eb_passwd_ = EditBox::create (s,
                                  Scale9Sprite::create ("Default/Button_Normal.png"));
      eb_passwd_->setPosition (node->getPosition ());
      node->getParent()->addChild (eb_passwd_);
      eb_passwd_->setDelegate (this);
      eb_passwd_->setReturnType (ui::EditBox::KeyboardReturnType::DONE);
      //	edit_box_->touchDownAction (this,Widget::TouchEventType::ENDED);
      eb_passwd_->setFontColor(Color4B::BLACK);
      eb_passwd_->setInputFlag(EditBox::InputFlag::PASSWORD);
    }
  }
  
  {
    //
    std::string node_name ="Panel_1_0_0";
    auto node = static_cast<Layout*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      auto s = node->getContentSize();
      CCLOG ("size = %f,%f",s.width,s.height);
      eb_passwd2_ = EditBox::create (s,
                                    Scale9Sprite::create ("Default/Button_Normal.png"));
      eb_passwd2_->setPosition (node->getPosition ());
      node->getParent()->addChild (eb_passwd2_);
      eb_passwd2_->setDelegate (this);
      eb_passwd2_->setReturnType (ui::EditBox::KeyboardReturnType::DONE);
      //	edit_box_->touchDownAction (this,Widget::TouchEventType::ENDED);
      eb_passwd2_->setFontColor(Color4B::BLACK);
      eb_passwd2_->setInputFlag(EditBox::InputFlag::PASSWORD);
    }
  }
  
  
  
}

void Create_User_Layer::on_btn_ok (Ref*)
{
#if 0
  auto action = Sequence::create (
                                  DelayTime::create (0.01),
                                  CallFunc::create (CC_CALLBACK_0 (Self::dismiss,this)),nullptr);
  this->runAction (action);
#endif
  
  std::string name = eb_name_->getText();
  std::string passwd = eb_passwd_->getText();
  std::string passwd2 = eb_passwd2_->getText();
  
  CCLOG ("***** [%s] [%s] [%s]",
         name.c_str(),
         passwd.c_str(),
         passwd2.c_str());
#if 0
  if ((name.length() > 6 && name.length() < 20)
     && (passwd == passwd2)
     && (passwd.length () > 6 && passwd.length ()  < 20))
#endif
  {
    do_create_user (name,passwd);
  }
  
 // dismiss();
}

void Create_User_Layer::on_btn_cancel (Ref*)
{
  auto action = Sequence::create (
                                  DelayTime::create (0.01),
                                  CallFunc::create (CC_CALLBACK_0 (Self::dismiss,this)),nullptr);
  this->runAction (action);
}

void Create_User_Layer::dismiss()
{
  this->removeFromParent();
}


void Create_User_Layer::editBoxEditingDidEnd (EditBox* box)
{
  std::string s = box->getText ();
  //CCLOG ("input is [%s]",s.c_str());
}

void Create_User_Layer::editBoxEditingDidBegin(cocos2d::ui::EditBox *editBox)
{
  
}

void Create_User_Layer::editBoxReturn(cocos2d::ui::EditBox *editBox)
{
  
}

void Create_User_Layer::editBoxTextChanged(cocos2d::ui::EditBox *editBox, const std::string &text)
{
  
}

void Create_User_Layer::do_create_user(const std::string &name, const std::string &passwd)
{
  CCLOG ("*do_create_user*** [%s] [%s]",
         name.c_str(),
         passwd.c_str());
  
  std::string account_type = "gamecoud";
  int n =  World_Factory::instance ()->create_user(name.c_str(),
                                                   account_type.c_str(),
                                                   passwd.c_str());
  if (n != 0)
  {
    CCLOG ("init user error");
  }
}
