# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Focus_Project C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# add compiled files subdirectory
add_subdirectory(Modules/Config)
add_subdirectory(Modules/PushButtons)
add_subdirectory(Modules/LCD)
add_subdirectory(Modules/Fonts)
add_subdirectory(Modules/GUI)

add_subdirectory(Apps/Entry)
add_subdirectory(Apps/Wallpaper)


# add header file directory
include_directories(./Apps/Entry)
include_directories(./Apps/Wallpaper)
include_directories(./Modules/Config)
include_directories(./Modules/GUI)
include_directories(./Modules/LCD)
include_directories(./Modules/PushButtons)

# Add executable. Default name is the project name, version 0.1

add_executable(Focus_Project Focus_Project.c )

pico_set_program_name(Focus_Project "Focus_Project")
pico_set_program_version(Focus_Project "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Focus_Project 0)
pico_enable_stdio_usb(Focus_Project 0)

# Add the standard library to the build
target_link_libraries(Focus_Project
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(Focus_Project PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(Focus_Project 
    Entry
    LCD 
    PushButtons 
    GUI 
    Fonts 
    Config
    Wallpaper 
    pico_stdlib 
    hardware_spi
        )

pico_add_extra_outputs(Focus_Project)

