/*
 * Project: N|Watch
 * Author: Zak Kemble, contact@zakkemble.co.uk
 * Copyright: (C) 2013 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/diy-digital-wristwatch/
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cmsis_os.h"
#include "FreeRTOS.h"                   // ARM.FreeRTOS::RTOS:Core
#include "task.h"                       // ARM.FreeRTOS::RTOS:Core
#include "event_groups.h"               // ARM.FreeRTOS::RTOS:Event Groups
#include "semphr.h"                     // ARM.FreeRTOS::RTOS:Core

#include "driver_passive_buzzer.h"
static TimerHandle_t g_TimerSound;
void GameSoundTimer_Function( TimerHandle_t xTimer )
{
    PassiveBuzzer_Control(0);
}

int buzzer_init(void)
{
    /*初始化蜂鸣，创建定时器*/
    PassiveBuzzer_Init();
    g_TimerSound = xTimerCreate( "GameSound", 
							200,
							pdFALSE,
							NULL,
							GameSoundTimer_Function);
}

void buzzer_buzz(int frep, int time_ms)
{
    PassiveBuzzer_Set_Freq_Duty(frep, 50);
    /*启动定时器*/
    xTimerChangePeriod(g_TimerSound, time_ms, 0);
}