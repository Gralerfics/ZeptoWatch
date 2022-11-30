# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

# compile ASM with D:/Environments/Embedded/GNU_Tools_ARM_Embedded/bin/arm-none-eabi-gcc.exe
# compile C with D:/Environments/Embedded/GNU_Tools_ARM_Embedded/bin/arm-none-eabi-gcc.exe
# compile CXX with D:/Environments/Embedded/GNU_Tools_ARM_Embedded/bin/arm-none-eabi-g++.exe
ASM_DEFINES = -DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -DSTM32F405xx -DUSE_HAL_DRIVER

ASM_INCLUDES = -IC:\Workplace\ZeptoWatch\Firmware -IC:\Workplace\ZeptoWatch\Firmware\Core\Inc -IC:\Workplace\ZeptoWatch\Firmware\Drivers\STM32F4xx_HAL_Driver\Inc -IC:\Workplace\ZeptoWatch\Firmware\Drivers\STM32F4xx_HAL_Driver\Inc\Legacy -IC:\Workplace\ZeptoWatch\Firmware\Drivers\CMSIS\Device\ST\STM32F4xx\Include -IC:\Workplace\ZeptoWatch\Firmware\Drivers\CMSIS\Include -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\porting -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\core -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\arm2d -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\nxp -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\nxp\pxp -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\nxp\vglite -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\sdl -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\stm32_dma2d -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\sw -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\swm341_dma2d -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\layouts -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\layouts\flex -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\layouts\grid -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\bmp -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\ffmpeg -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\freetype -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\fsdrv -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\gif -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\png -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\qrcode -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\rlottie -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\sjpg -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\fragment -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\gridnav -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\ime -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\imgfont -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\monkey -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\msg -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\snapshot -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\themes -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\themes\basic -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\themes\default -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\themes\mono -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\animimg -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\calendar -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\chart -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\colorwheel -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\imgbtn -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\keyboard -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\led -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\list -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\menu -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\meter -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\msgbox -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\span -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\spinbox -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\spinner -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\tabview -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\tileview -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\win -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\font -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\hal -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\misc -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\widgets -IC:\Workplace\ZeptoWatch\Firmware\Libraries\PikaScript\pikascript-api -IC:\Workplace\ZeptoWatch\Firmware\Libraries\PikaScript\pikascript-core -IC:\Workplace\ZeptoWatch\Firmware\Middlewares\Third_Party\FreeRTOS\Source\CMSIS_RTOS -IC:\Workplace\ZeptoWatch\Firmware\Middlewares\Third_Party\FreeRTOS\Source\include -IC:\Workplace\ZeptoWatch\Firmware\Middlewares\Third_Party\FreeRTOS\Source\portable\GCC\ARM_CM4F -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers\cst816 -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers\gc9a01 -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers\mpu6050 -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers\mpu6050\eMPL -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Tasks -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Utils

ASM_FLAGS = -g -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -mthumb -mthumb-interwork -ffunction-sections -fdata-sections -fno-common -fmessage-length=0 -x assembler-with-cpp -O0

C_DEFINES = -DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -DSTM32F405xx -DUSE_HAL_DRIVER

