// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-07 13:27:20 by jiangtao> */

/* @file Game_Layer.h
 * $Id: Game_Layer.h 2015-05-07 04:37:40 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef GAME_LAYER_H
#define GAME_LAYER_H

#include "CSB_Layer.h"
#include "UI_String_Text.h"

class Game_Layer
	: public CSB_Layer
	, public EditBoxDelegate
{
	typedef CSB_Layer Base;
	typedef Game_Layer Self;
public:
	Game_Layer ();
	virtual ~Game_Layer ();
	virtual std::string get_csb_filename ();
	virtual void set_callbacks (Root_Node_Type* node);
	CREATE_FUNC (Self);

	virtual void editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox);
  virtual void editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox);
  virtual void editBoxTextChanged(cocos2d::ui::EditBox* editBox,
																	const std::string& text);
  virtual void editBoxReturn(cocos2d::ui::EditBox* editBox);
public:
  void on_btn_close (Ref*);
  void on_btn_send (Ref*);
private:
  void send_i (const std::string & msg);
private:
  EditBox*  edit_box_;
  
  UI_String_Scroll*  ui_scroll_;

};

#endif /* GAME_LAYER_H */
