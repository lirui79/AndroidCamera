#include "ACameraDevice.h"
#include <gui/IGraphicBufferProducer.h>
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>
#include <gui/Surface.h>

ACameraDevice::ACameraDevice() {
}

ACameraDevice::~ACameraDevice() {}

int ACameraDevice::connect(android::sp<android::hardware::ICameraService> &service, int32_t cameraID, void *gbp) {
//    android::Surface *surface = (android::Surface*) sf;
    android::ProcessState::self()->startThreadPool();
    android::String16 cameraId(android::String8::format("%d",cameraID));
    android::binder::Status status;
    mCallbacks = new ACameraDeviceCallbacks();
    status = service->connectDevice(mCallbacks, cameraId, android::String16("camera"), android::hardware::ICameraService::USE_CALLING_UID, &mDevice);
    if (!status.isOk())
        return status.exceptionCode();

    android::sp<android::IGraphicBufferProducer> producer((android::IGraphicBufferProducer*)gbp);
    android::Surface *surface = new android::Surface(producer);
    android::OutputConfiguration output(producer, 0);
    status = mDevice->beginConfigure();
    if (!status.isOk())
        return status.exceptionCode();

    status = mDevice->createStream(output, &mStreamID);
    if (!status.isOk())
        return status.exceptionCode();
    printf("createStream mStreamID %d\n", mStreamID);

    status = mDevice->endConfigure(0);
    if (!status.isOk())
        return status.exceptionCode();

    android::CameraMetadata requestTemplate;
    status = mDevice->createDefaultRequest(android::hardware::camera2::ICameraDeviceUser::TEMPLATE_PREVIEW, &requestTemplate);
    if (!status.isOk())
        return status.exceptionCode();

    android::hardware::camera2::CaptureRequest request;
    request.mMetadata = requestTemplate;
    request.mSurfaceList.add(surface);
    request.mIsReprocess = false;

    android::hardware::camera2::utils::SubmitInfo info;
    status = mDevice->submitRequest(request, /*streaming*/true, /*out*/&info);
    if (!status.isOk())
        return status.exceptionCode();
    return 0;
}

int ACameraDevice::disconnect() {
    if (mDevice == NULL)
       return 1;
       // Can we unconfigure?
    android::binder::Status status = mDevice->beginConfigure();
    if (!status.isOk())
        return status.exceptionCode();
   status = mDevice->deleteStream(mStreamID);
   if (!status.isOk())
       return status.exceptionCode();
   status = mDevice->endConfigure(0);
   if (!status.isOk())
       return status.exceptionCode();

//   sleep(/*second*/1); // allow some time for errors to show up, if any

   status = mDevice->disconnect();
   if (!status.isOk())
       return status.exceptionCode();
    return 0;
}
