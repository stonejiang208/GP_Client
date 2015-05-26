// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-24 00:01:38 by jiangtao> */

/* @file Local_Storage.h
 * $Id: Local_Storage.h 2015-05-23 02:47:51 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef LOCAL_STORAGE_H
#define LOCAL_STORAGE_H
#include <string>
#include "GP_Client/Data_Types.h"

class Local_Storage_Impl;
class Local_Storage
{
private:
	Local_Storage ();
	~Local_Storage ();
public:
	void set_writeable_path (const std::string& writeable_path);
	int load ();
	int save ();
	int get_int_value (const std::string& key);
	float get_float_value (const std::string& key);
	std::string get_string_value (const std::string& key);
	void set_int_value (const std::string& key, int v);
	void set_float_value (const std::string& key, float v);
	void set_string_value (const std::string& key, const std::string& v);
	String_List get_string_list (const char* key);
	void append_string_to_list (const char* key, const char* v);
	Int_List get_int_list (const char* key);
	void append_int_to_list(const char* key, int v);
	
  static Local_Storage* instance ();
	static void  close ();
private:
	static Local_Storage* instance_;
	Local_Storage_Impl* impl_;
};

#endif /* LOCAL_STORAGE_H */
