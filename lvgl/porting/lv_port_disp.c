#include "lv_port_disp.h"

#include "common.h"
#include "gc9a01.h"

#define MY_DISP_HOR_RES 240
#define MY_DISP_VER_RES 240
#define BUFFER_ROWS 60
#define SINGLE_BUFFERING
#define DIRECT_SWAP_MODE

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_port_disp_init(void) {
	/* 初始化显示设备 */
    disp_init();

    /* 注册显示设备 */
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);

    /* 分辨率设置 */
    disp_drv.hor_res = MY_DISP_HOR_RES;
    disp_drv.ver_res = MY_DISP_VER_RES;

    /* 注册刷新函数 */
    disp_drv.flush_cb = disp_flush;

    /* 设置显示缓存 */
	static lv_disp_draw_buf_t draw_buf_dsc;
#ifdef SINGLE_BUFFERING
		/* 单缓冲 */
		static lv_color_t buf_1[MY_DISP_HOR_RES * BUFFER_ROWS];
		lv_disp_draw_buf_init(&draw_buf_dsc, buf_1, NULL, MY_DISP_HOR_RES * BUFFER_ROWS);
#endif
#ifdef DOUBLE_BUFFERING
		/* 双缓冲 */
		static lv_color_t buf_1[MY_DISP_HOR_RES * BUFFER_ROWS];
		static lv_color_t buf_2[MY_DISP_HOR_RES * BUFFER_ROWS];
		lv_disp_draw_buf_init(&draw_buf_dsc, buf_1, buf_2, MY_DISP_HOR_RES * BUFFER_ROWS);
#endif
#ifdef FULL_BUFFFERING
		/* 全屏缓冲 */
		static lv_color_t buf_1[MY_DISP_HOR_RES * MY_DISP_VER_RES];
		static lv_color_t buf_2[MY_DISP_HOR_RES * MY_DISP_VER_RES];
		lv_disp_draw_buf_init(&draw_buf_dsc, buf_1, buf_2, MY_DISP_VER_RES * LV_VER_RES_MAX);
		disp_drv.full_refresh = 1; // 全屏缓冲需要设置该量
#endif
    disp_drv.draw_buf = &draw_buf_dsc;

    /* 注册设备 */
    lv_disp_drv_register(&disp_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
/* 初始化显示设备接口 */
static void disp_init(void) {
	GC9A01_GPIO_Init();
	GC9A01_Init();
}

/* 屏幕刷新 */
volatile bool disp_flush_enabled = true;

void disp_enable_update(void) { disp_flush_enabled = true; }

void disp_disable_update(void) { disp_flush_enabled = false; }

static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p) {
    if (disp_flush_enabled) {
#ifdef DIRECT_SWAP_MODE
		/* 如果直接 DMA color_p, lv_conf.h 里面 LV_COLOR_16_SWAP 要设为 1.
		 * 同时如果使用 Squareline Studio 要在新建工程时选择 16bit swap 模式. */
		GC9A01_Fill(area -> x1, area -> y1, area -> x2, area -> y2, (uint16_t *) color_p);
#else
		/* 手动重排缓存 */
		uint8_t buf[(area -> y2) - (area -> y1) + 1][(area -> x2) - (area -> x1) + 1][2];
		for (int y = 0; y <= (area -> y2) - (area -> y1); y += 1) {
            for (int x = 0; x <= (area -> x2) - (area -> x1); x += 1) {
				buf[y][x][0] = (color_p -> full) >> 8;
				buf[y][x][1] = color_p -> full;
				color_p ++;
            }
        }
		GC9A01_Fill(area -> x1, area -> y1, area -> x2, area -> y2, (uint8_t *) buf);
#endif
    }
    lv_disp_flush_ready(disp_drv);
}
