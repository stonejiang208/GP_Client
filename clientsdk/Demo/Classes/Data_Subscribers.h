// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-20 07:48:32 by jiangtao> */

/* @file Data_Subscribers.h
 * $Id: Data_Subscribers.h 2015-05-19 23:48:25 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef DATA_SUBSCRIBERS_H
#define DATA_SUBSCRIBERS_H
#include "GP_Client/Observer.h"
USING_NS_GP_CLIENT;

class TerrainWalkThru;



class Move_Msg_Observer
: public Observer
{
  typedef Observer Base;
  typedef TerrainWalkThru UI;
public:
  Move_Msg_Observer (Subject* s, UI* ui);
  virtual void update (const Subject* s);
private:
  UI* ui_;
};

#endif /* DATA_SUBSCRIBERS_H */
