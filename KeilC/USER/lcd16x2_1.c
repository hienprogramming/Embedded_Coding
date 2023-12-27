#include"stm32f10x.h"
#include"delay1.h"

#define LCD_D4   GPIO_Pin_8
#define LCD_D5   GPIO_Pin_9
#define LCD_D6   GPIO_Pin_10
#define LCD_D7   GPIO_Pin_11

#define LCD_RS   GPIO_Pin_13
#define LCD_RW   GPIO_Pin_14
#define LCD_EN   GPIO_Pin_15

void GPIO_LCD_Config(void)
{
    // enable clock
    // using one pointer to contain the state of pins MCU connect to LCD
    // one function call for init GPIO
    RCC_APB2PeriphResetCmd (GPIOA | GPIOC, )
}

// LCD enable
void LCD_Enable(void)
{

}

// Send data
void LCD_Send4Bit(unsigned char Data)
{

}

// Send command 
void LCD_SendCommand(unsigned char Command) // 8 bits
{

}

void LCD_Gotoxy(unsigned char data)
{

}

void LCD_PutChar(char *s)
{

}






