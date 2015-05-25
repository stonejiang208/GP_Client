// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-19 12:27:46 by jiangtao> */

/* @file My_User.h
 * $Id: My_User.h 2015-05-12 05:35:39 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef MY_USER_H
#define MY_USER_H

#include "GP_Client/User.h"

USING_NS_GP_CLIENT;

class My_User
	: public User
{
public:
	My_User ();
	virtual ~My_User ();
  virtual void on_system_msg (unsigned int cmd_id,
                              const char* msg,
                              size_t length);
  virtual void on_get_app_list_complete (const char* app_id,
                                         const String_List& app_list);
  
public:
  void move_to (float x, float y, float z,float a,float b);
  
public:
  static My_User* instance ();
private:
	static My_User* instance_;
};

#endif /* MY_USER_H */
