// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-12 09:24:25 by jiangtao> */

/* @file Observer.h
 * $Id: Observer.h 2015-01-21 23:50:58 stone 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef OBSERVER_H
#define OBSERVER_H

#include "GP_Client/Subject.h"

NS_GP_CLIENT_BEGIN

class Observer
{
public:
	Observer (Subject* s);
	Observer ();
	void subject (Subject* s);
	virtual ~Observer ();
	virtual void update (const Subject* s) = 0;
protected:
	Subject* subject_;
};
NS_GP_CLIENT_END

#endif /* OBSERVER_H */
