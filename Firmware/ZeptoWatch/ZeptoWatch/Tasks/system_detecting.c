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

lv_chart_series_t *series = NULL;

void StartSystemDetecting(void const * argument) {
	char names[300] = {0};
	FS_ScanFolder("0:", names);
	lv_roller_set_options(ui_roller, names, LV_ROLLER_MODE_NORMAL);

//	lv_chart_set_type(ui_chart, LV_CHART_TYPE_LINE);
//	lv_chart_set_point_count(ui_chart, 30);
//	lv_chart_set_range(ui_chart, LV_CHART_AXIS_PRIMARY_Y, -16500, 16500);
//	lv_chart_set_range(ui_chart, LV_CHART_AXIS_SECONDARY_Y, -16500, 16500);
//	lv_chart_series_t *series_1 = lv_chart_add_series(ui_chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
//	lv_chart_series_t *series_2 = lv_chart_add_series(ui_chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_SECONDARY_Y);

	lv_chart_set_type(ui_chart, LV_CHART_TYPE_LINE);
	lv_chart_set_point_count(ui_chart, 8192);
	lv_chart_set_range(ui_chart, LV_CHART_AXIS_PRIMARY_Y, -32768, 32767);
	series = lv_chart_add_series(ui_chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);

	while (1) {
//		short ax, ay, az;
//		MPU_Get_Accelerometer(&ax, &ay, &az);
//		lv_chart_set_next_value(ui_chart, series_1, ax);
//		lv_chart_set_next_value(ui_chart, series_2, ay);

//		int data = Microphone_GetSampleData();
//		lv_chart_set_next_value(ui_chart, series, data / 10);

		osDelay(1);
	}
}

#ifdef __cplusplus
}
#endif
