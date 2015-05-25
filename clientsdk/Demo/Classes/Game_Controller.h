// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-05 12:36:22 by jiangtao> */

/* @file Game_Controller.h
 * $Id: Game_Controller.h 2015-05-05 04:34:24 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "My_Controller.h"
#include "json/document.h"

class Game_Controller
	: public My_Controller
{
	typedef Game_Controller Self;
	typedef My_Controller Base;

public:
	Game_Controller ();
	virtual ~Game_Controller ();
  int init ();
  int init_net_msg ();
  int init_game_data ();
  
public:
  int  parse_data (const char* uid,
                   const rapidjson::Document& d);
  
	static Game_Controller* instance ();
private:
	static Game_Controller* instance_;
};

#endif /* GAME_CONTROLLER_H */
