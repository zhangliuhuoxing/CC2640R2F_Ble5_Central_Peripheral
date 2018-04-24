#include <string.h>
#include <stdio.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/drivers/PIN.h>

#include "GUA_Led.h"

/*********************宏定义************************/
//LEDS
#define GUA_LED2 PIN_ID(7)

/*********************内部变量************************/
static PIN_State sGUA_LedPins;
static PIN_Handle sGUA_HledPins = NULL;
//IO配置
PIN_Config bGUA_LedPinsCfg[] =
{
    GUA_LED2 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PIN_TERMINATE
};
//**********************************************************************
//name: GUA_Led_Set
//introduce: 点灯驱动
//parameter: nGUA_Led_No： GUA_LED_NO_2
// GUA_LED_NO_ALL
// nGUA_Mode： GUA_LED_MODE_OFF、 GUA_LED_MODE_ON、
// GUA_LED_MODE_FLASH、 GUA_LED_MODE_TOGGLE
//return: none
//**********************************************************************
void GUA_Led_Set(GUA_U8 nGUA_Led_No, GUA_U8 nGUA_Mode)
{
    GUA_U8 nGUA_I = 0;
    GUA_U8 nbGUA_Pin[1] = {GUA_LED2};

    //第一次使用时注册IO
    if(NULL == sGUA_HledPins)
    {
        sGUA_HledPins = PIN_open(&sGUA_LedPins, bGUA_LedPinsCfg);
    }

    //依次检测4个led是否有执行动作
    for(nGUA_I = 0; nGUA_I <= 0; nGUA_I++)
    {
        if(nGUA_Led_No & (1 << nGUA_I))
        {
            //执行模式
            switch(nGUA_Mode)
            {
                //关灯模式
                case GUA_LED_MODE_OFF:
                {
                    PIN_setOutputValue(sGUA_HledPins, nbGUA_Pin[nGUA_I], 0);
                    break;
                }

                //开灯模式
                case GUA_LED_MODE_ON:
                {
                    PIN_setOutputValue(sGUA_HledPins, nbGUA_Pin[nGUA_I], 1);
                    break;
                }
                //先亮后灭一次
                case GUA_LED_MODE_FLASH:
                {
                    PIN_setOutputValue(sGUA_HledPins, nbGUA_Pin[nGUA_I], 1);
                    Task_sleep(10*1000/Clock_tickPeriod);
                    PIN_setOutputValue(sGUA_HledPins, nbGUA_Pin[nGUA_I], 0);
                    break;
                }
                //反转一次
                case GUA_LED_MODE_TOGGLE:
                {
                    PIN_setOutputValue(sGUA_HledPins, nbGUA_Pin[nGUA_I], !PIN_getOutputValue(nbGUA_Pin[nGUA_I]));
                    break;
                }
            }
        }
    }
}
