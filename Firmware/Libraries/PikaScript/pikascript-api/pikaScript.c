/*
 * [Warning!] This file is auto-generated by pika compiler.
 * Do not edit it manually.
 * The source code is *.pyi file.
 * More details: 
 * English Doc:
 * https://pikadoc.readthedocs.io/en/latest/PikaScript%20%E6%A8%A1%E5%9D%97%E6%A6%82%E8%BF%B0.html
 * Chinese Doc:
 * https://pikadoc.readthedocs.io/zh/latest/PikaScript%20%E6%A8%A1%E5%9D%97%E6%A6%82%E8%BF%B0.html
 */

#include "PikaMain.h"
#include <stdio.h>
#include <stdlib.h>

volatile PikaObj *__pikaMain;
PikaObj *pikaScriptInit(void){
    __platform_printf("======[pikascript packages installed]======\r\n");
    pks_printVersion();
    __platform_printf("PikaStdLib==v1.11.7\r\n");
    __platform_printf("===========================================\r\n");
    PikaObj* pikaMain = newRootObj("pikaMain", New_PikaMain);
    __pikaMain = pikaMain;
    extern unsigned char pikaModules_py_a[];
    obj_linkLibrary(pikaMain, pikaModules_py_a);
#if PIKA_INIT_STRING_ENABLE
    obj_run(pikaMain,
            "import PikaStdLib\n"
            "print('hello PikaScript!')\n"
            "\n");
#else 
    obj_runModule((PikaObj*)pikaMain, "main");
#endif
    return pikaMain;
}

