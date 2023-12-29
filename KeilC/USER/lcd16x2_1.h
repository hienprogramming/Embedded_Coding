#ifndef __LCD_H
#define __LCD_H

#ifdef __cplusplus
 extern "C" {        // Những dòng này đảm bảo rằng tệp tiêu đề có thể được sử dụng cả trong mã C và C++. extern "C" đảm bảo rằng trình biên dịch C++ không thay đổi tên hàm, giúp làm cho nó tương thích với C
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "delay1.h"


void GPIO_LCD_Config(void);
void LCD_Enable(void);
void LCD_Send4Bit(unsigned char Data);
void LCD_SendCommand(unsigned char Command);
void LCD_Clear();
void LCD_Init();
void LCD_Gotoxy(unsigned char x, unsigned char y);
void LCD_PutChar(unsigned char Data);
void LCD_Puts(char *s);




#ifdef __cplusplus

}
#endif

#endif /* __MISC_H */