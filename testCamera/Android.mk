
LOCAL_PATH:=$(call my-dir)

include $(CLEAR_VARS)


ifeq ($(PLATFORM_VERSION), 6.0.1)
	LOCAL_CPPFLAGS += -DPLATFORM_VERSION_6
endif

ifeq ($(PLATFORM_VERSION), 6.0)
	LOCAL_CPPFLAGS += -DPLATFORM_VERSION_6
endif

ifeq ($(PLATFORM_VERSION), 7.1.1)
	LOCAL_CPPFLAGS += -DPLATFORM_VERSION_7
endif

ifeq ($(PLATFORM_VERSION), 7.1.2)
	LOCAL_CPPFLAGS += -DPLATFORM_VERSION_7
endif

ifeq ($(PLATFORM_VERSION), 8.1.0)
	LOCAL_CPPFLAGS += -DPLATFORM_VERSION_8
endif

ifeq ($(PLATFORM_VERSION), 9)
	LOCAL_CPPFLAGS += -DPLATFORM_VERSION_9
endif

LOCAL_SRC_FILES := \
                   ACameraDevice.cpp \
				   ACameraDeviceCallbacks.cpp \
				   ACameraServiceListener.cpp \
				   ACameraManager.cpp \


LOCAL_SHARED_LIBRARIES := \
		libutils \
		libcutils \
		libcamera_metadata \
		libcamera_client \
		libgui \
		libsync \
		libui \
		libdl \
		libbinder


LOCAL_C_INCLUDES += \
	system/media/private/camera/include \
	system/media/camera/tests \
	frameworks/av/services/camera/libcameraservice \


LOCAL_CFLAGS += -DLOG_TAG=\"MediaEncode\" -g

LOCAL_MODULE := libCameraManager

include $(BUILD_SHARED_LIBRARY)



include $(CLEAR_VARS)


ifeq ($(PLATFORM_VERSION), 6.0.1)
	LOCAL_CPPFLAGS += -DPLATFORM_VERSION_6
endif

ifeq ($(PLATFORM_VERSION), 6.0)
	LOCAL_CPPFLAGS += -DPLATFORM_VERSION_6
endif

ifeq ($(PLATFORM_VERSION), 7.1.1)
	LOCAL_CPPFLAGS += -DPLATFORM_VERSION_7
endif

ifeq ($(PLATFORM_VERSION), 7.1.2)
	LOCAL_CPPFLAGS += -DPLATFORM_VERSION_7
endif

ifeq ($(PLATFORM_VERSION), 8.1.0)
	LOCAL_CPPFLAGS += -DPLATFORM_VERSION_8
endif


ifeq ($(PLATFORM_VERSION), 9)
	LOCAL_CPPFLAGS += -DPLATFORM_VERSION_9
endif

LOCAL_SRC_FILES := main.cpp \

LOCAL_C_INCLUDES := \
                     ./

LOCAL_SHARED_LIBRARIES := \
    libutils \
    libbinder \
    libui \
    libgui \
	libCameraManager


#LOCAL_ARM_MODE := arm
#LOCAL_MODULE_TARGET_ARCHS := arm
#LOCAL_MULTILIB := 32

LOCAL_MODULE := testCameraManager

LOCAL_CFLAGS += -Wall -Wextra -Werror

include $(BUILD_EXECUTABLE)
