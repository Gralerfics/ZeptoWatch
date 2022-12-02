#include "lv_port_indev.h"

#include "cst816.h"

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void touchpad_init(void);
static void touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
static bool touchpad_is_pressed(void);
static void touchpad_get_xy(lv_coord_t *x, lv_coord_t *y);

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t *indev_touchpad;

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_port_indev_init(void) {
    /* 硬件初始化输入设备 */
    touchpad_init();

	/* 注册输入设备 */
	static lv_indev_drv_t indev_touchpad_drv;
	lv_indev_drv_init(&indev_touchpad_drv);
	indev_touchpad_drv.type = LV_INDEV_TYPE_POINTER;
	indev_touchpad_drv.read_cb = touchpad_read;
	indev_touchpad = lv_indev_drv_register(&indev_touchpad_drv);

    /* Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
     * add objects to the group with `lv_group_add_obj(group, obj)`
     * and assign this input device to group to navigate in it:
     * `lv_indev_set_group(indev_encoder, group);` */
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void touchpad_init(void) {
	CST816_GPIO_Init();
}

static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data) {
    static lv_coord_t last_x = 0, last_y = 0;

	CST816_Get_Axis();
	if (touchpad_is_pressed()) {
		touchpad_get_xy(&last_x, &last_y);
		data -> state = LV_INDEV_STATE_PR;
	} else {
		data -> state = LV_INDEV_STATE_REL;
	}

	/* Set the last pressed coordinates */
	data -> point.x = last_x;
	data -> point.y = last_y;
}

static bool touchpad_is_pressed(void) {
	CST816_Pen_Flag = CST816_I2C_ReadReg(FingerNum);
	return CST816_Pen_Flag == 1;
}

static void touchpad_get_xy(lv_coord_t *x, lv_coord_t *y) {
	/* 显示方向朝右 */
	(*x) = CST816_Instance.Y_Pos;
	(*y) = 240 - CST816_Instance.X_Pos;

	/* 显示方向朝下 */
//	(*x) = 240 - CST816_Instance.Y_Pos;
//	(*y) = 240 - CST816_Instance.X_Pos;

	/* 显示方向朝左 */
//	(*x) = 240 - CST816_Instance.Y_Pos;
//	(*y) = CST816_Instance.X_Pos;

	/* 显示方向朝上 */
//	(*x) = CST816_Instance.X_Pos;
//	(*y) = CST816_Instance.Y_Pos;
}
