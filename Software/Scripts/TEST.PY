###ICON=scripts;NAME=Test1;COLOR=16751415;###

import PikaStdLib as std
import ZeptoWatchStdLib as zws
import ZeptoWatchPeriphLib as zwp

zwp.IMU.initialize()

i = 5
j = 1
while 1 == 1:
    zws.Display.setBrightness(i)
    if i >= 95:
        j = -1
    if i <= 5:
        j = 1
    i = i + j

    k = zwp.IMU.getTemperature()
    print(k)

    zws.System.delayMs(30)

###END###