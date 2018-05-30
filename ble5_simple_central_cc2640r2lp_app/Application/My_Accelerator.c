#include <My_Accelerator.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Log.h>
#include <ti/sysbios/BIOS.h>
#include "board.h"
#include <ti/drivers/power/PowerCC26XX.h>


ADC_Handle accelerator_adc;
uint16_t temp_accelerator_value = 0;
uint32_t fre_count = 0;

int8_t my_accelerator_init(void)
{
    ADC_Params params;
    ADC_init();
    ADC_Params_init(&params);
    accelerator_adc = ADC_open(ACCELERATOR_ADC, &params); //Board_ADCCHANNEL_A0
    if (accelerator_adc == NULL) {
        // ADC_open() failed
        return -1;
    }

    return 0;
}

uint16_t my_accelerator_get(ADC_Handle ADCn)
{
    int_fast16_t res;
    uint16_t adcValue;
    res = ADC_convert(ADCn, &adcValue);
    if (res == ADC_STATUS_SUCCESS) {
        //use adcValue
        return adcValue;
    }
}



