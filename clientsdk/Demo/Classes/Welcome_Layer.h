// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-05 12:18:09 by jiangtao> */

/* @file Welcome_Layer.h
 * $Id: Welcome_Layer.h 2015-05-05 04:15:39 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef WELCOME_LAYER_H
#define WELCOME_LAYER_H

#include "CSB_Layer.h"
#include "GP_Client/App_Listener.h"
#include <array>

typedef std::array<Button*,4> Button_Array;
USING_NS_GP_CLIENT;

class Welcome_Layer
	: public CSB_Layer
 , public GP_Client::App_Listener
{
	typedef Welcome_Layer Self;
	typedef CSB_Layer Base;
public:
	Welcome_Layer ();
	virtual ~Welcome_Layer ();
	virtual std::string get_csb_filename ();
	virtual void set_callbacks (Root_Node_Type* node);
  virtual void on_status (int status);
  
	CREATE_FUNC (Self);
  
public:
  void update_ui_by_status (int status);
private:
	void on_btn_test (Ref*);
  void on_btn_test2 (Ref*);
  void on_btn_test3 (Ref*);
  void on_btn_test4 (Ref*);
  void on_btn_lobby (Ref*);
  void enter_game ();
private:
  Button_Array    button_array_;
};

#endif /* WELCOME_LAYER_H */
