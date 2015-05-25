// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-10 15:35:17 by jiangtao> */

/* @file Status_Bar.h
 * $Id: Status_Bar.h 2015-05-10 07:25:28 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include "CSB_Layer.h"
#include "GP_Client/App_Listener.h"
class Status_Bar
	: public CSB_Layer
  , public GP_Client::App_Listener
{
	typedef Status_Bar Self;
	typedef CSB_Layer Base;
public:
	enum
	{
		kZorder = 100,
	};
public:
	Status_Bar ();
	virtual ~Status_Bar ();

	virtual std::string get_csb_filename ();
	virtual void set_callbacks (Root_Node_Type* node);
	CREATE_FUNC (Self);
  virtual void on_status (int status);
  
  virtual void on_local_msg (int status,
                             int error_code,
                             const char* msg);

private:
	Text*           status_text_;
 
};

#endif /* STATUS_BAR_H */
