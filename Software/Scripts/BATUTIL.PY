###ICON=check;NAME=BatteryTest;COLOR=4700671;###

import pika_lvgl as lv
import ZeptoWatchStdLib as zws
import ZeptoWatchPeriphLib as zwp

lb = lv.label(zws.Display.getField())
lb.set_align(lv.ALIGN.CENTER)

while 1 == 1:
    isc = zwp.Battery.isCharging()
    adc = zwp.Battery.getRawData()
    lb.set_text(str(isc) + ' ' + str(adc))

    zws.System.delayMs(10)

###END###