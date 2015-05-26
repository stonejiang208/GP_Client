// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-26 15:53:59 by android> */

/* @file Data_Define.h
 * $Id: Data_Define.h 2015-05-07 06:18:43 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef DATA_DEFINE_H
#define DATA_DEFINE_H

#include "GP_Client/Game_Data_T.h"
#include <string>
#include <list>
#include <stddef.h> //size_t
typedef std::list <std::string> String_List;
typedef std::list<int> Int_List;

USING_NS_GP_CLIENT;

typedef Game_Data_T<String_List> String_List_Data;

enum
{
	kData_Base = 0x00001000,
	kChat_Data,
  kApp_List,
  kMove_Msg,
};


class Move_Msg
{
public:
  Move_Msg (float x = 0,
            float y = 0,
            float z = 0,
            float a = 0,
            float b = 0,
            const char* uid = "")
  : x_ (x)
  , y_ (y)
  , z_ (z)
  , a_ (a)
  , b_ (b)
  , uid_ (uid)
  {
    
  }
  float x_;
  float y_;
  float z_;
  float a_;
  float b_;
  std::string uid_;
};

typedef Game_Data_T<Move_Msg> Move_Msg_Data;

#endif /* DATA_DEFINE_H */
