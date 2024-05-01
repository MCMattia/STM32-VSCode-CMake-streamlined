cmake_minimum_required(VERSION 3.28)

message("Entering ${CMAKE_CURRENT_LIST_FILE}")

set(PROJECT_TYPE_EXECUTABLE          "exe")
set(PROJECT_TYPE_STATIC_LIBRARY      "static-lib")

set(PROJECT_NAME                     "STM32-CMake-base")
set(PROJECT_TYPE                     "exe")
set(LINKER_SCRIPT                    "${CMAKE_CURRENT_SOURCE_DIR}/STM32L4A6AGIX_FLASH.ld")
set(MCPU                             "-mcpu=cortex-m4")
set(MFPU                             "-mfpu=fpv4-sp-d16")
set(MFLOAT_ABI                       "-mfloat-abi=hard")
set(RUNTIME_LIBRARY                  "--specs=nano.specs")
set(RUNTIME_LIBRARY_SYSCALLS         "--specs=nosys.specs")

set(PROJECT_SOURCES
    # find . -name "*.c" -type f
    Core/Src/main.c
    Core/Src/stm32l4xx_hal_msp.c
    Core/Src/stm32l4xx_it.c
    Core/Src/syscalls.c
    Core/Src/sysmem.c
    Core/Src/system_stm32l4xx.c
    Core/Startup/startup_stm32l4a6agix.s
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_cortex.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_exti.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_flash_ex.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_flash_ramfunc.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_flash.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_gpio.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_i2c_ex.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_i2c.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_pwr_ex.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_pwr.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_rcc_ex.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_rcc.c
    Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal.c
    )

set(PROJECT_DEFINES
    DEBUG
    STM32L4A6xx
    USE_HAL_DRIVER
    )

set(PROJECT_INCLUDES
    Core/Inc
    Drivers/STM32L4xx_HAL_Driver/Inc
    Drivers/STM32L4xx_HAL_Driver/Inc/Legacy
    Drivers/CMSIS/Device/ST/STM32L4xx/Include
    Drivers/CMSIS/Include
    )

project(${PROJECT_NAME})
enable_language(C CXX ASM)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

add_compile_definitions(${PROJECT_DEFINES})
include_directories(${PROJECT_INCLUDES})

set(CMAKE_EXECUTABLE_SUFFIX ".elf")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".a")
set(CMAKE_ASM_FLAGS "${MCPU} -g3 -c -x assembler-with-cpp ${RUNTIME_LIBRARY} ${MFPU} ${MFLOAT_ABI} -mthumb")
set(CMAKE_C_FLAGS "${MCPU} -std=gnu18 -g3 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity ${RUNTIME_LIBRARY} ${MFPU} ${MFLOAT_ABI} -mthumb")
set(CMAKE_EXE_LINKER_FLAGS "${MCPU} -T${LINKER_SCRIPT} ${RUNTIME_LIBRARY_SYSCALLS} -Wl,-Map=${CMAKE_PROJECT_NAME}.map -Wl,--gc-sections -static ${MFPU} ${MFLOAT_ABI} -mthumb -Wl,--start-group -lc -lm -Wl,--end-group")
