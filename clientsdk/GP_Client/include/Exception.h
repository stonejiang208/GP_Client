// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-09 13:58:02 by jiangtao> */

/* @file Exception.h
 * $Id: Exception.h 2014-12-24 01:51:32 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "GP_Client/Namespace.h"

#include <exception>      // std::exception
#include <string>
NS_GP_CLIENT_BEGIN

class Exception
	: public std::exception
{
public:
	Exception (int major, int minor);
	virtual ~Exception ();
	virtual const char* what() const noexcept;
private:
	int major_;
	int minor_;
	std::string what_;
};
NS_GP_CLIENT_END


#endif /* EXCEPTION_H */
