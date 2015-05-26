// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-12 10:01:43 by jiangtao> */

/* @file Message_Manager.h
 * $Id: Message_Manager.h 2015-02-27 13:58:31 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H
#include "GP_Client/Namespace.h"
#include "GP_Client/Client_Export.h"
#include <map>

class Message_Queue_Base;

typedef unsigned long Msg_Type;

NS_GP_CLIENT_BEGIN
class Subject;

class Net_Msg_Base;
class GP_Client_Export Message_Manager
{
	typedef std::map<Msg_Type,Net_Msg_Base*> Message_Map;
public:
	Message_Manager ();
	~Message_Manager ();
	int init ();
	void update (float);
	int register_message (Msg_Type cmd_id, Net_Msg_Base* msg);
	int unregister_message (Msg_Type cmd_id);
	Net_Msg_Base* find_subject (Msg_Type cmd_id);
	Net_Msg_Base* find_system_subject (Msg_Type cmd_id);
	Subject* local_msg_subject ();
	int local_msg (int x, int y, const char* msg);
	int net_msg (Msg_Type cmd_id, const char* sender,
							 char* data, size_t length);
	int sys_msg (Msg_Type cmd_id,
							 char* data,
							 size_t length);
 private:
	int init_system_message ();
	private:

	Message_Queue_Base*  local_mq_;
	Message_Map          message_map_;
	Message_Map          system_message_map_;
	Subject*             local_msg_subject_;
	Message_Queue_Base*  net_mq_;
	Message_Queue_Base*  sys_mq_;
};

NS_GP_CLIENT_END

#endif /* MESSAGE_MANAGER_H */
