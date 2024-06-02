The STM32CubeIDE software serves as an excellent starting point for STM32 development. However, when it comes to developer experience, the IDE provided by ST can feel sluggish and resource-intensive.

This repo is used to document how to seamlessly transition from STM32CubeIDE to Visual Studio Code for your embedded software development needs. Under the hood, a robust CMake build system is set up. Clangd is used for indexing, formatting and tidy checks. VS Code is configured to efficiently manage the CMake project, clangd, and debugging.

More information is available in the article [Streamlining STM32 Projects: VS Code, CMake and clangd](https://dev.to/mcmattia/streamlining-stm32-projects-vs-code-cmake-and-clangd-bhp).