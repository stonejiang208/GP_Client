// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-05 11:43:53 by jiangtao> */

/* @file My_Controller.h
 * $Id: My_Controller.h 2015-05-04 09:56:36 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef MY_CONTROLLER_H
#define MY_CONTROLLER_H

#include "GP_Client/Controller.h"
#include "cocos2d.h"

USING_NS_CC;

class My_Controller
	: public GP_Client::Controller
{
	typedef GP_Client::Controller Base;
public:
	My_Controller ();
	virtual ~My_Controller ();
	virtual int init ();
private:
	void on_event (EventCustom* event);

	void calculate_delta_time();
	float delta_time ();
private:

	EventListenerCustom* event_;
	float delta_time_;
	bool next_delta_time_zero_;
  struct timeval* last_update_time_;

};

#endif /* MY_CONTROLLER_H */
