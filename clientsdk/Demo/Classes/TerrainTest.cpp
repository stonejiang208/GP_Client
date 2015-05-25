#include "TerrainTest.h"
#include "My_User.h"
#include  "Game_Controller.h"
#include "GP_Client/Data_Manager.h"
#include "Data_Define.h"

USING_NS_CC;


Vec3 camera_offset(0, 45, 60);
#define PLAYER_HEIGHT 0



TerrainWalkThru::TerrainWalkThru()
: move_observer_(nullptr)
{
  
}
TerrainWalkThru::~TerrainWalkThru()
{
  CC_SAFE_DELETE(move_observer_);
}
bool TerrainWalkThru::init ()
{
  if (!cocos2d::Scene::init())
  {
    return false;
  }
  auto listener = EventListenerTouchAllAtOnce::create();
  listener->onTouchesBegan = CC_CALLBACK_2(TerrainWalkThru::onTouchesBegan, this);
  listener->onTouchesEnded = CC_CALLBACK_2(TerrainWalkThru::onTouchesEnd, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
  
  Size visibleSize = Director::getInstance()->getVisibleSize();
  
  //use custom camera
  _camera = Camera::createPerspective(60,visibleSize.width/visibleSize.height,0.1,200);
  _camera->setCameraFlag(CameraFlag::USER1);
  addChild(_camera);
  
  Terrain::DetailMap r("TerrainTest/dirt.jpg"),g("TerrainTest/Grass2.jpg",10),b("TerrainTest/road.jpg"),a("TerrainTest/GreenSkin.jpg",20);
  
  Terrain::TerrainData data("TerrainTest/heightmap16.jpg","TerrainTest/alphamap.png",r,g,b,a,Size(32,32),40.0f,2);
  _terrain = Terrain::create(data,Terrain::CrackFixedType::SKIRT);
  _terrain->setMaxDetailMapAmount(4);
  _terrain->setCameraMask(2);
  _terrain->setDrawWire(false);
  
  _terrain->setSkirtHeightRatio(3);
  _terrain->setLODDistance(64,128,192);
  _player = Player::create("Sprite3DTest/girl.c3b",_camera,_terrain);
  const char* uid = My_User::instance()->get_uid();
  _player->setName(uid);
  _player->setCameraMask(2);
  _player->setScale(0.08);
  _player->setPositionY(_terrain->getHeight(_player->getPositionX(),_player->getPositionZ())+PLAYER_HEIGHT);
 
  // add Particle3D for test blend
  auto rootps = PUParticleSystem3D::create("Particle3D/scripts/mp_torch.pu");
  rootps->setCameraMask((unsigned short)CameraFlag::USER1);
  rootps->setScale(30.0f);
  rootps->startParticleSystem();
  _player->addChild(rootps);
#if 0 
  // add BillBoard for test blend
  auto billboard = BillBoard::create("Images/btn-play-normal.png");
  billboard->setPosition3D(Vec3(0,180,0));
  billboard->setCameraMask((unsigned short)CameraFlag::USER1);
  _player->addChild(billboard);
#endif
  auto animation = Animation3D::create("Sprite3DTest/girl.c3b","Take 001");
  if (animation)
  {
    auto animate = Animate3D::create(animation);
    _player->runAction(RepeatForever::create(animate));
  }
  
  _camera->setPosition3D(_player->getPosition3D()+camera_offset);
  _camera->setRotation3D(Vec3(-45,0,0));
  
  addChild(_player);
  addChild(_terrain);
  
  GP_Client::Data_Manager* dm = Game_Controller::instance ()->data_manager();
  GP_Client::Game_Data* sub = dm->find_data_by_id(kMove_Msg);
  
  move_observer_ = new Move_Msg_Observer (sub,this);

  return true;
}
void TerrainWalkThru::onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
}


