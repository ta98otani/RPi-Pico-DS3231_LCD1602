cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(DeskClock C CXX ASM) 
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${PROJECT_NAME}
   DeskClock.cpp
)


target_sources (${PROJECT_NAME}
   PUBLIC 
   ${CMAKE_CURRENT_LIST_DIR}/DS3231/ds3231.cpp
   ${CMAKE_CURRENT_LIST_DIR}/LCD1602/lcd1602.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/DS3231
        ${CMAKE_CURRENT_LIST_DIR}/LCD1602
)

# Pull in our (to be renamed) simple get you started dependencies
target_link_libraries(${PROJECT_NAME} pico_stdlib hardware_i2c)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})

