// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-23 10:29:21 by jiangtao> */

/* @file User.h
 * $Id: User.h 2015-02-27 14:49:32 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef USER_H
#define USER_H

#include "GP_Client/Namespace.h"
#include <string>
#include <list>
typedef std::list<std::string> String_List;
class User_Impl_Base;

NS_GP_CLIENT_BEGIN

class Controller;
class User
{
public:
	User ();
	virtual ~User ();
  User_Impl_Base* get_impl ();
public:
	virtual const char* get_uid ();
	virtual bool is_me (const char* uid);
public:
	virtual void keep_alive ();

	void exit_from_app ();
	virtual void enter_into_app (const char* vendor_id,
															 const char* vendor_key,
															 const char* app_id,
															 const char* app_loc);

	virtual void send_data (unsigned int msg_id,
													const char* data,
													size_t length);

	virtual void send_request (unsigned int msg_id,
														 const char* data,
														 size_t length);

	virtual void shutdown ();

	virtual void get_app_list (const char* vendor_id,
														 const char* vendor_key,
														 const char* app_id);
public:
	virtual void on_get_app_list_complete (const char* app_id,
																				 const String_List& app_list);


	virtual void on_user_enter_into_app (const char* uid,
																			 const char* app_loc);
	virtual void on_user_exit_from_app (const char* uid,
																			const char* app_loc);
	virtual void on_system_msg (unsigned int cmd_id,
															const char* msg,
															size_t length);
	
	virtual void on_request_complete (unsigned int cmd_id,
																	const char* msg,
																	size_t length);

	virtual void on_exception (int error_code,
														 const char* msg,
														 size_t length);

	
	virtual void on_disconnect ();

private:

	User_Impl_Base* impl_;
};


NS_GP_CLIENT_END

#endif /* USER_H */
