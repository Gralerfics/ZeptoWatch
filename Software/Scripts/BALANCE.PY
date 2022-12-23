###ICON=scripts;NAME=Balance;COLOR=3801017;###

import ZeptoWatchStdLib as zws
import ZeptoWatchPeriphLib as zwp
import pika_lvgl as lv

lb = lv.label(zws.Display.getField())
lb.set_text("(°v °;)")
lb.set_align(lv.ALIGN.CENTER)

v_x = 0
v_y = 0
p_x = 0
p_y = 0
dt = 0.001
scale = 1500
eta = 0.85

zwp.IMU.initialize()
while 1 == 1:
    acce = zwp.IMU.getAccelerometer()
    a_x = acce[1] / 32768 * 9.83 * 2
    a_y = -acce[0] / 32768 * 9.83 * 2
    p_x += v_x * dt * scale
    p_y += v_y * dt * scale
    v_x += a_x * dt * scale
    v_y += a_y * dt * scale
    lb.set_pos(int(p_x), int(p_y))

    if p_x * p_x + p_y * p_y >= 14400 and p_x * v_x + p_y * v_y >= 0:
        n_x = p_y / 120
        n_y = -p_x / 120
        v_dot_n = v_x * n_x + v_y * n_y
        v_x = (2 * v_dot_n * n_x - v_x) * eta
        v_y = (2 * v_dot_n * n_y - v_y) * eta

    zws.System.delayMs(1)

###END###