#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "lcd16x2.h"
#include "delay1.h"

// https://www.youtube.com/watch?v=sXopHMgYJ-4

int main(void)
{
    // Delay initialization
    DelayInit();
    // LCD initialization
    LCD_Init();

		int i; 
        LCD_Gotoxy(0,0);
        LCD_Puts("Bach Dinh Hien");
			  for(i = 0; i < 6; i++)
			  {
					LCD_SendCommand(0x18);
					DelayMs(20);
				}
				
    while(1)
		{
			int i; 
        LCD_Gotoxy(0,0);
			  for(i = 0; i < 12; i++)
			  {
					LCD_SendCommand(0x1C);
					DelayMs(20);
				}
				
				for(i = 0; i < 12; i++)
			  {
					LCD_SendCommand(0x18);
					DelayMs(20);
				}
		}

    		

}

