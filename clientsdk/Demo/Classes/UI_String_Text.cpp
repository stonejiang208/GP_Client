// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-03-20 15:46:27 by jiangtao> */

/* @file UI_String_Text.cpp
 * $Id: UI_String_Text.cpp 2015-03-20 07:42:33 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "UI_String_Text.h"
#include "GP_Client/Game_Data_T.h"

UI_String_Text::UI_String_Text(Subject * data, Text * ui)
	: Base (data)
	, ui_ (ui)
{
}

UI_String_Text::~UI_String_Text()
{
}

void UI_String_Text::update(const Subject * s)
{
	if (s == subject_)
	{
		String_Data* sub = (String_Data*) s;
	  const String_Data::Value_Type& v = sub->value ();
		ui_->setString (v);
	}
}



UI_String_Scroll::UI_String_Scroll (Subject * data, ScrollView * ui)
: Base (data)
, ui_ (ui)
{
  
}

UI_String_Scroll::~UI_String_Scroll ()
{
  
}


void UI_String_Scroll::update(const Subject * s)
{
  if (s == subject_)
  {
    String_Data* sub = (String_Data*) s;
    const String_Data::Value_Type& v = sub->value ();
   
    insert_string(v);
  }
}


void UI_String_Scroll::insert_string(const std::string &str)
{
  CCLOG ("UI_String_Scroll::insert_string ==> [%s]",str.c_str());
  auto txt = Text::create (str,"",24);
  msg_list_.push_back(txt);
  auto s = txt->getAutoRenderSize();
  CCLOG ("size (%f,%f)",s.width,s.height);
  auto children = ui_->getChildren();
  
  for (auto i : children)
  {
    i->setPositionY (i->getPositionY() + s.height* 1.5f);
  }
  ui_->addChild (txt);
  txt->setPosition (Vec2 (s.width /2 ,s.height/2));
  
}

