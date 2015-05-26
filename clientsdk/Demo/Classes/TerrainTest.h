#ifndef TERRAIN_TESH_H

#include "cocos2d.h"
#include "3d/CCSprite3D.h"
#include "3d/CCTerrain.h"
#include "2d/CCCamera.h"
#include "2d/CCAction.h"
#include "extensions/cocos-ext.h"
#include "Data_Subscribers.h"

#define PLAYER_STATE_LEFT 0 
#define PLAYER_STATE_RIGHT 1
#define PLAYER_STATE_IDLE 2
#define PLAYER_STATE_FORWARD 3
#define PLAYER_STATE_BACKWARD 4

class Player : public cocos2d::Sprite3D
{
public:
    static Player * create(const char * file, cocos2d::Camera*  cam, cocos2d::Terrain* terrain);
    virtual bool isDone() const;
    virtual void update(float dt);

    void turnLeft();
    void turnRight();
    void forward();
    void backward();
    void idle();
    cocos2d::Vec3 _targetPos;
    void updateState();
    float _headingAngle;
    cocos2d::Vec3 _headingAxis;
protected:
    cocos2d::Terrain* _terrain;
    cocos2d::Camera*  _cam;
    int _playerState;
};


class Other : public Player
{
public:
  static Other * create(const char * file, cocos2d::Camera*  cam, cocos2d::Terrain* terrain);
  virtual void update(float dt);
};


class TerrainWalkThru : public cocos2d::Scene
{
public:
    CREATE_FUNC(TerrainWalkThru);
    TerrainWalkThru();
  virtual ~TerrainWalkThru ();
  virtual bool init ();
    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    void onTouchesEnd(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
  
  void create_other(const char* uid,
                     float x, float y, float z);
  void on_move (const char* uid,
                float x,float y, float z,float a,float b);
protected:
    cocos2d::Camera*  _camera;
    cocos2d::Terrain* _terrain;
    Player * _player;
  Move_Msg_Observer*   move_observer_;
};

#endif // !TERRAIN_TESH_H
