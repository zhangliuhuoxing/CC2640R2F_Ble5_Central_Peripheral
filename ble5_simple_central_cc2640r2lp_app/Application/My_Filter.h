#ifndef __FILTER_H
#define __FILTER_H

#include <sys/stdint.h>

float Moving_Average(uint8_t item,uint8_t width_num,float in);
float Moving_Median(uint8_t item, uint8_t width_num, float in);

#endif
