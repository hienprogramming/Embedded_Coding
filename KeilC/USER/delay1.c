#include "delay1.h"

// For store tick counts in us and make sure it is saved to memory 
static __IO uint32_t usTicks;  

void SysTick_Handler()
{
    if(usTicks != 0){
        usTicks--;
    }
}

void DelayInit()
{
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClockUpdate / 1000000);
}

void DelayUs(uint32_t us)
{
    usTicks = us;
    while(usTicks);
}

void DelayMs(uint32_t ms)
{
    while(ms--){
        DelayUs(1000);
    }
}