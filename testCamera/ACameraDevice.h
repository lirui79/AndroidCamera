/*****************************************************/
/*
**   Author: lirui
**   Date: 2019/07/17
**   File: ACameraDevice.h
**   Function:  Interface of ACameraDevice for user
**   History:
**       2019/07/17 create by lirui
**
**   Copy Right: iris corp
**
*/
/*****************************************************/

#ifndef VIRTUAL_INTERFACE_ACAMERA_DEVICE_H
#define VIRTUAL_INTERFACE_ACAMERA_DEVICE_H


#include <android/hardware/ICameraService.h>
#include <android/hardware/camera2/ICameraDeviceUser.h>
#include "ACameraDeviceCallbacks.h"

class ACameraDevice {
public:
    ACameraDevice();

    virtual ~ACameraDevice();

    virtual int disconnect();

    virtual int connect(android::sp<android::hardware::ICameraService> &service, int32_t cameraID, void *gbp);

private:
    android::sp<ACameraDeviceCallbacks>            mCallbacks;
    android::sp<android::hardware::camera2::ICameraDeviceUser> mDevice;
    int32_t                                        mStreamID;
};



#endif  //VIRTUAL_INTERFACE_ACAMERA_DEVICE_H
