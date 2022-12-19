###ICON=check;NAME=UITest;COLOR=23751314;###
import PikaStdLib as std
import pika_lvgl as lv
import ZeptoWatchStdLib as zws
import ZeptoWatchPeriphLib as zwp

lb1 = lv.label(lv.scr_act())
btn1 = lv.btn(lv.scr_act())

def event_cb_1(evt):
    lb1.set_text('EVT 1.')
    print('EVT 1.')

btn1.align(lv.ALIGN.CENTER, 0, 10)
btn1.set_width(50)
btn1.set_height(50)
btn1.add_event_cb(event_cb_1, lv.EVENT.CLICKED, 0)
lb1.set_width(150)
lb1.align(lv.ALIGN.TOP_MID, 0, 40)
lb1.set_text('Test.')

while 1 == 1:
    zws.System.delayMs(5)

###END### 