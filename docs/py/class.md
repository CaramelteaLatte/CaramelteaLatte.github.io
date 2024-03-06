# Class.py

py 真的是一种很神奇的语言。。。我觉得它真的分不了点 TT，不过也有可能是老师的 PPT 做得太懒了

## 1 to start with

### 1.1 量

#### 1.1.1 关键字

- Python 区分大小写。True *not true*
- raise，is，as，expect，lambda，with，assert，finally，nonlocal，vield，class，from，global，pass
  
#### 1.1.2 id 函数

*python你真会说。。。。这就是地址*

- 赋值操作不改变实际赋值值，只是为数据对象去一个相关的名字。名字是对象的引用。
- id 函数返回对象的标识（一般是对象的地址）

```python
print(id(a))
a=7
print(id(7))
```
```
1566532000
1566532000
```

```python
a=5
print(a)
print(id(a))
print(id(5))
print(id(7))
```
```
5
1566531936
1566532000
```

### 1.2 IO

#### 1.2.1 input

- `input()` 读取到 str 类型
- 使用 `int(input())` 可以读取到 int 类型
- 使用 `input.split()` 可以读取到一连串的 str 类型，没有特殊说明就用空格隔开来输入
- 使用 `input.split(',')` 可以控制输入格式中使用 `,` 来分隔输入
- 使用 `input("请输入：").split()` 可以在输入前添上一行输入指示

#### 1.2.2 print

- `print(3,7,...)` 可以通过加逗号一次输出很多个数字，默认输出中间带空格且末尾带换行
- `print(a,b,...)` 可以输出变量的值
- 使用 end 参数控制输出格式，`print(3,end=' ')`

### 1.3

奇怪的画图啊？？？？

（我不仅没学turtle库也没载，，，，）

```python
import turtle
turtle.forward(200)
turtle.right(144)
turtle.forward(200)
turtle.right(144)
turtle.forward(200)
turtle.right(144)
turtle.forward(200)
turtle.right(144)
turtle.forward(200)
turtle.done()
```

### 1.4 calculation

#### 1.4.1 data

- py 允许的数据类型：整数，浮点数，复数
- 整数的表示方式
- 运算符
  - `/` 表示浮点数除法，`//` 表示整数除法
  - `**` 表示幂
- 浮点数的表示方式
  - 科学计数法，1.2e-5，e后面的值就是幂次方，必须为整数，e前后不能为空
  - 浮点数计算有误差，如 `2.1-2.0==0.1` False
  - 浮点数的整除还是浮点数，取余也是浮点数
- 复数：real 和 imaginary
  - 使用 `complex()` 函数来创建一个值为 `real + imag * J ` 的复数


#### 1.4.2 string

- 转义字符
  - `\n` 换行，`\t` 制表
  - `\ooo` 最多三位八进制，`\xyy` 最多两位十六进制
  - `\\` 表示 `\`, `\"` 表示 `"`

- 字符串运算符有 `+` 和 `*`。（非常好记字面理解
- `type()` 调用函数用来查询对象的的类型信息。`type(1)` 返回 `<class 'int'>`, `type("py")` 返回 `<class 'str'>`
- None（注意大小写
  - None 不是 0
  - `bool(None)` False, `None == 0` False

#### 1.4.3 Graph

- 列表
  - `empty_list = []` 空列表
  - `weekdays = ['Monday', 'Tuesday', 'Wednesday', 'Thurseday', 'Friday']` **注意下标从 0 开始**，weekday[2] 是 Wednesday
- 列表计算
  - 列表大小比较与字符串同理
  - 列表也可以加法，与字符串同理
  - 列表可以乘法初始化，与字符串同理

#### 1.4.4 内置转换函数

| 函数名 | 含义 | 举例 | 返回值 |
| -- | -- | -- | -- |
| bool | 根据传入参数创建布尔值 | `bool('str')` | True |
| int | ···整数 | `int(3.6)` | 3 |
| float | | `float(3)` | 3.0 |
| complex | | `complex(1, 2)` | (1+2j) |
| str | 创建一个字符串 | `str(123)` | '123' |
| ord | 返回 Unicode 字符对应的整数 | `ord('a')` | 97 |
| chr | 返回整数对应的 Unicode 字符| `chr(97)` | a |
| bin | 转化为二进制 | `bin(3)` | '0b11' |
| oct | | `oct(10)` | '0o12' |
| hex | | `hex(15)` | '0xf' |
| list | 根据传入的参数创建一个新的列表 | `list('abcd')` | ['a','b','c','d'] |

- `int`
  - `int("   35")` 去掉空格
  - `int("   3  5")` 无法转换
  - `int("35", 8)` 转换为八进制

#### 1.4.5 赋值

*我觉得python很神奇的地方*

- 交换值不需要设置容量 t
```python
print(a, b)
a, b = b, a
print(a, b)
```

### 1.5 语句

#### 1.5.1 条件

```python
if ...
    ......
else ...
    ......
```

#### 1.5.2 循环

```python
for variable in 列表:
  ......
```

**语句块缩进表示这个是for下的语句**

**`range()`：**
- range(start, stop, step)
- start 起始，默认从 0 开始。`range(5)` 表示 `range(0, 5)`
- stop 结束但不包括 stop，`range(1, 5)` 遍历了 1234
- step 默认 1

于是我们可以有：

```python
n = int(input())
fac = 1
for i in list(range(1, n+1)):
  fac *= i
print(fac)
```

#### 1.5.3 列表元素计算

`lst=[i for i in list(range(1,5))]` lst [1, 2, 3, 4]

`nl = [2*number for number in [1,2,3,4]]`  nl [1, 2, 3, 4] #列表推导式

`nl = [number for number in range(1,8) if nnumber % 2 == 1]` nl [1, 3, 5, 7]

#### 1.5.4 格式化输出

| 格式限定符 | 输出 | 说明 |
| -- | -- | -- |
| `"{:d}".format(24)` | 24 | 格式化一个整数，d代表十进制整数 |

**Note：d 十进制，b 二进制，o 八进制，x 十六进制** 

| `"{:5d}".format(24)` | ___24 | 宽度指定 5，在左侧增加空格 |
| -- | -- | -- |
| `"{:4d}".format(56789)` | 56789 | 宽度超出时全部输出 |
| `"{:.2f}".format(1.2456)` | 1.24 | 小数点保留2位，f浮点数 |
| `"{:.2e}".format(53.245)"` | 5.32e+01 | e表示科学计数法 |
| `"{:6.2f}".format(1.2449)"` | __1.24 | 宽度为6，增加了空格 |
| `"{:9s}".format("hello")` | hello____ | 宽度为9，s代表字符串，左对齐|
|`"{:>9s}".format("hello")` | ____hello | 宽度为9，右对齐 |
| `"{:^9s}".format("hello")` | __ hello __ | 居中 |

也可以多个参数一起格式化输出：

`print("{0:.2f} {1:.2f}".format(x,y))`

#### 1.5.5 位运算

& 位与，| 位或，^ 位异或，~ 位01取反，<< 位左移，>> 位右移

### 1.6 数据结构

#### 1.6.1 序列

*？很不清楚吗，数组你*

