// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-12 16:26:43 by jiangtao> */

/* @file App_Listener.h
 * $Id: App_Listener.h 2015-05-04 09:02:19 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef APP_LISTENER_H
#define APP_LISTENER_H
#include "GP_Client/Namespace.h"

#include <cstddef>

class App_Listener_Impl;
NS_GP_CLIENT_BEGIN

class App_Listener
{
public:
	App_Listener ();
	virtual ~App_Listener ();
	// on_start
	virtual void on_status (int status);

	virtual void on_local_msg (int status,
														 int error_code,
														 const char* msg);
	


	virtual void on_disconnect ();

private:
	App_Listener_Impl* impl_;
};
NS_GP_CLIENT_END

#endif /* APP_LISTENER_H */
