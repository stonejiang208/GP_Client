// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-20 07:48:40 by jiangtao> */

/* @file Data_Subscribers.cpp
 * $Id: Data_Subscribers.cpp 2015-05-19 23:48:39 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "Data_Subscribers.h"
#include "Data_Define.h"

#include "TerrainTest.h"

///---------------
Move_Msg_Observer::Move_Msg_Observer(Subject* s, UI* ui)
: Base (s)
, ui_ (ui)
{
  
}


void Move_Msg_Observer::update(const GP_Client::Subject *s)
{
  if (s == subject_)
  {
    Move_Msg_Data* data = (Move_Msg_Data*) s;
    const Move_Msg_Data::Value_Type& v = data->value ();
    
    ui_->on_move (v.uid_.c_str(),
                  v.x_,v.y_,v.z_,
                  v.a_, v.b_
                  );
    
  }
}


