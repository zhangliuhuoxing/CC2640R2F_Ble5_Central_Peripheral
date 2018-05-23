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

PWM_Handle gPWM_R = NULL;
PWM_Handle gPWM_G = NULL;
PWM_Handle gPWM_B = NULL;

uint32_t g_RGB_colour_code = 0;



//-----------------------------------------------------------
/*
\brief  Initialize the RGB driver.
\parm   none

\return -1:Initial failed   0:Initial success
*/
//-----------------------------------------------------------
int8_t my_RGB_init(void)
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

    gPWM_R = PWM_open(RGB_R_PWM, &pwmParams);
    if (gPWM_R == NULL)
    {
        // PWM_open() failed
        return -1;
    }

    gPWM_G = PWM_open(RGB_G_PWM, &pwmParams);
    if (gPWM_G == NULL)
    {
        // PWM_open() failed
        return -1;
    }

    gPWM_B = PWM_open(RGB_B_PWM, &pwmParams);
    if (gPWM_B == NULL)
    {
        // PWM_open() failed
        return -1;
    }

    PWM_start(gPWM_R);                                      // start PWM with 0% duty cycle
    PWM_setDuty(gPWM_R, (PWM_DUTY_FRACTION_MAX * 1.0f));    //
    PWM_start(gPWM_G);                                      // start PWM with 0% duty cycle
    PWM_setDuty(gPWM_G, (PWM_DUTY_FRACTION_MAX * 1.0f));    //
    PWM_start(gPWM_B);                                      // start PWM with 0% duty cycle
    PWM_setDuty(gPWM_B, (PWM_DUTY_FRACTION_MAX * 1.0f));    //

    return 0;
}

//-----------------------------------------------------------
/*
\brief  Set the RGB value
\parm   RGB_value :the RGB value(0x00~0xff)

\return -1:set failed  0:set success
*/
//-----------------------------------------------------------
static int8_t my_RGB_set_value(PWM_Handle RGB_PWM_handle, uint8_t RGB_value)
{
    if(RGB_PWM_handle == NULL)
    {
        return -1;
    }

    float temp_RGB_percent = (RGB_value * 1.0f) / 255.0f;
    temp_RGB_percent = 1.0f - temp_RGB_percent;

    if(PWM_setDuty(RGB_PWM_handle, (PWM_DUTY_FRACTION_MAX * temp_RGB_percent)) == -1)
    {
        return -1;
    }

    return 0;
}

//-----------------------------------------------------------
/*
\brief  Set the RGB colour
\parm   RGB_value :the RGB colour code(0x00000000~0x00ffffff)

\return -1:set failed  0:set success
*/
//-----------------------------------------------------------
int8_t my_RGB_set_colour(uint32_t RGB_colour_code)
{
    uint8_t R_value = 0;
    uint8_t G_value = 0;
    uint8_t B_value = 0;

    g_RGB_colour_code = RGB_colour_code;

    if(RGB_colour_code > 0xffffff)
    {
        return -1;
    }

    R_value = RGB_colour_code >> 16;
    G_value = (RGB_colour_code >> 8) & 0xff;
    B_value = (uint8_t)RGB_colour_code;

    if(my_RGB_set_value(gPWM_R, R_value) == -1
       || my_RGB_set_value(gPWM_G, G_value) == -1
       || my_RGB_set_value(gPWM_B, B_value) == -1)
    {
        return -1;
    }

    return 0;
}

//-----------------------------------------------------------
/*
\brief  Get the RGB colour
\parm   none

\return g_RGB_colour_code: current color code
*/
//-----------------------------------------------------------
uint32_t my_RGB_get_colour(void)
{
    return g_RGB_colour_code;
}

void my_RGB_flash(void)
{
    static uint8_t flash_flag = 0;

    flash_flag = ~flash_flag;
    if(flash_flag == 0)
    {
        my_RGB_set_value(gPWM_R, 0);
        my_RGB_set_value(gPWM_G, 0);
        my_RGB_set_value(gPWM_B, 0);
    }
    else if(flash_flag == 0xFF)
    {
        my_RGB_set_colour(my_RGB_get_colour());
    }
}

