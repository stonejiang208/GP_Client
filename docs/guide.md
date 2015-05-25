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

执行

~~~~~~~~~~~
#./update.sh
~~~~~~~~~~~


从GP_Client.tar.bz2解压得到库文件。


#### 代码集成

1. 实现User类 （My_User.{h,cpp})，最好实现为单体
（可以不重载任何函数）

2. 实现Controller类 (My_Controller.{h,cpp}) 最好实现为单体
   
3. 定义交互的数据类型

4. 实现数据的显示

5. 实现数据的发布和订阅




