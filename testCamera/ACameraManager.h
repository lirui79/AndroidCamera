/*****************************************************/
/*
**   Author: lirui
**   Date: 2019/07/17
**   File: ACameraManager.h
**   Function:  Interface of ACameraManager for user
**   History:
**       2019/07/17 create by lirui
**
**   Copy Right: iris corp
**
*/
/*****************************************************/

#ifndef VIRTUAL_INTERFACE_ACAMERA_MANAGER_H
#define VIRTUAL_INTERFACE_ACAMERA_MANAGER_H

#include "ICameraManager.h"
#include <android/hardware/ICameraService.h>
#include "ACameraServiceListener.h"
#include "ACameraDevice.h"
#include <map>
#include <memory>
#include <utils/Mutex.h>

class ACameraManager : public ICameraManager {
protected:
    static int ACameraManager_static_default_init(struct ICameraManager* manager, int32_t *numCameras);
    static int ACameraManager_static_default_open(struct ICameraManager* manager, int32_t cameraID, void* gbp);
    static int ACameraManager_static_default_close(struct ICameraManager* manager, int32_t cameraID);
private:
    ACameraManager();

    ACameraManager(const ACameraManager &sc);

    ACameraManager &operator=(const ACameraManager &sc);

public:
    virtual ~ACameraManager();

    static ACameraManager* singleton();

    virtual int init(int32_t &numCameras);
    virtual int open(int32_t cameraID, void* gbp);
    virtual int close(int32_t cameraID);

private:
    android::sp<android::hardware::ICameraService>     mService;
    android::sp<ACameraServiceListener>                mListener;
    std::map<int32_t, std::shared_ptr<ACameraDevice>>  mDevices;
    mutable android::Mutex mLock;
};


#endif  //VIRTUAL_INTERFACE_ACAMERA_MANAGER_H
