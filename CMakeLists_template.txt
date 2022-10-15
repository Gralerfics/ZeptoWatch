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
        lvgl
        lvgl/porting
        lvgl/src
        lvgl/src/core
        lvgl/src/draw
        lvgl/src/draw/arm2d
        lvgl/src/draw/nxp
        lvgl/src/draw/nxp/pxp
        lvgl/src/draw/nxp/vglite
        lvgl/src/draw/sdl
        lvgl/src/draw/stm32_dma2d
        lvgl/src/draw/sw
        lvgl/src/draw/swm341_dma2d
        lvgl/src/extra
        lvgl/src/extra/layouts
        lvgl/src/extra/layouts/flex
        lvgl/src/extra/layouts/grid
        lvgl/src/extra/libs
        lvgl/src/extra/libs/bmp
        lvgl/src/extra/libs/ffmpeg
        lvgl/src/extra/libs/freetype
        lvgl/src/extra/libs/fsdrv
        lvgl/src/extra/libs/gif
        lvgl/src/extra/libs/png
        lvgl/src/extra/libs/qrcode
        lvgl/src/extra/libs/rlottie
        lvgl/src/extra/libs/sjpg
        lvgl/src/extra/others
        lvgl/src/extra/others/fragment
        lvgl/src/extra/others/gridnav
        lvgl/src/extra/others/ime
        lvgl/src/extra/others/imgfont
        lvgl/src/extra/others/monkey
        lvgl/src/extra/others/msg
        lvgl/src/extra/others/snapshot
        lvgl/src/extra/themes
        lvgl/src/extra/themes/basic
        lvgl/src/extra/themes/default
        lvgl/src/extra/themes/mono
        lvgl/src/extra/widgets
        lvgl/src/extra/widgets/animimg
        lvgl/src/extra/widgets/calendar
        lvgl/src/extra/widgets/chart
        lvgl/src/extra/widgets/colorwheel
        lvgl/src/extra/widgets/imgbtn
        lvgl/src/extra/widgets/keyboard
        lvgl/src/extra/widgets/led
        lvgl/src/extra/widgets/list
        lvgl/src/extra/widgets/menu
        lvgl/src/extra/widgets/meter
        lvgl/src/extra/widgets/msgbox
        lvgl/src/extra/widgets/span
        lvgl/src/extra/widgets/spinbox
        lvgl/src/extra/widgets/spinner
        lvgl/src/extra/widgets/tabview
        lvgl/src/extra/widgets/tileview
        lvgl/src/extra/widgets/win
        lvgl/src/font
        lvgl/src/hal
        lvgl/src/misc
        lvgl/src/widgets
        Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS
        Middlewares/Third_Party/FreeRTOS/Source/include
        Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F
        UserApp
        UserApp/Apps
        UserApp/Drivers
        UserApp/UI
        UserApp/Utils
)

add_definitions(-DUSE_HAL_DRIVER -DSTM32F405xx)

file(GLOB_RECURSE SOURCES
        "Core/*.*"
        "Drivers/*.*"
        "lvgl/*.*"
        "Middlewares/*.*"
        "startup/*.*"
        "UserApp/*.*"
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
