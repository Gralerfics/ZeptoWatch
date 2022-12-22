###ICON=clock;NAME=ClockSettings;COLOR=16751415;###

import pika_lvgl as lv
import ZeptoWatchStdLib as zws

def get_options(tot, cur):
    return str((cur + tot - 2) % tot) + '\n' + str((cur + tot - 1) % tot) + '\n' + str(cur) + '\n' + str((cur + 1) % tot) + '\n' + str((cur + 2) % tot)

def get_init_val(i):
    if i == 0:
        return zws.Clock.getHours()
    elif i == 1:
        return zws.Clock.getMinutes()
    else:
        return zws.Clock.getSeconds()

def rol_cb(e):
    code = e.get_code()
    if code == lv.EVENT.VALUE_CHANGED:
        target = e.get_target()
        idx = int(target.get_id())
        cur_val = int(rolList[idx].get_selected_str())
        rolList[idx].set_options(get_options(24 + (idx != 0) * 36, cur_val), 0)
        rolList[idx].set_selected(2, lv.ANIM.OFF)

def btn_cb(e):
    code = e.get_code()
    if code == lv.EVENT.CLICKED:
        h = int(rolList[0].get_selected_str())
        m = int(rolList[1].get_selected_str())
        s = int(rolList[2].get_selected_str())
        zws.Clock.setTime(h, m, s)
        btnlb.set_text('Modified')

title = lv.label(zws.Display.getField())
title.set_align(lv.ALIGN.CENTER)
title.set_x(0)
title.set_y(-86)
title.set_text("Time Settings")

rolList = []
for i in range(3):
    rolList.append(lv.roller(zws.Display.getField()))
    rolList[i].set_id(str(i))
    rolList[i].set_align(lv.ALIGN.CENTER)
    rolList[i].set_size(52, 85)
    rolList[i].set_x(i * 58 - 58)
    rolList[i].set_y(-10)
    rolList[i].set_options(get_options(24 + (i != 0) * 36, get_init_val(i)), 0)
    rolList[i].set_selected(2, lv.ANIM.OFF)
    rolList[i].add_event_cb(rol_cb, lv.EVENT.VALUE_CHANGED, 0)

btnc = lv.btn(zws.Display.getField())
btnc.set_align(lv.ALIGN.CENTER)
btnc.set_size(72, 36)
btnc.set_y(65)
btnc.add_event_cb(btn_cb, lv.EVENT.CLICKED, 0)

btnlb = lv.label(zws.Display.getField())
btnlb.set_align(lv.ALIGN.CENTER)
btnlb.set_y(65)
btnlb.set_text('Confirm')

while 1 == 1:
    zws.System.delayMs(5)

###END###