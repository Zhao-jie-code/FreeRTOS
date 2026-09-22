/*  Copyright (s) 2023 深圳百问网科技有限公司
 *  All rights reserved
 * 
 * 文件名称：driver_mpu6050.c
 * 摘要：
 *  

 *--------------------------------------------------
*/

#ifndef __DRIVER_MPU6050_H
#define __DRIVER_MPU6050_H

#include <stdint.h>
#include "FreeRTOS.h"
#include "queue.h"


struct mpu6050_data{
    int32_t angle_x;
};

/**********************************************************************
 * 函数名称： MPU6050_Init
 * 功能描述： MPU6050初始化函数,
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 0 - 成功, 其他值 - 失败

 ***********************************************************************/
int MPU6050_Init(void);

/**********************************************************************
 * 函数名称： MPU6050_GetID
 * 功能描述： 读取MPU6050 ID
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 01 - 失败, 其他值 - ID

 ***********************************************************************/
int MPU6050_GetID(void);



/**********************************************************************
 * 函数名称： MPU6050_ReadData
 * 功能描述： 读取MPU6050数据
 * 输入参数： 无
 * 输出参数： pAccX/pAccY/pAccZ         - 用来保存X/Y/Z轴的加速度
 *            pGyroX/pGyroY/pGyroZ - 用来保存X/Y/Z轴的角速度
 * 返 回 值： 0 - 成功, 其他值 - 失败

 ***********************************************************************/
int MPU6050_ReadData(int16_t *pAccX, int16_t *pAccY, int16_t *pAccZ, int16_t *pGyroX, int16_t *pGyroY, int16_t *pGyroZ);

/**********************************************************************
 * 函数名称： MPU6050_Test
 * 功能描述： MPU6050测试程序
 * 输入参数： 无
 * 输出参数： 无
 *            无
 * 返 回 值： 0 - 成功, 其他值 - 失败

 ***********************************************************************/
void MPU6050_Test(void);

QueueHandle_t GetQueueMPU6050(void);

void MPU6050_Task(void *params);

void MPU6050_ParseData(int16_t AccX, int16_t AccY, int16_t AccZ, int16_t GyroX, int16_t GyroY, int16_t GyroZ, struct mpu6050_data *result);

#endif /* __DRIVER_OLED_H */

