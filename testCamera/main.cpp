
#include <gui/Surface.h>
#include <gui/SurfaceComposerClient.h>
#include <gui/ISurfaceComposer.h>

#include <system/graphics.h>
#include <hardware/gralloc.h>
#include <hardware/hwcomposer_defs.h>
#include "ICameraManager.h"
#include <list>

int main(int argc, char** argv) {
    printf("argc %d argv %s \n", argc , argv[0]);
    int width = 1440;
    int height = 2880;
    if (argc >= 3) {
        width = atoi(argv[1]);
        height = atoi(argv[2]);
    }

    android::sp<android::SurfaceComposerClient> client = new android::SurfaceComposerClient();
    std::list<android::sp<android::SurfaceControl>> sfc;

    struct ICameraManager* manager = getICameraManager();
    int32_t numCameras = 0;
    if (manager->init(manager, &numCameras) < 0) {
        printf(" init error \n");
        return -1;
    }


    for (int32_t i = 0 ; i < numCameras ; ++i) {
        android::sp<android::SurfaceControl> surfaceControl = client->createSurface(android::String8("nom nom"),
                    width, height, HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED, 0);
        sfc.push_back(surfaceControl);
    //    	SurfaceComposerClient::setDisplayLayerStack(dtoken, layerStack);
        android::SurfaceComposerClient::openGlobalTransaction();
        surfaceControl->setLayerStack(0);
        surfaceControl->setLayer(300000);//设定Z坐标
        surfaceControl->setPosition(0, i * height);//以左上角为(0,0)设定显示位置
        surfaceControl->show();//感觉没有这步,图片也能显示
        android::SurfaceComposerClient::closeGlobalTransaction();


        android::sp<android::Surface> surface = surfaceControl->getSurface();

        void* gbp = (void*)surface->getIGraphicBufferProducer().get();
        manager->open(manager, i, gbp);
    }

    while(1) {
        sleep(1);
        printf("sleep 1 second\n");
    }

    return 0;
}
