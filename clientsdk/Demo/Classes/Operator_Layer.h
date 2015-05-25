// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-21 22:06:52 by jiangtao> */

/* @file Operator_Layer.h
 * $Id: Operator_Layer.h 2015-05-21 14:04:23 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef OPERATOR_LAYER_H
#define OPERATOR_LAYER_H

#include "CSB_Layer.h"

class Operator_Layer
	: public CSB_Layer
{
	typedef CSB_Layer Base;
	typedef Operator_Layer Self;
public:
	virtual std::string get_csb_filename ();
	virtual void set_callbacks (Root_Node_Type* node);
	CREATE_FUNC (Self);
public:
	void on_app_exit (Ref*);
  void on_lobby (Ref*);
};

#endif /* OPERATOR_LAYER_H */
