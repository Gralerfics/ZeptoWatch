#include "cmsis_os.h"

#include "stdio.h"

#include "tim.h"
#include "brightness.h"
#include "battery.h"
#include "UI/ui.h"

#ifdef __cplusplus /* 为了在 .cpp 中覆写 .c 中的 __weak 函数需要在 extern "C" 中声明, 方能被 .c 文件索引到. */
extern "C" {
#endif

void StartSystemDetecting(void const * argument) {
	Brightness_SetTIMHandle(&htim3);
	Brightness_SetTIMChannel(TIM_CHANNEL_1);
	Brightness_Start();
	Brightness_SetValue(60);

	Battery_Init();

	char txt[10];
	while (1) {
//		sprintf(txt, "%d, %d", Battery_GetPowerPercentage(), Battery_IsCharging());
		sprintf(txt, "%d, %d", Battery_GetADCData(), Battery_IsCharging());
		lv_label_set_text(ui_Screen1_Label1, txt);
		osDelay(500);
	}
}

#ifdef __cplusplus
}
#endif
