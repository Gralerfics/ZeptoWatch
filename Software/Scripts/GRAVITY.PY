###ICON=scripts;NAME=Gravity;COLOR=16727076;###

import ZeptoWatchStdLib as zws
import ZeptoWatchPeriphLib as zwp
import pika_lvgl as lv

total = 5
dt = 0.001
scale = 2500
eta = 0.85

lb = []
v_x = []
v_y = []
p_x = []
p_y = []

for i in range(total):
    lb.append(lv.label(zws.Display.getField()))
    lb[i].set_text("(°v °;)")
    lb[i].set_align(lv.ALIGN.CENTER)
    v_x.append(i * 3 - 6)
    v_y.append(3)
    p_x.append(i * 30 - 60)
    p_y.append(i * 30 - 60)

zwp.IMU.initialize()
while 1 == 1:
    acce = zwp.IMU.getAccelerometer()
    a_x = acce[1] / 32768 * 9.83 * 2
    a_y = -acce[0] / 32768 * 9.83 * 2

    for i in range(total):
        p_x[i] += v_x[i] * dt * scale
        p_y[i] += v_y[i] * dt * scale
        v_x[i] += a_x * dt * scale
        v_y[i] += a_y * dt * scale
        lb[i].set_pos(int(p_x[i]), int(p_y[i]))

        if p_x[i] * p_x[i] + p_y[i] * p_y[i] >= 14400 and p_x[i] * v_x[i] + p_y[i] * v_y[i] >= 0:
            n_x = p_y[i] / 120
            n_y = -p_x[i] / 120
            v_dot_n = v_x[i] * n_x + v_y[i] * n_y
            v_x[i] = (2 * v_dot_n * n_x - v_x[i]) * eta
            v_y[i] = (2 * v_dot_n * n_y - v_y[i]) * eta

    zws.System.delayMs(1)

###END###