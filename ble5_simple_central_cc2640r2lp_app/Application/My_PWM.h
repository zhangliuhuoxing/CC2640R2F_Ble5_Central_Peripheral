#ifndef _My_PWM_H_
#define _My_PWM_H_
/*********************�궨��************************/
#define PWM_FRE     400      //400hz

//���ͺ�
#ifndef PWM_STATUS
    typedef signed char PWM_STATUS;
#endif

extern PWM_Handle gPWM0;

PWM_STATUS My_PWM_init(void);

#endif
