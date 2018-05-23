#include <My_Motor.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Log.h>
#include <ti/sysbios/BIOS.h>
#include "board.h"
#include <ti/drivers/power/PowerCC26XX.h>

PWM_Handle gPWM0;

// Initialize the PWM driver.
PWM_STATUS my_Motor_init(void)
{
    PWM_Params pwmParams;

    // Initialize the PWM parameters
    PWM_init();

    PWM_Params_init(&pwmParams);
    pwmParams.idleLevel = PWM_IDLE_LOW;      // Output low when PWM is not running
    pwmParams.periodUnits = PWM_PERIOD_HZ;   // Period is in Hz
    pwmParams.periodValue = PWM_FRE;
    pwmParams.dutyUnits = PWM_DUTY_FRACTION; // Duty is in fractional percentage
    pwmParams.dutyValue = 0;                 // 0% initial duty cycle
    // Open the PWM instance
    gPWM0 = PWM_open(MOTOR_PWM, &pwmParams);

    if (gPWM0 == NULL)
    {
        // PWM_open() failed
        return -1;
    }

    PWM_start(gPWM0);                                      // start PWM with 0% duty cycle
    PWM_setDuty(gPWM0, (PWM_DUTY_FRACTION_MAX * 0.4f));     //

    return 0;
}
