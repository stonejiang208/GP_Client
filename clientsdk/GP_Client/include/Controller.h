// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-18 17:51:43 by jiangtao> */

/* @file Controller.h
 * $Id: Controller.h 2015-02-27 05:50:18 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Namespace.h"
#include "Client_Export.h"
#include <string>
#include <list>
typedef std::list<std::string> User_List;

class Controller_Impl;

NS_GP_CLIENT_BEGIN

class Data_Manager;
class Message_Manager;

class GP_Client_Export Controller
{
public:
	Controller ();
	virtual ~Controller ();
	virtual int init ();
	virtual int fini ();
	virtual void update (float dt);
	virtual void init_game_cloud (const char* world_id,
															 const char* world_loc,
															 const char* address,
															 unsigned short port);

	virtual void create_user (const char* account_name,
														const char* account_type,
														const char* passwd);
	
	virtual void init_user (const char* user_id,
												 const char* passwd,
												 const char* nickname);

	virtual void init_guest (const char* user_id);

	virtual void enter_into_app (const char* vendor_id,
															 const char* vendor_key,
															 const char* app_id,
															 const char* app_loc);

	
	virtual void shutdown ();
	
public:
	static Controller* instance ();	
public:
	Data_Manager*    data_manager ();
	Message_Manager* message_manager ();
  
protected:
	static Controller* instance_;
	Controller_Impl*   impl_;
};
NS_GP_CLIENT_END


#endif /* CONTROLLER_H */