void TerrainWalkThru::onTouchesEnd(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
    auto touch = touches[0];
    auto location = touch->getLocationInView();
    if(_camera)
    {
        if(_player)
        {
            Vec3 nearP(location.x, location.y, 0.0f), farP(location.x, location.y, 1.0f);

            auto size = Director::getInstance()->getWinSize();
            _camera->unproject(size, &nearP, &nearP);
            _camera->unproject(size, &farP, &farP);
            Vec3 dir = farP - nearP;
            dir.normalize();
            Vec3 rayStep = 15*dir;
            Vec3 rayPos =  nearP;
            Vec3 rayStartPosition = nearP;
            Vec3 lastRayPosition =rayPos;
            rayPos += rayStep; 
            // Linear search - Loop until find a point inside and outside the terrain Vector3 
            float height = _terrain->getHeight(rayPos.x,rayPos.z); 

            while (rayPos.y > height)
            {
                lastRayPosition = rayPos; 
                rayPos += rayStep; 
                height = _terrain->getHeight(rayPos.x,rayPos.z); 
            } 

            Vec3 startPosition = lastRayPosition;
            Vec3 endPosition = rayPos;

            for (int i= 0; i< 32; i++) 
            { 
                // Binary search pass 
                Vec3 middlePoint = (startPosition + endPosition) * 0.5f;
                if (middlePoint.y < height) 
                    endPosition = middlePoint; 
                else 
                    startPosition = middlePoint;
            } 
            Vec3 collisionPoint = (startPosition + endPosition) * 0.5f; 
            dir = collisionPoint - _player->getPosition3D();
            dir.y = 0;
            dir.normalize();
          float angle = -1*acos(dir.dot(Vec3(0,0,-1)));;
         //   _player->_headingAngle =  -1*acos(dir.dot(Vec3(0,0,-1)));
          
          CCLOG ("target axis 1= (%f,%f,%f)",
                 _player->_headingAxis.x,
                 _player->_headingAxis.y,
                 _player->_headingAxis.z);
          
          
          dir.cross(dir,Vec3(0,0,-1),&_player->_headingAxis);
          
          CCLOG ("target axis 2 = (%f,%f,%f)",
                 _player->_headingAxis.x,
                 _player->_headingAxis.y,
                 _player->_headingAxis.z);
          
#if 1
          My_User::instance ()->move_to( collisionPoint.x,
                                        collisionPoint.y,
                                        collisionPoint.z,
                                        angle,
                                        _player->_headingAxis.y);
#endif
      //    _player->_targetPos=collisionPoint;
          
          CCLOG ("target pos = (%f,%f,%f)",
                 collisionPoint.x,
                 collisionPoint.y,
                 collisionPoint.z);
          
        //    _player->forward();
        }
    }
}


bool Player::isDone() const
{
    return false;
}


void Player::update(float dt)
{
    auto player = (Sprite3D *)this;
  float x,y,z;
  x = player->getPositionX();
  y = player->getPositionY();
  z = player->getPositionZ ();
  
 // CCLOG ("player (%f,%f,%f)",x,y,z);
    switch (_playerState)
    {
    case PLAYER_STATE_IDLE:
        break;
    case PLAYER_STATE_FORWARD:
        {
            Vec3 curPos=  player->getPosition3D();
            Vec3 newFaceDir = _targetPos - curPos;
            newFaceDir.y = 0.0f;
            newFaceDir.normalize();
            Vec3 offset = newFaceDir * 25.0f * dt;
            curPos+=offset;
            player->setPosition3D(curPos);
        }
        break;
    case PLAYER_STATE_BACKWARD:
        {
            Vec3 forward_vec;
            player->getNodeToWorldTransform().getForwardVector(&forward_vec);
            forward_vec.normalize();
            player->setPosition3D(player->getPosition3D()-forward_vec*15*dt);
        }
        break;
    case PLAYER_STATE_LEFT:
        {
            player->setRotation3D(player->getRotation3D()+Vec3(0,25*dt,0));
        }
        break;
    case PLAYER_STATE_RIGHT:
        {
            player->setRotation3D(player->getRotation3D()+Vec3(0,-25*dt,0));
        }
        break;
    default:
        break;
    }
    Vec3 Normal;
    float player_h = _terrain->getHeight(player->getPositionX(),player->getPositionZ(),&Normal);

    player->setPositionY(player_h+PLAYER_HEIGHT);
    Quaternion q2;
    q2.createFromAxisAngle(Vec3(0,1,0),-M_PI,&q2);
 
    Quaternion headingQ;
    headingQ.createFromAxisAngle(_headingAxis,_headingAngle,&headingQ);
    player->setRotationQuat(headingQ*q2);
    auto vec_offset =Vec4(camera_offset.x,camera_offset.y,camera_offset.z,1);
    vec_offset = player->getNodeToWorldTransform()*vec_offset;
     _cam->setPosition3D(player->getPosition3D() + camera_offset);
    updateState();
}

void Player::turnLeft()
{
    _playerState = PLAYER_STATE_LEFT;
}

void Player::turnRight()
{
    _playerState = PLAYER_STATE_RIGHT;
}

void Player::idle()
{
    _playerState = PLAYER_STATE_IDLE;
}


void Player::forward()
{
    _playerState = PLAYER_STATE_FORWARD;
}

void Player::backward()
{
    _playerState = PLAYER_STATE_BACKWARD;
}

void Player::updateState()
{
    auto player = (Sprite3D * )this;
    switch (_playerState)
    {
    case PLAYER_STATE_FORWARD:
        {
            Vec2 player_pos =Vec2(player->getPositionX(),player->getPositionZ());
            Vec2 targetPos = Vec2(_targetPos.x,_targetPos.z);
            auto dist = player_pos.distance(targetPos);
            if(dist<1)
            {
                _playerState = PLAYER_STATE_IDLE;
            }
        }
        break;
    default:
        break;
    }
}

