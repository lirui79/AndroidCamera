/*****************************************************/
/*
**   Author: lirui
**   Date: 2019/07/17
**   File: ICameraManager.h
**   Function:  Interface of ICameraManager for user
**   History:
**       2019/07/17 create by lirui
**
**   Copy Right: iris corp
**
*/
/*****************************************************/
#ifndef VIRTUAL_INTERFACE_CAMERA_MANAGER_H
#define VIRTUAL_INTERFACE_CAMERA_MANAGER_H

#include <stdint.h>

/**
 * @addtogroup Platform
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif


typedef struct ICameraManager {
	/**
	 * @brief ICameraManager 初始化函数
	 *
	 * @param[in]     manager     结构体指针
	 * @param[inout]  numCameras  指针 返回相机个数
	 *
	 * @return 返回说明
	 *        -<em> < 0</em>   失败
	 *        -<em> >=0</em>   成功
	 *
	 * @example struct ICameraManager* manager = getICameraManager();
	 *          int32_t numCameras = 0;
	 *          int code = manager->init(manager, &numCameras);
	 */
	int (*init)(struct ICameraManager* manager, int32_t *numCameras);

	/**
	 * @brief ICameraManager 打开相机函数
	 *
	 * @param[in]     manager      结构体指针
     * @param[in]     cameraID     相机编号 从零开始
     * @param[in]     gbp          IGraphicBufferProducer指针
	 *
	 * @return 返回说明
	 *        -<em> < 0</em>   失败
	 *        -<em> >=0</em>   成功
	 *
     * @example struct ICameraManager* manager = getICameraManager();
	 *          int32_t numCameras = 0;
	 *          int code = manager->init(manager, &numCameras);
     *          void *gbp = NULL;
     *          ...
     *          code = manager->open(manager, 0, gbp);
	 */
    int (*open)(struct ICameraManager* manager, int32_t cameraID, void* gbp);

	/**
	 * @brief ICameraDevice 初始化函数
	 *
     * @param[in]     manager      结构体指针
     * @param[in]     cameraID     相机编号 从零开始
	 *
	 * @return 返回说明
	 *        -<em> < 0</em>   失败
	 *        -<em> >=0</em>   成功
	 *
	 */
    int (*close)(struct ICameraManager* manager, int32_t cameraID);

} ICameraManager;

/**
 * @brief 分配ICameraManager结构体指针函数
 *
 * @return 返回说明
 *        -<em>非NULL</em>    成功 返回结构体指针
 *        -<em>NULL</em>      失败
 *
 * @example struct ICameraManager* manager = getICameraManager();
 *          int32_t numCameras = 0;
 *          int code = manager->init(manager, &numCameras);
 *          void *sf = NULL;
 *          ...
 *          code = manager->open(manager, 0, sf);
 *          code = manager->close(manager, 0);
 */
typedef struct ICameraManager* (*getICameraManagerType)();
__attribute__((visibility("default"))) struct ICameraManager*
getICameraManager();

#if defined(__cplusplus)
}
#endif

/**
 * @}
 */

#endif  // VIRTUAL_INTERFACE_CAMERA_MANAGER_H
