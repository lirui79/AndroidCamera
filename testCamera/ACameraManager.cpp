#include "ACameraManager.h"


int ACameraManager::ACameraManager_static_default_init(struct ICameraManager* manager, int32_t *numCameras) {
    ACameraManager* aManager = (ACameraManager*) manager;
    return aManager->init(numCameras[0]);
}

int ACameraManager::ACameraManager_static_default_open(struct ICameraManager* manager, int32_t cameraID, void* gbp) {
    ACameraManager* aManager = (ACameraManager*) manager;
    return aManager->open(cameraID, gbp);
}

int ACameraManager::ACameraManager_static_default_close(struct ICameraManager* manager, int32_t cameraID) {
    ACameraManager* aManager = (ACameraManager*) manager;
    return aManager->close(cameraID);
}

ACameraManager::ACameraManager() {
    ICameraManager::init = ACameraManager_static_default_init;
    ICameraManager::open = ACameraManager_static_default_open;
    ICameraManager::close = ACameraManager_static_default_close;
}

ACameraManager::~ACameraManager() {
}

ACameraManager* ACameraManager::singleton() {
    static android::Mutex mutex;
    static ACameraManager* singleton = NULL;
    if (singleton != NULL) return singleton;
    android::Mutex::Autolock l(mutex);;
    if (singleton == NULL)
        singleton = new ACameraManager();
    return singleton;
}

int ACameraManager::init(int32_t &numCameras) {
    android::Mutex::Autolock l(mLock);
    if (mService != NULL)
        return 1;
    android::sp<android::IServiceManager> sm = android::defaultServiceManager();
    mService = android::interface_cast<android::hardware::ICameraService>(sm->getService(android::String16("media.camera")));
    if (mService == NULL)
        return -1;

    android::binder::Status status;
    mListener = new ACameraServiceListener();
    std::vector<android::hardware::CameraStatus> statuses;
    status = mService->addListener(mListener, &statuses);
    if (!status.isOk())
        return status.exceptionCode();
    status = mService->getNumberOfCameras(android::hardware::ICameraService::CAMERA_TYPE_BACKWARD_COMPATIBLE, &numCameras);
    if (!status.isOk())
        return status.exceptionCode();
    return 0;
}

int ACameraManager::open(int32_t cameraID, void* gbp) {
    android::Mutex::Autolock l(mLock);
    if (mService == NULL)
        return -1;

    std::map<int32_t, std::shared_ptr<ACameraDevice>>::iterator it = mDevices.find(cameraID);
    if (it != mDevices.end())
         return 1;
    std::shared_ptr<ACameraDevice> dev(new ACameraDevice());
    if (dev->connect(mService, cameraID, gbp) < 0)
       return -2;
    mDevices[cameraID] = dev;
    return 0;
}

int ACameraManager::close(int32_t cameraID) {
    android::Mutex::Autolock l(mLock);
    if (mService == NULL)
        return -1;

    std::map<int32_t, std::shared_ptr<ACameraDevice>>::iterator it = mDevices.find(cameraID);
    if (it == mDevices.end())
         return 1;
    std::shared_ptr<ACameraDevice> dev = it->second;
    dev->disconnect();
    mDevices.erase(it);
    return 0;
}



#if defined(__cplusplus)
extern "C" {
#endif


__attribute__((visibility("default"))) struct ICameraManager* getICameraManager(){
    return (struct ICameraManager*) ACameraManager::singleton();
}


#if defined(__cplusplus)
}
#endif
