#include "main.h"
#include "gpio.h"

extern "C"
{
    extern void SystemClock_Config();
}

int main()
{
    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();

    while (true)
    {
        HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
        HAL_Delay(1000);
    }
}
