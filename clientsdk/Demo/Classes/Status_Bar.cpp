// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-10 15:37:44 by jiangtao> */

/* @file Status_Bar.cpp
 * $Id: Status_Bar.cpp 2015-05-10 07:25:36 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "Status_Bar.h"


#include "Game_Controller.h"


Status_Bar::Status_Bar()
	: status_text_ (nullptr)

{
}

Status_Bar::~Status_Bar()
{
    CC_SAFE_RELEASE(status_text_);
}

std::string  Status_Bar::get_csb_filename()
{
	return "status/status_bar.csb";
}

void Status_Bar::set_callbacks(Root_Node_Type * node)
{
  Widget* root = static_cast<Widget*>(node);

  {
    std::string node_name = "Text_Status";
    auto node = static_cast<Text*>(Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      CCLOG ("found %s",node_name.c_str());
      status_text_ = node;
      node->retain();
    }
  }

}
void Status_Bar::on_status(int status)
{
  
}
void Status_Bar::on_local_msg(int status,
                          int error_code,
                          const char* msg)
{
  if (status_text_)
  {
  status_text_->setString (msg);
  }
  else
  {
    CCLOG ("Status_Bar::on_local_msg(%s)",msg);
  }
}
