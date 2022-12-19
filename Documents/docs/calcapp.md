# Comments for Calculator Example

---

```python
###ICON=calc;NAME=Calculator;COLOR=13726207;###

import pika_lvgl as lv
import ZeptoWatchStdLib as zws

instr = ''
sym = ''
a = 0
b = 0

lb = lv.label(zws.Display.getField())
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
    btnList.append(lv.btn(zws.Display.getField()))
    btnList[i].set_id(str(i))
    btnList[i].set_align(lv.ALIGN.CENTER)
    btnList[i].set_size(32, 32)
    btnList[i].set_x((i % 4) * 40 - 60)
    btnList[i].set_y(int(i / 4) * 40 - 45)
    btnList[i].add_event_cb(event_cb_btns, lv.EVENT.CLICKED, 0)

    lbList.append(lv.label(zws.Display.getField()))
    lbList[i].set_align(lv.ALIGN.CENTER)
    lbList[i].set_x((i % 4) * 40 - 60)
    lbList[i].set_y(int(i / 4) * 40 - 45)
    lbList[i].set_text(btnCode[i])

while 1 == 1:
    zws.System.delayMs(5)

###END###
```

1. 首先程序开头和结尾的的注释：

```python
###ICON=calc;NAME=Calculator;COLOR=13726207;###
...
###END###
```

- 首先开头的注释包含应用信息。

  - **参数**：
  `ICON`指定图标，目前可选`scripts (默认)`、`timer`、`calc`、`canlendar`、`settings`、`info`、`clock`、`check`、`notes`；
  `NAME`指定应用名称，默认为文件路径；
  `COLOR`指定应用图标颜色，十进制，转换为十六进制后有六位，每两位分别代表`RGB (0 - 255)`值。 
  例如：上例中`13726207`为十六进制`0xD171FF`，`D1`为`209`代表红色值，依此类推。用 Windows 自带计算器的程序员模式看就行。

  - **要求**：
开头三个井号是必须的，结束至少一个井号，写三个对称好看点；
内部每个参数用分号隔开，顺序可以变动，最后一个参数结束也要加分号；
参数名和参数值用一个等号连接；
参数名要大写；参数值长度不超过`30`；
非法参数名会被忽略，但长度不要超过`8`；
未成功赋值的参数将使用默认值`ICON=scripts;NAME=[文件名];COLOR=16751415`。
当然，因为解析部分的逻辑很简单粗暴，按照示例的格式来是最稳的。

- 结尾的注释最好加上，先前读取程序时末尾有非法字符，暂时的解决方案就是检测`#END#`然后把后面的内容都忽略掉。

2. 接下来是导入所需的包：
```python
import pika_lvgl as lv
import ZeptoWatchStdLib as zws
```

这里用到了 UI 组件所以导入`pika_lvgl`包，便于使用起别名为`lv`；同样地，因为用到了`delayMs()`和`getField()`等，也要导入`ZeptoWatchStdLib`包，起别名为`zws`。

虽然其实初始化时几个包都导入了，不过为了完整性还是规范些写。

3. 下面先说主循环：
```python
while 1 == 1:
    zws.System.delayMs(5)
```

主循环中如果不想阻塞系统其它任务请调用`zws.System.delayMs()`。该函数背后是`FreeRTOS`的`osDelay`，在延时中会由`RTOS`调度执行系统其他任务，比如绘制 UI、亮度和电量同步等。

缺点就是最小时间单位长达一毫秒——但如果不调用就会阻塞，UI 不会更新，系统也会卡死，因为触摸检测之类都被阻塞了，进了死循环。当然，`ZeptoWatchStdLib`也提供了一个`.Display.lvglUpdate()`方法，用于手动触发`lvgl`任务处理，可以使 UI 更新和触摸继续工作，但亮度和电量检测之类还是罢工，晚些都把手动的接口添加上，再加个配套的微秒级阻塞延时。

4. 然后以创建一个 Label 为例看下 UI 组件的配置：
```python
lb = lv.label(zws.Display.getField())
lb.set_align(lv.ALIGN.CENTER)
lb.set_width(140)
lb.set_y(-80)
```

这里是用构造方法`lv.label()`创建了一个`label`对象，参数是其父对象。UI 界面是一个树形结构，组件可以一级套一级，所以要传入它的父对象。

