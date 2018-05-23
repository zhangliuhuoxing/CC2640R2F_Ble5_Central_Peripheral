#ifndef _My_MOTOR_H_
#define _My_MOTOR_H_

#include <ti/drivers/PWM.h>

/*********************宏定义************************/
#define PWM_FRE     400      //400hz

//类型宏
#ifndef PWM_STATUS
    typedef signed char PWM_STATUS;
#endif

extern PWM_Handle gPWM0;

PWM_STATUS my_Motor_init(void);

#endif
