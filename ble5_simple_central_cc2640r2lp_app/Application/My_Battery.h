#ifndef _My_ADC_H_
#define _My_ADC_H_

#include <sys/stdint.h>
#include <ti/drivers/ADC.h>

/*********************∫Í∂®“Â************************/

extern ADC_Handle adc;
extern uint16_t adc_value;
extern uint32_t micro_volt;

int8_t my_battery_init(void);
int32_t my_battery_get_voltage(ADC_Handle ADCn);

#endif
