# Streamlining STM32 Projects: VS Code, CMake and clangd

The STM32CubeIDE software serves as an excellent starting point for STM32 development. However, when it comes to developer experience, the IDE provided by ST can feel sluggish and resource-intensive.

This repo is used to document how to seamlessly transition from STM32CubeIDE to Visual Studio Code for your embedded software development needs. Under the hood, a robust CMake build system is set up. Clangd is used for indexing, formatting and tidy checks. VS Code is configured to efficiently manage the CMake project, clangd, and debugging.

More information is available in the article [Streamlining STM32 Projects: VS Code, CMake and clangd](https://dev.to/mcmattia/streamlining-stm32-projects-vs-code-cmake-and-clangd-bhp).

## Setup

Depending on your environment, you will need to customize different paths to your toolchain and related tools. In the repository you will find a configuration for a linux system.

If you install another version of STM32CubeIDE or install it in a different folder than `/opt/` adaptation of the hardcoded paths will be required.

Here an example to configure the different paths with a windows system:

In `.vscode/settings.json` adapt the path of gdb and the path of the gcc compiler. Here an example:

```
"cortex-debug.gdbPath": "C:/ST/STM32CubeIDE_1.15.1/STM32CubeIDE/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.12.3.rel1.win32_1.0.100.202403111256/tools/bin/arm-none-eabi-gdb",
"cortex-debug.JLinkGDBServerPath": "C:/ST/STM32CubeIDE_1.15.1/STM32CubeIDE/plugins/com.st.stm32cube.ide.mcu.externaltools.jlink.win32_2.2.200.202402092224/tools/bin/JLinkGDBServerCL.exe",
"clangd.arguments": [
    "--query-driver=C:/ST/STM32CubeIDE_1.15.1/STM32CubeIDE/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.12.3.rel1.win32_1.0.100.202403111256/tools/bin/*",
  ],
```

In the CMake toolchain file `gcc-arm-none-eabi.cmake` adapt the `TOOLCHAIN_PREFIX` and add `.exe` for the executables:

```
set(TOOLCHAIN_PREFIX   "C:/ST/STM32CubeIDE_1.15.1/STM32CubeIDE/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.12.3.rel1.win32_1.0.100.202403111256/tools/bin/arm-none-eabi-")
set(CMAKE_C_COMPILER   "${TOOLCHAIN_PREFIX}gcc.exe")
```
