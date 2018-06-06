#ifndef _My_ACCELERATOR_H_
#define _My_ACCELERATOR_H_

#include <ti/drivers/ADC.h>

/*********************�궨��************************/

extern ADC_Handle accelerator_adc;
extern uint16_t temp_accelerator_value1, temp_accelerator_value2;
extern uint32_t fre_count;
extern float test_pwm_percent;

int8_t my_accelerator_init(void);
uint16_t my_accelerator_get(ADC_Handle ADCn);

#endif