Player * Player::create(const char * file,Camera * cam,Terrain * terrain)
{
    //
    auto sprite = new (std::nothrow) Player();
    if (sprite && sprite->initWithFile(file))
    {
        sprite->_headingAngle = 0;
        sprite->_playerState = PLAYER_STATE_IDLE;
        sprite->_cam = cam;
        sprite->_terrain = terrain;
        sprite->autorelease();
        sprite->scheduleUpdate();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

void TerrainWalkThru::create_other(const char* uid,
                                    float x, float y, float z)
{
  auto p  = Other::create("Sprite3DTest/girl.c3b",_camera,_terrain);
  p->setCameraMask(2);
  p->setScale(0.08);
  p->setPosition3D(Vec3(0,0,0));
  p->setPositionY(_terrain->getHeight(p->getPositionX(),p->getPositionZ())+PLAYER_HEIGHT);
  
  auto animation = Animation3D::create("Sprite3DTest/girl.c3b","Take 001");
  if (animation)
  {
    auto animate = Animate3D::create(animation);
    p->runAction(RepeatForever::create(animate));
  }

  
  this->addChild(p);
  p->setName (uid);
  
  Vec3 collisionPoint (x,y,z);
  Vec3 dir;
  dir = collisionPoint - p->getPosition3D();
  dir.y = 0;
  dir.normalize();
  //float angle = -1*acos(dir.dot(Vec3(0,0,-1)));;
  p->_headingAngle =  -1*acos(dir.dot(Vec3(0,0,-1)));
  dir.cross(dir,Vec3(0,0,-1),&p->_headingAxis);
  

  
  p->_targetPos = collisionPoint;
  p->forward();
}

void TerrainWalkThru::on_move(const char *uid,
                              float x, float y, float z,
                              float a,float b)
{
  //get user by id
  Player* p = getChildByName<Player*> (uid);
  if (p)
  {
    Vec3 collisionPoint (x,y,z);
  
    p->_headingAngle = a;
    p->_headingAxis.y = b;
    p->_targetPos = collisionPoint;
    p->forward();
  }
  else
  {
    // create other user
    create_other(uid,x,y,z);
  }
}

Other * Other::create(const char * file,Camera * cam,Terrain * terrain)
{
  //
  auto sprite = new (std::nothrow) Other();
  if (sprite && sprite->initWithFile(file))
  {
    sprite->_headingAngle = 0;
    sprite->_playerState = PLAYER_STATE_IDLE;
    sprite->_cam = cam;
    sprite->_terrain = terrain;
    sprite->autorelease();
    sprite->scheduleUpdate();
    return sprite;
  }
  CC_SAFE_DELETE(sprite);
  return nullptr;
}

void Other::update(float dt)
{
  auto player = (Sprite3D *)this;
  float x,y,z;
  x = player->getPositionX();
  y = player->getPositionY();
  z = player->getPositionZ ();
  
  // CCLOG ("player (%f,%f,%f)",x,y,z);
  switch (_playerState)
  {
    case PLAYER_STATE_IDLE:
      break;
    case PLAYER_STATE_FORWARD:
    {
      Vec3 curPos=  player->getPosition3D();
      Vec3 newFaceDir = _targetPos - curPos;
      newFaceDir.y = 0.0f;
      newFaceDir.normalize();
      Vec3 offset = newFaceDir * 25.0f * dt;
      curPos+=offset;
      player->setPosition3D(curPos);
    }
      break;
    case PLAYER_STATE_BACKWARD:
    {
      Vec3 forward_vec;
      player->getNodeToWorldTransform().getForwardVector(&forward_vec);
      forward_vec.normalize();
      player->setPosition3D(player->getPosition3D()-forward_vec*15*dt);
    }
      break;
    case PLAYER_STATE_LEFT:
    {
      player->setRotation3D(player->getRotation3D()+Vec3(0,25*dt,0));
    }
      break;
    case PLAYER_STATE_RIGHT:
    {
      player->setRotation3D(player->getRotation3D()+Vec3(0,-25*dt,0));
    }
      break;
    default:
      break;
  }
  Vec3 Normal;
  float player_h = _terrain->getHeight(player->getPositionX(),player->getPositionZ(),&Normal);
  
  player->setPositionY(player_h+PLAYER_HEIGHT);
  Quaternion q2;
  q2.createFromAxisAngle(Vec3(0,1,0),-M_PI,&q2);
  
  Quaternion headingQ;
  headingQ.createFromAxisAngle(_headingAxis,_headingAngle,&headingQ);
  player->setRotationQuat(headingQ*q2);
 // auto vec_offset =Vec4(camera_offset.x,camera_offset.y,camera_offset.z,1);
  //vec_offset = player->getNodeToWorldTransform()*vec_offset;
  //_cam->setPosition3D(player->getPosition3D() + camera_offset);
  updateState();
}
