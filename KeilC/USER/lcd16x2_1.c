#include"lcd16x2_1.h"

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
    GPIO_InitTypeDef    GPIO_LCD_Init;

    RCC_APB2PeriphResetCmd (RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_WriteBit(GPIOA, LCD_D4|LCD_D5|LCD_D6|LCD_D7, Bit_RESET);
    GPIO_WriteBit(GPIOC, LCD_RS|LCD_RW|LCD_EN, Bit_RESET);

    GPIO_LCD_Init.GPIO_Mode =  GPIO_Mode_Out_PP;
    GPIO_LCD_Init.GPIO_Pin =  LCD_D4|LCD_D5|LCD_D6|LCD_D7;
    GPIO_LCD_Init.GPIO_Speed =  GPIO_Mode_Out_PP;
    GPIO_Init (GPIOA, &GPIO_LCD_Init);

    GPIO_LCD_Init.GPIO_Pin = LCD_RS|LCD_RW|LCD_EN;
    GPIO_Init (GPIOC, &GPIO_LCD_Init);
}

// LCD enable
void LCD_Enable(void)
{
    GPIO_SetBits(GPIOC, LCD_EN);
    DelayMs(1);
    GPIO_ResetBits(GPIOC, LCD_EN);
    DelayMs(1);
}

// Send data 4 bit
void LCD_Send4Bit(unsigned char Data)
{
    GPIO_WriteBit(GPIOA, LCD_D4, Data&0x01);
    GPIO_WriteBit(GPIOA, LCD_D5, (Data >> 1)&0x01);
    GPIO_WriteBit(GPIOA, LCD_D6, (Data >> 2)&0x01);
    GPIO_WriteBit(GPIOA, LCD_D7, (Data >> 3)&0x01);
}

// Send command 
void LCD_SendCommand(unsigned char Command) // 8 bits
{
    LCD_Send4Bit(Command >> 4);
    LCD_Enable();
    LCD_Send4Bit(Command);
    LCD_Enable();
}

void LCD_Clear()
{
    LCD_SendCommand(0x01);
    DelayMs(2);
}

void LCD_Init()
{
  GPIO_LCD_Config();

  LCD_Send4Bit(0x00);
  // Nhận dữ liệu
  GPIO_WriteBit(GPIOC, LCD_RS, 0);  
  LCD_Send4Bit(0x03);  // return home -> đầu dòng đầu tiên
  LCD_Enable();
  // LCD_Enable();
  // LCD_Enable();
  LCD_Send4Bit(0x02);  // return home -> đầu dòng đầu tiên
  LCD_Enable();
  LCD_SendCommand(0x28); // giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
  LCD_SendCommand(0x0C); // cho phep hien thi man hinh
  LCD_SendCommand(0x06); // tang ID, khong dich khung hinh
  // LCD_SendCommand(0x01); // xoa toan bo khung hinh
}

void LCD_Gotoxy(unsigned char x, unsigned char y)  // x: row, y=colum
{
  unsigned char address;
  if(y == 0)address=(0x80 + x);  // Địa chỉ đầu tiên của hàng 1
  else if(y == 1) address=(0xc0 + x);  // Địa chỉ đầu tiên của hàng 2
  LCD_SendCommand(address);
}

void LCD_PutChar(unsigned char Data)
{
  GPIO_SetBits(GPIOC, LCD_RS);
  LCD_SendCommand(Data);
  GPIO_ResetBits(GPIOC, LCD_RS);
}

void LCD_Puts(char *s)
{
  while (*s)
  {
    LCD_PutChar(*s);
    s++;
  }
}





