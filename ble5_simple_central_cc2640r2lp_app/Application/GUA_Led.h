#ifndef _GUA_LED_H_
#define _GUA_LED_H_
/*********************宏定义************************/
//类型宏
#ifndef GUA_U8
    typedef unsigned char GUA_U8;
#endif
//LEDS
#define GUA_LED_NO_2 0x01
#define GUA_LED_NO_ALL (GUA_LED_NO_2)
//Modes
#define GUA_LED_MODE_OFF 0x00
#define GUA_LED_MODE_ON 0x01
#define GUA_LED_MODE_FLASH 0x02
#define GUA_LED_MODE_TOGGLE 0x04
/*********************函数声明************************/
extern void GUA_Led_Set(GUA_U8 nGUA_Led_No, GUA_U8 nGUA_Mode);
#endif