C_INCLUDES = -IC:\Workplace\ZeptoWatch\Firmware -IC:\Workplace\ZeptoWatch\Firmware\Core\Inc -IC:\Workplace\ZeptoWatch\Firmware\Drivers\STM32F4xx_HAL_Driver\Inc -IC:\Workplace\ZeptoWatch\Firmware\Drivers\STM32F4xx_HAL_Driver\Inc\Legacy -IC:\Workplace\ZeptoWatch\Firmware\Drivers\CMSIS\Device\ST\STM32F4xx\Include -IC:\Workplace\ZeptoWatch\Firmware\Drivers\CMSIS\Include -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\porting -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\core -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\arm2d -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\nxp -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\nxp\pxp -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\nxp\vglite -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\sdl -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\stm32_dma2d -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\sw -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\swm341_dma2d -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\layouts -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\layouts\flex -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\layouts\grid -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\bmp -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\ffmpeg -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\freetype -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\fsdrv -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\gif -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\png -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\qrcode -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\rlottie -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\sjpg -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\fragment -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\gridnav -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\ime -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\imgfont -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\monkey -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\msg -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\snapshot -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\themes -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\themes\basic -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\themes\default -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\themes\mono -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\animimg -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\calendar -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\chart -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\colorwheel -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\imgbtn -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\keyboard -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\led -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\list -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\menu -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\meter -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\msgbox -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\span -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\spinbox -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\spinner -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\tabview -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\tileview -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\win -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\font -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\hal -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\misc -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\widgets -IC:\Workplace\ZeptoWatch\Firmware\Libraries\PikaScript\pikascript-api -IC:\Workplace\ZeptoWatch\Firmware\Libraries\PikaScript\pikascript-core -IC:\Workplace\ZeptoWatch\Firmware\Middlewares\Third_Party\FreeRTOS\Source\CMSIS_RTOS -IC:\Workplace\ZeptoWatch\Firmware\Middlewares\Third_Party\FreeRTOS\Source\include -IC:\Workplace\ZeptoWatch\Firmware\Middlewares\Third_Party\FreeRTOS\Source\portable\GCC\ARM_CM4F -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers\cst816 -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers\gc9a01 -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers\mpu6050 -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers\mpu6050\eMPL -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Tasks -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Utils

C_FLAGS = -g -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -mthumb -mthumb-interwork -ffunction-sections -fdata-sections -fno-common -fmessage-length=0 -O0 -std=gnu11

CXX_DEFINES = -DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -DSTM32F405xx -DUSE_HAL_DRIVER

CXX_INCLUDES = -IC:\Workplace\ZeptoWatch\Firmware -IC:\Workplace\ZeptoWatch\Firmware\Core\Inc -IC:\Workplace\ZeptoWatch\Firmware\Drivers\STM32F4xx_HAL_Driver\Inc -IC:\Workplace\ZeptoWatch\Firmware\Drivers\STM32F4xx_HAL_Driver\Inc\Legacy -IC:\Workplace\ZeptoWatch\Firmware\Drivers\CMSIS\Device\ST\STM32F4xx\Include -IC:\Workplace\ZeptoWatch\Firmware\Drivers\CMSIS\Include -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\porting -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\core -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\arm2d -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\nxp -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\nxp\pxp -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\nxp\vglite -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\sdl -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\stm32_dma2d -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\sw -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\draw\swm341_dma2d -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\layouts -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\layouts\flex -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\layouts\grid -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\bmp -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\ffmpeg -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\freetype -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\fsdrv -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\gif -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\png -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\qrcode -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\rlottie -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\libs\sjpg -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\fragment -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\gridnav -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\ime -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\imgfont -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\monkey -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\msg -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\others\snapshot -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\themes -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\themes\basic -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\themes\default -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\themes\mono -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\animimg -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\calendar -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\chart -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\colorwheel -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\imgbtn -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\keyboard -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\led -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\list -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\menu -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\meter -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\msgbox -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\span -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\spinbox -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\spinner -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\tabview -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\tileview -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\extra\widgets\win -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\font -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\hal -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\misc -IC:\Workplace\ZeptoWatch\Firmware\Libraries\lvgl\src\widgets -IC:\Workplace\ZeptoWatch\Firmware\Libraries\PikaScript\pikascript-api -IC:\Workplace\ZeptoWatch\Firmware\Libraries\PikaScript\pikascript-core -IC:\Workplace\ZeptoWatch\Firmware\Middlewares\Third_Party\FreeRTOS\Source\CMSIS_RTOS -IC:\Workplace\ZeptoWatch\Firmware\Middlewares\Third_Party\FreeRTOS\Source\include -IC:\Workplace\ZeptoWatch\Firmware\Middlewares\Third_Party\FreeRTOS\Source\portable\GCC\ARM_CM4F -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers\cst816 -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers\gc9a01 -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers\mpu6050 -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Drivers\mpu6050\eMPL -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Tasks -IC:\Workplace\ZeptoWatch\Firmware\ZeptoWatch\Utils

CXX_FLAGS = -g -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -mthumb -mthumb-interwork -ffunction-sections -fdata-sections -fno-common -fmessage-length=0 -O0 -std=gnu++17

