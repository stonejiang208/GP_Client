// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-05 11:47:29 by jiangtao> */

/* @file My_Controller.cpp
 * $Id: My_Controller.cpp 2015-05-04 09:56:42 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "My_Controller.h"

My_Controller::My_Controller ()
	: next_delta_time_zero_ (true)
{
	last_update_time_ = new struct timeval;
}

My_Controller::~My_Controller ()
{
	auto dispatcher = Director::getInstance ()->getEventDispatcher ();
	dispatcher->removeEventListener (event_);
	CC_SAFE_DELETE (last_update_time_);
}

int My_Controller::init ()
{
	if (Base::init () == 0)
	{
		auto dispatcher = Director::getInstance ()->getEventDispatcher ();
		event_ = dispatcher->addCustomEventListener (
			Director::EVENT_AFTER_VISIT,
			std::bind (&My_Controller::on_event, this, std::placeholders::_1));
		return 0;
	}

	return -1;
}

void My_Controller::on_event(EventCustom * event)
{
	calculate_delta_time ();
  if(delta_time_ < 0.000500)
  {
    return;
  }

	update (delta_time_);
}


void My_Controller::calculate_delta_time ()
{
	 struct timeval now;

    if (gettimeofday(&now, nullptr) != 0)
    {
        CCLOG("error in gettimeofday");
        delta_time_ = 0;
        return;
    }

    // new delta time. Re-fixed issue #1277
    if (next_delta_time_zero_)
    {
        delta_time_ = 0;
        next_delta_time_zero_ = false;
    }
    else
    {
        delta_time_ =
					(now.tv_sec - last_update_time_->tv_sec) +
					(now.tv_usec - last_update_time_->tv_usec) / 1000000.0f;
        delta_time_ = MAX(0, delta_time_);
    }

#if COCOS2D_DEBUG
    // If we are debugging our code, prevent big delta time
    if (delta_time_ > 0.2f)
    {
        delta_time_ = 1 / 60.0f;
    }
#endif

    *last_update_time_ = now;
}
float My_Controller::delta_time()
{
	return delta_time_;
}



