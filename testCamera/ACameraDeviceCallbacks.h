/*****************************************************/
/*
**   Author: lirui
**   Date: 2019/07/17
**   File: ACameraDeviceCallbacks.h
**   Function:  Interface of ACameraDeviceCallbacks for user
**   History:
**       2019/07/17 create by lirui
**
**   Copy Right: iris corp
**
*/
/*****************************************************/

#ifndef VIRTUAL_INTERFACE_ACAMERA_DEVICE_CALLBACKS_H
#define VIRTUAL_INTERFACE_ACAMERA_DEVICE_CALLBACKS_H

#include <vector>
#include <utils/Condition.h>
#include <utils/Mutex.h>
#include <android/hardware/camera2/ICameraDeviceCallbacks.h>
#include <android/hardware/camera2/BnCameraDeviceCallbacks.h>

class ACameraDeviceCallbacks : public ::android::hardware::camera2::BnCameraDeviceCallbacks {
public:
    ACameraDeviceCallbacks();

    virtual ~ACameraDeviceCallbacks();

    virtual android::binder::Status onDeviceError(int errorCode, const android::CaptureResultExtras& resultExtras);

    virtual android::binder::Status onDeviceIdle();

    virtual android::binder::Status onCaptureStarted(const android::CaptureResultExtras& resultExtras, int64_t timestamp) ;

    virtual android::binder::Status onResultReceived(const android::CameraMetadata& metadata, const android::CaptureResultExtras& resultExtras);

    virtual android::binder::Status onPrepared(int streamId);

    virtual android::binder::Status onRepeatingRequestError(int64_t lastFrameNumber, int32_t stoppedSequenceId);

    virtual android::binder::Status onRequestQueueEmpty();
};

#endif  //VIRTUAL_INTERFACE_ACAMERA_DEVICE_CALLBACKS_H
