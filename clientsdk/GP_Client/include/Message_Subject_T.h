// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-03-03 15:59:35 by jiangtao> */

/* @file Message_Subject_T.h
 * $Id: Message_Subject_T.h 2015-03-03 04:55:47 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef MESSAGE_SUBJECT_T_H
#define MESSAGE_SUBJECT_T_H

#include "Subject.h"
template <typename Native_Type>
struct Msg_Data_T
{
	typedef Native_Type Value_Type;
	int parse_data (const char* data, size_t n) {return 0;}
	Value_Type value_;
};


template <typename Native_Type>
class Message_Subject_T
	: public NS_GP_CLIENT::Subject
{
	typedef NS_GP_CLIENT::Subject Base;
	typedef Msg_Data_T<Native_Type> Msg_Data_Type;
public:
	typedef Native_Type Value_Type;
	void value (const Value_Type& v) { msg_.value_ = v; notify ();}
	const Value_Type& value () const { return msg_.value_; }
	int parse_data (const char* data, size_t n) { return msg_.parse_data (data,n);}
private:
  Msg_Data_Type msg_;
};


#endif /* MESSAGE_SUBJECT_T_H */
