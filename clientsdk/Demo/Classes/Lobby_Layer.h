// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-20 08:52:33 by jiangtao> */

/* @file Lobby_Layer.h
 * $Id: Lobby_Layer.h 2015-05-11 09:24:40 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef LOBBY_LAYER_H
#define LOBBY_LAYER_H
#include "GP_Client/App_Listener.h"
#include "GP_Client/Observer.h"
#include "CSB_Layer.h"
#include "Data_Define.h"  // String_List;

class Lobby_Layer
	: public CSB_Layer
  , public GP_Client::App_Listener
 ,  public Observer
{
	typedef CSB_Layer Base;
	typedef Lobby_Layer Self;
public:
	Lobby_Layer ();
	virtual ~Lobby_Layer ();
	virtual std::string get_csb_filename ();
	virtual void set_callbacks (Root_Node_Type* node);
	CREATE_FUNC (Self);
  virtual void onEnter();
public:
  virtual void on_status (int status);
  virtual void update (const Subject* s);
public:
	void on_btn_enter_game (Ref*);
	void on_btn_quit (Ref*);
  void enter_game ();
private:
  void show_app_list ();
  void add_room (ListView* lv, const char*  room_id);
private:
  ListView*    room_list_view_;
  String_List  room_list_;
};

#endif /* LOBBY_LAYER_H */