这里使用`zws.Display.getField()`获取应用界面的根对象(源代码中看就是`ui_Appfield`)。`lvgl`还提供了一个`lv.scr_act()`方法用于获取当前活动中的屏幕，不使用而专门封装一个`getField()`是为了防止例如应用界面加载时拉下下拉菜单导致组件画到下拉菜单上这种情况出现，所以尽量使用`getField()`。

然后创建后把对象保存到`lb`变量，之后对其进行操作即可。下面使用的都是`lv_obj`的成员方法，具体可以见`api.md`和`pika_lvgl.pyi`。

`lb.set_align`设置对齐方式，设为`lv.ALIGN.CENTER`的直观表现就是坐标系的原点`(0, 0)`之后就被定位在了屏幕正中。

设置居中对齐后，`lb.set_y(-80)`就把标签移动到比中心高`80px`的地方。横坐标默认为`0`。注：屏幕大小为`240x240px`。

`lb.set_width`设置宽度为`140px`，不设置也行，标签对象的默认宽度是适应内容宽度。

设置完后可以用`label`的成员方法设置标签的内容，例如`lb.set_text(str)`，`str`为字符串。

5. 可以看到`PikaScript`目前也支持`list`数据结构：
```python
btnCode = ['7', '8', '9', '+', '4', '5', '6', '-', '1', '2', '3', '*', '.', '0', '=', '/']
btnList = []
lbList = []
...
for i in range(16):
    btnList.append(lv.btn(zws.Display.getField()))
    btnList[i].set_id(str(i))
    btnList[i].set_align(lv.ALIGN.CENTER)
    btnList[i].set_size(32, 32)
    btnList[i].set_x((i % 4) * 40 - 60)
    btnList[i].set_y(int(i / 4) * 40 - 45)
    btnList[i].add_event_cb(event_cb_btns, lv.EVENT.CLICKED, 0)

    lbList.append(lv.label(zws.Display.getField()))
    lbList[i].set_align(lv.ALIGN.CENTER)
    lbList[i].set_x((i % 4) * 40 - 60)
    lbList[i].set_y(int(i / 4) * 40 - 45)
    lbList[i].set_text(btnCode[i])
```

前面的标签是计算器的输入和输出显示标签，被放在屏幕上端。这里则是`16`个按键阵列的生成。

首先定义好几个`list`，一个存放各个按键的标签字符串，一个存放十六个`btn`，一个存放十六个`label`对象。

下面`for`循环（可以看到`range`也支持），按钮和标签分别创建后添加至列表，然后进行设置，具体的和前面一样就不说了，看函数名字就能猜。

特别的是`btn`还用了一个`.add_event_cb`方法，用于绑定事件，见下。

6. 关于事件绑定：
```python
def event_cb_btns(e):
    code = e.get_code()
    if code == lv.EVENT.CLICKED:
        idx = int(e.get_target().get_id())
        ...

for i in range(16):
    btnList[i].set_id(str(i))
    ...
    btnList[i].add_event_cb(event_cb_btns, lv.EVENT.CLICKED, 0)

```

按钮点击之后需要处理，这时候就需要给按钮绑定点击事件。`add_event_cb`三个参数，第一个是回调函数的名字，第二个是事件类型，第三个是`user_data`。

回调函数前边定义了放进来就行。

事件类型参见文档`EVENT`，常用的就点击，也就是`lv.EVENT.CLICKED`。

`user_data`可以给回调函数传递数据，比如像上面十六个按钮共用一个回调函数，可以用这个参数来区分到底是哪个按钮被点击了。但是获取这个数据的接口他好像没封装，所以这种方法先不能用，就传个`0`进去空着。
替代的方法也就是上面用到的，给每个`btn`对象`set_id`设置一个`id`，在回调函数中查看点击对象的`id`来区分。

回调函数接受一个参数，假设叫`e`。这个`e`目前由两个方法，一个是`.get_code()`，可以获取触发的事件类型，每次要先判断一下是不是你要的事件，具体见上；另一个是`.get_target()`，返回触发事件的对象，比如你按了第七个按钮，就可以获取第七个按钮的对象引用，所以可以通过这个方法来获取按钮的`id`，区分是哪个按钮被点击了，具体见上。

上面实例中回调函数大半部分是混乱但能跑的计算器逻辑，涉及到按钮点击的部分就是上面截取出的部分。

7. 一些备注：

这是关于`Python`语法的，函数中获取全局变量记得`global`。

`Python`的`for`、`if`结构和其他的不太一样，注意一下。还有逻辑运算不是`&&`之类，而是`and`之类。

所有缩进都是四个空格为基础，而不是等缩进就行，这是`PikaScript`的要求。

---
