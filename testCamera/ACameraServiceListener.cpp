#include "ACameraServiceListener.h"

#define SETUP_TIMEOUT 2000000000 // ns

ACameraServiceListener::~ACameraServiceListener() {
}

android::binder::Status ACameraServiceListener::onStatusChanged(int32_t status, const android::String16& cameraId) {
    (void) status;
    (void) cameraId;
//    printf("onStatusChanged status %d, cameraId %s\n", status, android::String8(cameraId).c_str());
//    android::Mutex::Autolock l(mLock);
//    mCameraStatuses[cameraId] = status;
//    mCondition.broadcast();
    return android::binder::Status::ok();
};

android::binder::Status ACameraServiceListener::onTorchStatusChanged(int32_t status, const android::String16& cameraId) {
    (void) status;
    (void) cameraId;
//    printf("onTorchStatusChanged status %d, cameraId %s\n", status, android::String8(cameraId).c_str());
//    android::Mutex::Autolock l(mLock);
//    mCameraTorchStatuses[cameraId] = status;
//    mTorchCondition.broadcast();
    return android::binder::Status::ok();
};

/*
bool ACameraServiceListener::waitForNumCameras(size_t num) const {
//    printf("waitForNumCameras num %zu\n", num);
    android::Mutex::Autolock l(mLock);

    if (mCameraStatuses.size() == num) {
        return true;
    }

    while (mCameraStatuses.size() < num) {
        if (mCondition.waitRelative(mLock, SETUP_TIMEOUT) != android::OK) {
            return false;
        }
    }
    return true;
};

bool ACameraServiceListener::waitForTorchState(int32_t status, int32_t cameraId) const {
    printf("waitForTorchState status %d, cameraId %d\n", status, cameraId);
    android::Mutex::Autolock l(mLock);

    const auto& iter = mCameraTorchStatuses.find(android::String16(android::String8::format("%d", cameraId)));
    if (iter != mCameraTorchStatuses.end() && iter->second == status) {
        return true;
    }

    bool foundStatus = false;
    while (!foundStatus) {
        if (mTorchCondition.waitRelative(mLock, SETUP_TIMEOUT) != android::OK) {
            return false;
        }
        const auto& iter =
                mCameraTorchStatuses.find(android::String16(android::String8::format("%d", cameraId)));
        foundStatus = (iter != mCameraTorchStatuses.end() && iter->second == status);
    }
    return true;
};

int32_t ACameraServiceListener::getTorchStatus(int32_t cameraId) const {
    printf("getTorchStatus cameraId %d\n", cameraId);
    android::Mutex::Autolock l(mLock);
    const auto& iter = mCameraTorchStatuses.find(android::String16(android::String8::format("%d", cameraId)));
    if (iter == mCameraTorchStatuses.end()) {
        return android::hardware::ICameraServiceListener::TORCH_STATUS_UNKNOWN;
    }
    return iter->second;
};

int32_t ACameraServiceListener::getStatus(const android::String16& cameraId) const {
    printf("getStatus cameraId %s\n", android::String8(cameraId).c_str());
    android::Mutex::Autolock l(mLock);
    const auto& iter = mCameraStatuses.find(cameraId);
    if (iter == mCameraStatuses.end()) {
        return android::hardware::ICameraServiceListener::STATUS_UNKNOWN;
    }
    return iter->second;
};
*/
