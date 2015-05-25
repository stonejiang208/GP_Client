// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-23 20:53:54 by jiangtao> */

/* @file Local_Settings.h
 * $Id: Local_Settings.h 2015-05-23 09:31:21 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef LOCAL_SETTINGS_H
#define LOCAL_SETTINGS_H
#include <string>
class Local_Settings_Impl;

class Local_Settings
{
public:
	int load (const std::string& config_file);
	int get_int_value (const std::string& key);
	float get_float_value (const std::string& key);
	std::string get_string_value (const std::string& key);
  static Local_Settings* instance ();
	static void  close ();

private:
	Local_Settings();
	~Local_Settings ();
	Local_Settings_Impl* impl_;
	static Local_Settings* instance_;
};

#endif /* LOCAL_SETTINGS_H */
