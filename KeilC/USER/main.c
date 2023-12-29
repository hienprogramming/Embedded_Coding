#include"stm32f10x.h"

#include"lcd16x2.h"

void main(void)
{
    int i;
    DelayInit();
    LCD_Init();

    while(1)
    {
        LCD_Gotoxy(0, 0);
        LCD_Puts("BACH DINH HIEN");
        for(i=0; i<16; i++)
        {
            LCD_SendCommand(0x1C);
            DelayMs(10);
        }
        for(i=0; i<16; i++)
        {
            LCD_SendCommand(0x18);
            DelayMs(10);
        }
    }
}