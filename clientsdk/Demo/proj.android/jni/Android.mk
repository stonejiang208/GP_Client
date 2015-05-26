LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

### step 2
LOCAL_SRC_FILES := hellocpp/main.cpp \
##                   ../../Classes/AppDelegate.cpp \
##                   ../../Classes/HelloWorldScene.cpp
FILE_LIST := $(wildcard $(LOCAL_PATH)/../../Classes/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../

### step 3
## {{ lib
##### step 3.1
LOCAL_C_INCLUDES += $(GP_ROOT)/GP_Client
LOCAL_C_INCLUDES += $(ACE_ROOT)

LOCAL_LDLIBS += -L$(GP_ROOT)/lib
LOCAL_LDLIBS += -L$(ACE_ROOT)/lib

#### step 3.2
LOCAL_LDLIBS +=-lGP_Client
LOCAL_LDLIBS +=-lGP_Application
LOCAL_LDLIBS +=-lGP_World_Factory
LOCAL_LDLIBS +=-lGP_Common
LOCAL_LDLIBS +=-lTAO_CosNaming
LOCAL_LDLIBS +=-lTAO_Utils
LOCAL_LDLIBS +=-lTAO_Svc_Utils
LOCAL_LDLIBS +=-lTAO_Messaging
LOCAL_LDLIBS +=-lTAO_CodecFactory
LOCAL_LDLIBS +=-lTAO_PI
LOCAL_LDLIBS +=-lTAO_BiDirGIOP
LOCAL_LDLIBS +=-lTAO_PortableServer
LOCAL_LDLIBS +=-lTAO_AnyTypeCode
LOCAL_LDLIBS +=-lTAO_Valuetype
LOCAL_LDLIBS +=-lTAO
LOCAL_LDLIBS +=-lACE
## lib}}


# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
