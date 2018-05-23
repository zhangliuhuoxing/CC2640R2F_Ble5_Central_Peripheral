#ifndef _MY_RGB_H_
#define _MY_RGB_H_

#include <sys/stdint.h>

#define RGB_COLOUR_OFF      0x000000
#define RGB_COLOUR_RED      0xFF0000
#define RGB_COLOUR_GREEN    0x00FF00
#define RGB_COLOUR_BLUE     0x0000FF
#define RGB_COLOUR_WHITE    0xFFFFFF

/*********************∫Í∂®“Â************************/

#define RGB_PWM_FRE      2000             //1000Hz

extern int8_t my_RGB_init(void);
int8_t my_RGB_set_colour(uint32_t RGB_colour_code);
uint32_t my_RGB_get_colour(void);
void my_RGB_flash(void);

#endif
