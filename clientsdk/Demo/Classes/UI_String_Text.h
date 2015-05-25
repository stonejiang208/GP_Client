// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-06 13:00:32 by jiangtao> */

/* @file UI_String_Text.h
 * $Id: UI_String_Text.h 2015-03-20 07:42:26 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef UI_STRING_TEXT_H
#define UI_STRING_TEXT_H


#include "GP_Client/GP_Client.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <list>
#include <string>

USING_NS_CC;
USING_NS_GP_CLIENT;
using namespace cocos2d::ui;


class UI_String_Text
	: public Observer
{
	typedef Observer Base;
public:
	UI_String_Text (Subject* data, Text* ui);
	virtual ~UI_String_Text ();
public:
	virtual void update (const Subject* s);
protected:
	Text* ui_;
};


class UI_String_Scroll
: public Observer
{
  typedef Observer Base;
  typedef std::list<Text*> Msg_List;
public:
  UI_String_Scroll (Subject* data, ScrollView* ui);
  virtual ~UI_String_Scroll ();
public:
  virtual void update (const Subject* s);
  
public:
  void insert_string(const std::string& s);
protected:
  ScrollView* ui_;
  Msg_List  msg_list_;
};


#endif /* UI_STRING_TEXT_H */
