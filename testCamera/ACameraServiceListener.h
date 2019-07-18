/*****************************************************/
/*
**   Author: lirui
**   Date: 2019/07/17
**   File: ACameraServiceListener.h
**   Function:  Interface of ACameraServiceListener for user
**   History:
**       2019/07/17 create by lirui
**
**   Copy Right: iris corp
**
*/
/*****************************************************/
#ifndef VIRTUAL_INTERFACE_ACAMERA_SERVICE_LISTENER_H
#define VIRTUAL_INTERFACE_ACAMERA_SERVICE_LISTENER_H

#include <map>
#include <string>
#include <utils/String16.h>
#include <utils/Condition.h>
#include <utils/Mutex.h>
#include <android/hardware/BnCameraServiceListener.h>


class ACameraServiceListener : public android::hardware::BnCameraServiceListener {
public:
    virtual ~ACameraServiceListener();

    virtual android::binder::Status onStatusChanged(int32_t status, const android::String16& cameraId);

    virtual android::binder::Status onTorchStatusChanged(int32_t status, const android::String16& cameraId);
/*
    bool waitForNumCameras(size_t num) const;

    bool waitForTorchState(int32_t status, int32_t cameraId) const;

    int32_t getTorchStatus(int32_t cameraId) const ;

    int32_t getStatus(const android::String16& cameraId) const ;

private:
    std::map<android::String16, int32_t> mCameraTorchStatuses;
    std::map<android::String16, int32_t> mCameraStatuses;
    mutable android::Mutex mLock;
    mutable android::Condition mCondition;
    mutable android::Condition mTorchCondition;*/
};


#endif  //VIRTUAL_INTERFACE_ACAMERA_SERVICE_LISTENER_H
