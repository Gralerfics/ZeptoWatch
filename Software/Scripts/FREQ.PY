###ICON=scripts;NAME=Freqs;COLOR=16251415;###

import PikaStdLib as std
import ZeptoWatchStdLib as zws
import ZeptoWatchPeriphLib as zwp
import arm_math_dsp as dsp
import pika_lvgl as lv

POINTS = dsp.FFT.LENGTH_32
HALF = POINTS / 2
MAX_VAL = 950000
MIN_VAL = 50000
SLI_NUM = 8

def getSliderValue(x):
    if x >= MAX_VAL:
        return 100
    elif x <= MIN_VAL:
        return 0
    else:
        return int(100 * (x - MIN_VAL) / (MAX_VAL - MIN_VAL))

st_main = lv.style_t()
st_main.set_radius(2)
st_main.set_bg_color(lv.lv_color_hex(0x292831))
st_main.set_bg_opa(255)

st_indic = lv.style_t()
st_indic.set_radius(2)
st_indic.set_bg_color(lv.lv_color_hex(0xE6E6E6))
st_indic.set_bg_opa(255)

st_knob = lv.style_t()
st_knob.set_bg_opa(0)

sliderList = []
for i in range(SLI_NUM):
    sliderList.append(lv.slider(zws.Display.getField()))
    sliderList[i].clear_flag(lv.flag_t.CLICKABLE)
    sliderList[i].add_style(st_main, lv.PART.MAIN | lv.STATE.DEFAULT)
    sliderList[i].add_style(st_indic, lv.PART.INDICATOR | lv.STATE.DEFAULT)
    sliderList[i].add_style(st_knob, lv.PART.KNOB | lv.STATE.DEFAULT)
    sliderList[i].set_align(lv.ALIGN.CENTER)
    sliderList[i].set_size(18, 120)
    sliderList[i].set_pos(20 * i - 70, 0)

zwp.Microphone.startSampling()

curList = []
for i in range(POINTS):
    curList.append(zwp.Microphone.getRawData())
hamm = dsp.Hamming.getFactors(POINTS)

while 1 == 1:
    hamedList = list(curList)
    for i in range(POINTS):
        hamedList[i] = curList[i] * hamm[i]

    fList = dsp.FFT.rfft(hamedList, POINTS)
    mList = dsp.Complex.mag(fList, HALF)
    mList[0] /= 2

    for j in range(SLI_NUM):
        i = j * int(HALF / SLI_NUM)
        print(getSliderValue(mList[i] / HALF))
        sliderList[j].set_value(getSliderValue(mList[i] / HALF), lv.ANIM.ON)
        zws.System.delayMs(10)

    for i in range(POINTS):
        curList[i] = zwp.Microphone.getRawData()

    # print(std.MemChecker.now())
    # zws.System.delayMs(100)

###END###