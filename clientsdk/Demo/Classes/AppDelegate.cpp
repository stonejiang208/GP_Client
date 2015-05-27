#include "AppDelegate.h"

#include "GP_Client/GP_Client.h"
#include "GP_Client/Local_Storage.h"
#include "GP_Client/Local_Settings.h"
#include "GP_Client/World_Factory.h"
#include "Game_Controller.h"
#include "My_User.h"
#include "Welcome_Layer.h"
#include "Status_Bar.h"
#include <vector>
#include <string>

#include "TerrainTest.h"
using namespace std;

USING_NS_CC;
USING_NS_GP_CLIENT;

AppDelegate::AppDelegate() {
  
  const std::string writeable_path = FileUtils::getInstance()->getWritablePath();
  CCLOG ("the writeable path is [%s]",
         writeable_path.c_str());
  
  //const std::string settings_file =
 // FileUtils::getInstance()->fullPathForFilename("settings/config.xml");
//	CCLOG ("setting_file = %s",settings_file.c_str());
  Init_Client::init ();
#if 0
 // Local_Settings* settings = Local_Settings::instance ();
 // int retval = settings->load (settings_file);
  if (retval !=0 )
	{
		CCLOG ("LOAD config ok");
	}
	else
	{
		CCLOG ("LOAD config error");
	}
	#if 1
	std::string t = "vendor_id";
  std::string wf_name = settings->get_string_value(t);

  CCLOG ("wf_name [%s]",wf_name.c_str());
  int port = settings->get_int_value("server_port");
  CCLOG ("port  [%d]",port);

  float temp = settings->get_float_value ("value");
   CCLOG ("temp  [%f]",temp);
#endif
#endif
  
  Local_Storage* storage = Local_Storage::instance();
  storage->set_writeable_path(writeable_path);
  int x = storage->load ();
  CCLOG ("load == %d",x);

//  storage->append_string_to_list("string_list", "name3");
 // storage->append_string_to_list("string_list", "name6");

  storage->save ();
  
  World_Factory* wf = World_Factory::instance ();
  wf->set_app_id("abc");
  wf->set_app_key("mykey");

  wf->create_world<My_User,Game_Controller> ("abc","mykey","192.168.1.2",2809);
  
  
  Game_Controller::instance ()->init ();
}

AppDelegate::~AppDelegate() 
{
  int retval = Game_Controller::instance ()->fini ();
  if (retval != 0)
  {
    CCLOG ("fini error.");
  }
  else
  {
    CCLOG ("fini ok");
  }
  
  World_Factory::destroy();
  Local_Settings::close ();
  Local_Storage::close ();
  Init_Client::fini ();
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    register_all_packages();
		
    Size my_designResolutionSize;
		vector<string> searchPath;

		my_designResolutionSize = Size (1136, 640);
		searchPath.push_back ( "iPhone5");
		glview->setDesignResolutionSize(
		 my_designResolutionSize.width,
		 my_designResolutionSize.height,
		 ResolutionPolicy::SHOW_ALL);

		
    // set searching path
		FileUtils::getInstance()->setSearchPaths(searchPath);
#if 1
    // create a scene. it's an autorelease object
  auto scene = cocos2d::Scene::create();
    scene->addChild(Welcome_Layer::create ());
    scene->addChild(Status_Bar::create (),Status_Bar::kZorder);
#else
  auto scene = TerrainWalkThru::create ();
#endif
    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
