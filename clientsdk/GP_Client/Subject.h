// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-09 13:44:45 by jiangtao> */

/* @file Subject.h
 * $Id: Subject.h 2015-02-27 14:02:41 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>
#include "Namespace.h"

NS_GP_CLIENT_BEGIN
class Observer;

class Subject
{
public:
	Subject ();
	virtual ~Subject ();
public:
	virtual int update_data (const char* data, size_t n) = 0;
	void notify ();
	void attach (Observer*);
	void detach (Observer*);
private:
	std::list <Observer*> observers_;
};
NS_GP_CLIENT_END

#endif /* SUBJECT_H */
