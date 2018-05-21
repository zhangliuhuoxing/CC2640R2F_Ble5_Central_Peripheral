#include <My_RGB.h>
#include <string.h>
#include <stdio.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/drivers/PIN.h>
#include "board.h"
#include <ti/drivers/PWM.h>

PWM_Handle gPWM_R;
PWM_Handle gPWM_G;
PWM_Handle gPWM_B;

// Initialize the RGB driver.
int8_t My_RGB_init(void)
{
    PWM_Params pwmParams;

    // Initialize the PWM parameters
    PWM_init();

    PWM_Params_init(&pwmParams);
    pwmParams.idleLevel = PWM_IDLE_LOW;      // Output low when PWM is not running
    pwmParams.periodUnits = PWM_PERIOD_HZ;   // Period is in Hz
    pwmParams.periodValue = RGB_PWM_FRE;
    pwmParams.dutyUnits = PWM_DUTY_FRACTION; // Duty is in fractional percentage
    pwmParams.dutyValue = 0;                 // 0% initial duty cycle
    // Open the PWM instance

//    gPWM_R = PWM_open(RGB_R_PWM, &pwmParams);
//    if (gPWM_R == NULL)
//    {
//        // PWM_open() failed
//        return -1;
//    }
//
//    gPWM_G = PWM_open(RGB_G_PWM, &pwmParams);
//    if (gPWM_G == NULL)
//    {
//        // PWM_open() failed
//        return -1;
//    }
//
//    gPWM_B = PWM_open(RGB_B_PWM, &pwmParams);
//    if (gPWM_B == NULL)
//    {
//        // PWM_open() failed
//        return -1;
//    }

    PWM_start(gPWM_R);                                      // start PWM with 0% duty cycle
    PWM_setDuty(gPWM_R, (PWM_DUTY_FRACTION_MAX * 0.4f));     //
    PWM_start(gPWM_G);                                      // start PWM with 0% duty cycle
    PWM_setDuty(gPWM_G, (PWM_DUTY_FRACTION_MAX * 0.4f));     //
    PWM_start(gPWM_B);                                      // start PWM with 0% duty cycle
    PWM_setDuty(gPWM_B, (PWM_DUTY_FRACTION_MAX * 0.4f));     //

    return 0;
}

