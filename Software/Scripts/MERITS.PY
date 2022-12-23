###ICON=merits;NAME=Merits;COLOR=16751415;###

import pika_lvgl as lv
import ZeptoWatchStdLib as zws
import ZeptoWatchPeriphLib as zwp
import ZeptoWatchAssets as assets

merits_acc = 0

img = lv.img(zws.Display.getField())
img.set_align(lv.ALIGN.CENTER)
img.set_pos(-5, -2)
img.set_zoom(225)
img.set_src(assets.Imgs.WOODENF)

lb = lv.label(zws.Display.getField())
lb.set_align(lv.ALIGN.CENTER)
lb.set_y(80)
lb.set_text('Knock')

stlb = lv.style_t()
stlb.set_text_font(lv.FONT.MONTSERRAT_16)
lb.add_style(stlb, 0)

def btn_event_cb(e):
    global merits_acc
    merits_acc += 1
    lb.set_text('Merits: ' + str(merits_acc))
    zwp.Vibrator.vibrate(2, 70)
    zwp.Vibrator.vibrate(6, 80)
    zwp.Vibrator.vibrate(10, 90)
    zwp.Vibrator.vibrate(6, 80)
    zwp.Vibrator.vibrate(2, 70)

btn = lv.btn(zws.Display.getField())
btn.set_align(lv.ALIGN.CENTER)
btn.set_pos(-5, -2)
btn.set_size(131, 99)
btn.add_event_cb(btn_event_cb, lv.EVENT.CLICKED, 0)

stbtn = lv.style_t()
stbtn.set_bg_opa(0)
btn.add_style(stbtn, 0)

while 1 == 1:
    zws.System.delayMs(5)

###END###