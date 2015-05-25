// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-11 17:27:22 by jiangtao> */

/* @file Lobby_Scene.h
 * $Id: Lobby_Scene.h 2015-05-11 09:24:17 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef LOBBY_SCENE_H
#define LOBBY_SCENE_H
#include "cocos2d.h"

USING_NS_CC;

class Lobby_Scene
	: public Scene
{
	typedef Lobby_Scene Self;
	typedef Scene Base;
public:
	Lobby_Scene ();
	virtual ~Lobby_Scene ();
	virtual bool init ();
	CREATE_FUNC (Lobby_Scene);
};


#endif /* LOBBY_SCENE_H */
