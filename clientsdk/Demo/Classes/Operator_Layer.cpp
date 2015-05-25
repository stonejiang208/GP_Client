// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-21 22:07:59 by jiangtao> */

/* @file Operator_Layer.cpp
 * $Id: Operator_Layer.cpp 2015-05-21 14:04:32 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "Operator_Layer.h"
#include "GP_Client/World_Factory.h"
#include "My_User.h"
#include "Lobby_Scene.h"
USING_NS_GP_CLIENT;

std::string Operator_Layer::get_csb_filename()
{
	return "settings/operator-layer.csb";
}

void Operator_Layer::set_callbacks(Root_Node_Type * node)
{
	 Widget* root = static_cast<Widget*>(node);
  {
    std::string node_name ="Button_Exit_App";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_app_exit, this));
      
    }
  }
  {
    std::string node_name ="Button_Lobby";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_lobby, this));
      
    }
  }
  
}


void Operator_Layer::on_app_exit(Ref *)
{
  World_Factory* wf = World_Factory::instance ();
  wf->shutdown ();
  
  
  Director::getInstance()->end();
  
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif

}

void Operator_Layer::on_lobby(cocos2d::Ref *)
{
  My_User* user = My_User::instance();
  try
  {
    user->exit_from_app();
  }catch (const std::exception& ex)
  {
    CCLOG ("exception:%s",ex.what());
  }
  Director::getInstance()->replaceScene(Lobby_Scene::create ());
}
