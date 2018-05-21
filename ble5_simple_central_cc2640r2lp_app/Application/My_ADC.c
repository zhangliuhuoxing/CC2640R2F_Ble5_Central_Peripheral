#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Log.h>
#include <ti/sysbios/BIOS.h>
#include "board.h"
#include <ti/drivers/power/PowerCC26XX.h>
#include <ti/drivers/ADC.h>

#include "My_ADC.h"

ADC_Handle adc;

uint16_t adc_value = 0;
uint32_t micro_volt = 0;

int8_t My_ADC_init(void)
{
    ADC_Params params;
    ADC_init();
    ADC_Params_init(&params);
//    adc = ADC_open(DC_FB_ADC, &params); //Board_ADCCHANNEL_A0
    if (adc == NULL)
    {
        // ADC_open() failed
        return -1;
    }

    return 0;
}

int32_t My_ADC_Get(ADC_Handle ADCn)
{
    int_fast16_t res;
    uint16_t adcValue;
    res = ADC_convert(adc, &adcValue);
    if (res == ADC_STATUS_ERROR)
    {
        //ADC_convert() failed
        return -1;
    }

    return adcValue;
}




