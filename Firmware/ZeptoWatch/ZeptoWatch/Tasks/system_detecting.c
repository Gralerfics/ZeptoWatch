#include "cmsis_os.h"

#ifdef __cplusplus /* 为了在 .cpp 中覆写 .c 中的 __weak 函数需要在 extern "C" 中声明, 方能被 .c 文件索引到. */
extern "C" {
#endif

#include "common.h"

#include "lvgl.h"
#include "ui.h"

#include "fshelper.h"

#include "mpu6050.h"
#include "msm261s.h"
#include "vibrator.h"

lv_chart_series_t *series = NULL;

void StartSystemDetecting(void const * argument) {
	while (1) {

		osDelay(1);
	}
}

#ifdef __cplusplus
}
#endif
