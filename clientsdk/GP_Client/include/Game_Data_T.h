// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-18 16:05:37 by jiangtao> */

/* @file Game_Data_T.h
 * $Id: Game_Data_T.h 2015-03-03 07:44:52 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef GAME_DATA_T_H
#define GAME_DATA_T_H

#include "GP_Client/Game_Data.h"
#include <string>

template <typename Native_Type>
class Game_Data_T
	: public NS_GP_CLIENT::Game_Data
{
	typedef NS_GP_CLIENT::Game_Data Base;
public:
	typedef Native_Type Value_Type;
	Game_Data_T (bool need_destroy = true): Base (need_destroy) {};
	void value (const Value_Type& v) { value_ = v;notify();}
	const Value_Type& value () const { return value_;}
private:
	Value_Type  value_;
};

//typedef Game_Data_T<int> Int_Data;

class Int_Data
: public Game_Data_T<int>
{
public:
  Int_Data ()
  {
    value (0);
  }
};

//typedef Game_Data_T<std::string> String_Data;
#if 1
class String_Data
: public Game_Data_T<std::string>
{
public:
  String_Data()
  {
    value ("");
  }
};
#endif




#endif /* GAME_DATA_T_H */
