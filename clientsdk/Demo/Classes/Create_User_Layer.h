// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-09 14:48:55 by jiangtao> */

/* @file Create_User_Layer.h
 * $Id: Create_User_Layer.h 2015-05-09 06:45:56 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef CREATE_USER_LAYER_H
#define CREATE_USER_LAYER_H

#include "CSB_Layer.h"

class Create_User_Layer
	: public CSB_Layer
  , public EditBoxDelegate
{
	typedef Create_User_Layer Self;
	typedef CSB_Layer Base;
public:
	Create_User_Layer ();
	virtual ~Create_User_Layer ();
	virtual std::string get_csb_filename ();
	virtual void set_callbacks (Root_Node_Type* node);
  virtual void editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox);
  virtual void editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox);
  virtual void editBoxTextChanged(cocos2d::ui::EditBox* editBox,
                                  const std::string& text);
  virtual void editBoxReturn(cocos2d::ui::EditBox* editBox);
  
	CREATE_FUNC (Self);
public:
	void on_btn_cancel (Ref*);
	void on_btn_ok (Ref*);
  void do_create_user (const std::string& name,
                       const std::string& passwd);
protected:
  void dismiss ();
  EditBox* eb_name_;
  EditBox* eb_passwd_;
  EditBox* eb_passwd2_;
};

#endif /* CREATE_USER_LAYER_H */
