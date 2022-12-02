#THIS FILE IS AUTO GENERATED FROM THE TEMPLATE! DO NOT CHANGE!
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.23)

# specify cross-compilers and tools
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER  arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# project settings
project(ZeptoWatch C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

#Uncomment for hardware floating point
add_compile_definitions(ARM_MATH_CM4;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)
add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)

#Uncomment for software floating point
#add_compile_options(-mfloat-abi=soft)

add_compile_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_compile_options(-ffunction-sections -fdata-sections -fno-common -fmessage-length=0)

# uncomment to mitigate c++17 absolute addresses warnings
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-register")

# Enable assembler files preprocessing
add_compile_options($<$<COMPILE_LANGUAGE:ASM>:-x$<SEMICOLON>assembler-with-cpp>)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    #    add_compile_options(-Og -g)
    add_compile_options(-O0)
endif ()

include_directories(
        /
        Core/Inc
        Drivers/STM32F4xx_HAL_Driver/Inc
        Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
        Drivers/CMSIS/Device/ST/STM32F4xx/Include
        Drivers/CMSIS/Include
        Libraries/
        Libraries/lvgl
        Libraries/lvgl/porting
        Libraries/lvgl/src
        Libraries/lvgl/src/core
        Libraries/lvgl/src/draw
        Libraries/lvgl/src/draw/arm2d
        Libraries/lvgl/src/draw/nxp
        Libraries/lvgl/src/draw/nxp/pxp
        Libraries/lvgl/src/draw/nxp/vglite
        Libraries/lvgl/src/draw/sdl
        Libraries/lvgl/src/draw/stm32_dma2d
        Libraries/lvgl/src/draw/sw
        Libraries/lvgl/src/draw/swm341_dma2d
        Libraries/lvgl/src/extra
        Libraries/lvgl/src/extra/layouts
        Libraries/lvgl/src/extra/layouts/flex
        Libraries/lvgl/src/extra/layouts/grid
        Libraries/lvgl/src/extra/libs
        Libraries/lvgl/src/extra/libs/bmp
        Libraries/lvgl/src/extra/libs/ffmpeg
        Libraries/lvgl/src/extra/libs/freetype
        Libraries/lvgl/src/extra/libs/fsdrv
        Libraries/lvgl/src/extra/libs/gif
        Libraries/lvgl/src/extra/libs/png
        Libraries/lvgl/src/extra/libs/qrcode
        Libraries/lvgl/src/extra/libs/rlottie
        Libraries/lvgl/src/extra/libs/sjpg
        Libraries/lvgl/src/extra/others
        Libraries/lvgl/src/extra/others/fragment
        Libraries/lvgl/src/extra/others/gridnav
        Libraries/lvgl/src/extra/others/ime
        Libraries/lvgl/src/extra/others/imgfont
        Libraries/lvgl/src/extra/others/monkey
        Libraries/lvgl/src/extra/others/msg
        Libraries/lvgl/src/extra/others/snapshot
        Libraries/lvgl/src/extra/themes
        Libraries/lvgl/src/extra/themes/basic
        Libraries/lvgl/src/extra/themes/default
        Libraries/lvgl/src/extra/themes/mono
        Libraries/lvgl/src/extra/widgets
        Libraries/lvgl/src/extra/widgets/animimg
        Libraries/lvgl/src/extra/widgets/calendar
        Libraries/lvgl/src/extra/widgets/chart
        Libraries/lvgl/src/extra/widgets/colorwheel
        Libraries/lvgl/src/extra/widgets/imgbtn
        Libraries/lvgl/src/extra/widgets/keyboard
        Libraries/lvgl/src/extra/widgets/led
        Libraries/lvgl/src/extra/widgets/list
        Libraries/lvgl/src/extra/widgets/menu
        Libraries/lvgl/src/extra/widgets/meter
        Libraries/lvgl/src/extra/widgets/msgbox
        Libraries/lvgl/src/extra/widgets/span
        Libraries/lvgl/src/extra/widgets/spinbox
        Libraries/lvgl/src/extra/widgets/spinner
        Libraries/lvgl/src/extra/widgets/tabview
        Libraries/lvgl/src/extra/widgets/tileview
        Libraries/lvgl/src/extra/widgets/win
        Libraries/lvgl/src/font
        Libraries/lvgl/src/hal
        Libraries/lvgl/src/misc
        Libraries/lvgl/src/widgets
        Libraries/PikaScript/pikascript-api
        Libraries/PikaScript/pikascript-core
        Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS
        Middlewares/Third_Party/FreeRTOS/Source/include
        Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F
        ZeptoWatch
        ZeptoWatch/Drivers
        ZeptoWatch/Drivers/cst816
        ZeptoWatch/Drivers/gc9a01
        ZeptoWatch/Drivers/mpu6050
        ZeptoWatch/Drivers/mpu6050/eMPL
        ZeptoWatch/Tasks
        ZeptoWatch/UI
        ZeptoWatch/Utils
)

add_definitions(-DUSE_HAL_DRIVER -DSTM32F405xx)

file(GLOB_RECURSE SOURCES
        "Core/*.*"
        "Drivers/*.*"
        "Libraries/lvgl/*.*"
        "Libraries/PikaScript/*.c"
        "Libraries/PikaScript/*.h"
        "Middlewares/*.*"
        "startup/*.*"
        "ZeptoWatch/*.*"
)

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F405RGTx_FLASH.ld)

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_link_options(-T ${LINKER_SCRIPT})

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE}
Building ${BIN_FILE}")
