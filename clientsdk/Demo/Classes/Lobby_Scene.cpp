// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-11 17:33:28 by jiangtao> */

/* @file Lobby_Scene.cpp
 * $Id: Lobby_Scene.cpp 2015-05-11 09:24:23 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "Lobby_Scene.h"
#include "Lobby_Layer.h"
#include "Status_Bar.h"

Lobby_Scene::Lobby_Scene ()
{
}


Lobby_Scene::~Lobby_Scene ()
{
}

bool Lobby_Scene::init ()
{
	if (! Base::init ())
	{
		return false;
	}

	this->addChild (Lobby_Layer::create ());
  this->addChild (Status_Bar::create (),Status_Bar::kZorder);
	return true;
}


