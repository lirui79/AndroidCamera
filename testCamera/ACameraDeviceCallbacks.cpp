#include "ACameraDeviceCallbacks.h"

ACameraDeviceCallbacks::ACameraDeviceCallbacks() {}

ACameraDeviceCallbacks::~ACameraDeviceCallbacks() {}

android::binder::Status ACameraDeviceCallbacks::onDeviceError(int errorCode,
        const android::CaptureResultExtras& resultExtras) {
//    printf("%s: onDeviceError occurred with: %d\n", __FUNCTION__, static_cast<int>(errorCode));
    (void) resultExtras;
    (void) errorCode;
    return android::binder::Status::ok();
}

android::binder::Status ACameraDeviceCallbacks::onDeviceIdle() {
//    printf("%s: onDeviceIdle \n", __FUNCTION__);
    return android::binder::Status::ok();
}

android::binder::Status ACameraDeviceCallbacks::onCaptureStarted(const android::CaptureResultExtras& resultExtras,
        int64_t timestamp) {
//    printf("%s: onCaptureStarted \n", __FUNCTION__);
    (void) resultExtras;
    (void) timestamp;
    return android::binder::Status::ok();
}

android::binder::Status ACameraDeviceCallbacks::onResultReceived(const android::CameraMetadata& metadata,
        const android::CaptureResultExtras& resultExtras) {
//    printf("%s: onResultReceived \n", __FUNCTION__);
    (void) metadata;
    (void) resultExtras;
    return android::binder::Status::ok();
}

android::binder::Status ACameraDeviceCallbacks::onPrepared(int streamId) {
//    printf("%s: onPrepared streamId %d \n", __FUNCTION__, streamId);
    (void) streamId;
    return android::binder::Status::ok();
}

android::binder::Status ACameraDeviceCallbacks::onRepeatingRequestError(
        int64_t lastFrameNumber, int32_t stoppedSequenceId) {
//    printf("%s: onRepeatingRequestError lastFrameNumber %" PRId64 " stoppedSequenceId %d\n", __FUNCTION__, lastFrameNumber, stoppedSequenceId);
    (void) lastFrameNumber;
    (void) stoppedSequenceId;
    return android::binder::Status::ok();
}

android::binder::Status ACameraDeviceCallbacks::onRequestQueueEmpty() {
//    printf("%s: onRequestQueueEmpty \n", __FUNCTION__);
    return android::binder::Status::ok();
}
