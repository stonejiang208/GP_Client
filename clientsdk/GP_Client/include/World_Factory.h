// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-14 17:29:18 by jiangtao> */

/* @file World_Factory.h
 * $Id: World_Factory.h 2015-05-04 06:24:56 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef WORLD_FACTORY_H
#define WORLD_FACTORY_H

#include "GP_Client/Namespace.h"
#include <string>
#include "GP_Client/App_Listener.h"
#include "GP_Client/Controller.h"
#include "GP_Client/User.h"

NS_GP_CLIENT_BEGIN

class World_Factory
{
public:
	template<class USER, class CTRL>
	int create_world (const char* app_id,
										const char* app_key,
										const char* address,
										unsigned short     port);
	
	void set_app_id (const char* app_id);
	void set_app_key (const char* app_key);
	void set_address (const char* address);
	void set_port (unsigned short port);
	void set_app_listener (App_Listener* al);
	void set_controller (Controller* ctrl);
	std::string get_app_id ();
	std::string get_app_key ();
	std::string get_address ();
	unsigned short get_port ();
	App_Listener* get_app_listener ();
	Controller* get_controller ();
	User*       get_user ();
	int init_game_cloud ( const char* address,
												unsigned short port,
												const char* world_id,
												const char* world_loc);

	int create_user (const char* account_name,
									 const char* account_type,
									 const char* passwd);
									 
	int init_user (const char* user_id,
								 const char* passwd,
								 const char* nickname);

	int init_guest (const char* user_id);
	void user_quit_complete ();
	void shutdown ();
public:
	static World_Factory* instance ();
	static void destroy ();
private:
	static World_Factory* instance_;
	World_Factory ();
	~World_Factory ();
	std::string    app_id_;
	std::string    app_key_;
	std::string    address_;
	unsigned short port_;
	App_Listener*  app_listener_;
	Controller*    controller_;
	User*          user_;
	bool           initialized_;
};


template <class USER,
					class CTRL>
int World_Factory::create_world (
	const char* app_id,
	const char* app_key,
	const char* address,
	unsigned short     port)
{

	controller_ = new CTRL ();
	user_ = new USER ();
	app_id_ = app_id;
	app_key_ = app_key;
	address_ = address;
	port_ = port;
	return 0;
}


NS_GP_CLIENT_END


#endif /* WORLD_FACTORY_H */
