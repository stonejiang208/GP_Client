// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-03-07 14:11:04 by jiangtao> */

/* @file Game_Data.h
 * $Id: Game_Data.h 2015-03-03 06:18:19 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef GAME_DATA_H
#define GAME_DATA_H

#include "GP_Client/Subject.h"

NS_GP_CLIENT_BEGIN

class Game_Data
	: public Subject
{
public:
	Game_Data (bool need_destroy = true);
	virtual ~Game_Data ();
	virtual int update_data (const char*, size_t);
	void update ();
	bool need_destroy ();
	bool is_dirty () ;
	void make_dirty ();
private:
	bool need_destroy_;
	bool is_dirty_;
};
NS_GP_CLIENT_END


#endif /* GAME_DATA_H */
