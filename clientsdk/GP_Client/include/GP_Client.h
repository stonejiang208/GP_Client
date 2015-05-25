// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-23 14:57:04 by jiangtao> */

/* @file GP_Client.h
 * $Id: GP_Client.h 2015-03-07 07:45:25 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef GP_CLIENT_H
#define GP_CLIENT_H

#include "GP_Client/Controller.h"
#include "GP_Client/User.h"
#include "GP_Client/Data_Manager.h"
#include "GP_Client/Message_Manager.h"
#include "GP_Client/Observer.h"
#include "GP_Client/Subject.h"

NS_GP_CLIENT_BEGIN

class Init_Client
{

public:
	static int init ();
	static int fini ();
};

NS_GP_CLIENT_END


#endif /* GP_CLIENT_H */
