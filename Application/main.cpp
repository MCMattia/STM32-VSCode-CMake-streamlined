#include "main.h"
#include "stm32l4xx_hal.h"

extern "C" {
extern void SystemClock_Config();
}

int main()
{
    HAL_Init();

    SystemClock_Config();
}
