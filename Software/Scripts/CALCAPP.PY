###ICON=calc;NAME=Calculator;COLOR=13726207;###
import PikaStdLib as std
import pika_lvgl as lv
import ZeptoWatchStdLib as zws
import ZeptoWatchPeriphLib as zwp

instr = ''
sym = ''
a = 0
b = 0

lb = lv.label(lv.scr_act())
lb.set_align(lv.ALIGN.CENTER)
lb.set_width(140)
lb.set_y(-80)
lb.set_text(instr)

btnCode = ['7', '8', '9', '+', '4', '5', '6', '-', '1', '2', '3', '*', '.', '0', '=', '/']
btnList = []
lbList = []

def event_cb_btns(e):
    code = e.get_code()
    if code == lv.EVENT.CLICKED:
        global instr, sym, a, b
        idx = int(e.get_target().get_id())
        if btnCode[idx] == '=':
            if instr == '':
                b = 0
            else:
                b = float(instr)
            res = ''
            if sym == '+':
                res = str(a + b)
            elif sym == '-':
                res = str(a - b)
            elif sym == '*':
                res = str(a * b)
            elif sym == '/':
                if b == 0:
                    res = 'Math Error!'
                else:
                    res = str(a / b)
            else:
                res = str(b)
            lb.set_text(res)
            a = float(res)
            sym = '='
            instr = ''
        elif btnCode[idx] == '+' or btnCode[idx] == '-' or btnCode[idx] == '*' or btnCode[idx] == '/':
            if sym == '':
                if instr == '':
                    a = 0
                else:
                    a = float(instr)
            sym = btnCode[idx]
            instr = ''
            lb.set_text(sym)
        else:
            if sym == '=':
                sym = ''
            instr += btnCode[idx]
            lb.set_text(instr)

for i in range(16):
    btnList.append(lv.btn(lv.scr_act()))
    btnList[i].set_id(str(i))
    btnList[i].set_align(lv.ALIGN.CENTER)
    btnList[i].set_size(32, 32)
    btnList[i].set_x((i % 4) * 40 - 60)
    btnList[i].set_y(int(i / 4) * 40 - 45)
    btnList[i].add_event_cb(event_cb_btns, lv.EVENT.CLICKED, 0)

    lbList.append(lv.label(lv.scr_act()))
    lbList[i].set_align(lv.ALIGN.CENTER)
    lbList[i].set_x((i % 4) * 40 - 60)
    lbList[i].set_y(int(i / 4) * 40 - 45)
    lbList[i].set_text(btnCode[i])

while 1 == 1:
    zws.System.delayMs(5)

###END###