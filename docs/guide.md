# Game Cloud 使用指南
## SDK简介

Game Cloud 帮助开发人员快速构建多人联网实时互动的游戏产品。
Game Cloud 由SDK和一组应用服务组成。 开发人员可以利用这个SDK
开发可以访问应用服务的产品来快速构建具有联网功能的游戏产品。

SDK又分为户端的SDK(简记为"GP_Client")和服务端SDK ("GP_Server")。
本文通过示例，介绍SDK的具体用法。

## 获取 SDK

### SDK的组成
~~~~~~
GP_Clint

 include
 ios
	 lib
 ios-simulator
    lib

 android
	
 os-x
 win32
 linux
GP_Server
~~~~~~
## 使用步骤


### iOS 接入

#### 导入库

在XCode中，选PROJECT的TARGETS选中"Demo-mobile"，然后在Build Settings中，找到
"Search Paths",在Header Search中，加入 include的路径。

同样，在"Library Search Paths"中，加入 lib的路径。
如下图:

// todo:｛增加屏幕图示｝

#### 代码集成概述

##### 基本步骤


1. 设置本地存储的可写路径

2. 初始化SDK

3. 实现User类 （My_User.{h,cpp})，最好实现为单体
（可以不重载任何函数）


4. 实现Controller类 (My_Controller.{h,cpp}) 最好实现为单体
   
5. 定义交互的数据类型

6. 实现数据的显示

5. 实现数据的发布和订阅


#####  代码示例
1. 包含SDK头文件

SDK内部实现做到了跨平台的工作，为不同平台的提供了一致的文件，这减少开发人员对多同平支持的工作量。

//todo

2. 设置本地存储的可写路径


3. 创建用户和控制器

4. 初始化控制器


#### 代码集成详解


1. 初始化Game_Cloud

	World_Factory作为一个工厂类，除了创建用户和控制器之外，它还提供了一个初始化的功能：

2. 订阅应用的状态

	控制器初始化后，SDK内部会向服务器发起会话请求，如果成功，应用端会与服务器建立连接，之后，服务器与应用双方都能够进行通讯，定点与传统的客户端发起请求，服务端作一个简单应答不同。

	示例中的

	Welcome_Layer

	从 "GP_Client::App_Listener"
	派生，同时重载
``` cpp
void on_status (int status);
```

	根据参数status，即可获知当前的连接状态.示例中，通过 另一个函数
``` cpp
void update_ui_status (int status)
```
	控制界面UI元素在不同状态下的显示外观。


3. 初始化用户或初始化游客

4. 进入游戏大厅

5. 获取房间列表，进入游戏

6. 安全退出





