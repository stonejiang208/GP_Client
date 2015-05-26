// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-07 11:31:01 by jiangtao> */

/* @file Data_Manager.h
 * $Id: Data_Manager.h 2015-03-03 06:14:56 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "GP_Client/Game_Data.h"
#include <map>
NS_GP_CLIENT_BEGIN

class Data_Manager
{
	typedef std::map <int, Game_Data*> Data_Map;
public:
	enum {
		SYS_DATA_CONNECTION_STATUS = 0x00011000,
	};
	Data_Manager ();
	~Data_Manager ();
	int init ();
	Game_Data*  find_data_by_id (int the_id);
	Game_Data*  get_sys_data_by_id (int the_id);
	int register_data (int the_id, Game_Data* data);
	int unregister_message (int the_id);
	void update ();
private:
	Data_Map  data_map_;
	Data_Map  system_data_map_;
};

NS_GP_CLIENT_END
#endif /* DATA_MANAGER_H */
