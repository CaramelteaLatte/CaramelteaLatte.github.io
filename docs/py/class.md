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


*惨痛经历告诉我，不能莫名其妙缩进语句，会爆莫名其妙的错。。。。备注#空格请删干净。。。。。。。*

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

**要注意这种方法下总位数不会数进去小数点，但是别的书写方法会算进小数点，所以要数一下减一**

也可以多个参数一起格式化输出：

`print("{0:.2f} {1:.2f}".format(x,y))`

`{}` 表示占位符，format后跟填写的内容，0和1(:前)表示索引序列

#### 1.5.5 位运算

& 位与，| 位或，^ 位异或，~ 位01取反，<< 位左移，>> 位右移

### 1.6 数据结构

#### 1.6.1 序列

*？很不清楚吗，数组你*

**序列是一大类数据容器的统称，不是具体的数据类型**

`range()` 函数产生结果是**序列**，因此 for 函数可以直接遍历 range 函数的返回对象。

如 `for i in range(4)` 而不需要 `for i in list(range(4))`

| 序列操作 | 描述：大部分跟字符串类型极其相似 |
| -- | -- |
| `X1+X2` |  |
| `X*n` |  |
| `X[i]` | 访问下标 i 的元素 |
| `X[i: j]` | 引用下标 i 到 **j-1** 的子序列 |
| `X[i: j: k]` | 引用...的子序列，步长 k |
| `len(X)` |  |
| `max(X)` |  |
| `min(X)` |  |
| `v in X` | 检查 v 是否在 X 中，返回布尔值 |
| `v not in X` |  |

**1. 序列访问：**

- 对一个有 n 个数据的序列，下标的有效范围是 0 到 n-1，或 -n 到 -1
- 否则报错，下标越界
- -1 为最后一位，负数表示从后往前
- [1:-3] 表示从第二个数到倒数第四个数（第三个数的前面一个数）
- 步长可以取负，取负表示从后往前取（顺序会不一样）

**2. 序列复制：**

- 如果直接将一个序列变量赋值给另外一个数列变量，那么这两个变量表达同一个序列（地址一样，值的改变一样）
- 如果不想要地址相同的情况，可以使用切片：
```python
a = [2, 3, 5, 7, 11, 13]
b = a[ : ] # 省略范围表示取整个从头到尾
```

**3. 拆包运算：**

*python真的好简易好无脑啊啊啊我懂他为啥作为工具了。。。*

```python
info=["章武","male",30,[70,80,65,78]]
name,sex,age,grade=info
```

- 字符串也是一种序列，字符串也可以拆包
- 字符串/序列前面加 `*`，可以获取子序列

```python
grade=[70,80,65,78]
a,*b=grade # a=70, b=[80,65,78]
```

**4. 元素判断：**

- we have: `a=[2,3,4,5,7,11,13]`
- `print(3 in a)` True
- `[2,3] in a` False
- `[2,3] in [[2,3],4,5,11,13]` True
 
**5. 获取索引：**

- 获取一个元素的下标。
- 如果这个序列中有重复元素，那么对重复元素的 index 操作返回第一次出现时候的index值
- 不存在元素会报错返回

#### 1.6.2 字符串

**1. 原始字符串：**

在一个字符串前面加一个字符 r，表示这个字符串无转义字符

```python
r = r'hello\nworld'
print(r) # hello\nworld
```

**2. 字符串修改：**

字符串不可以修改单个数据或字符，必须要用新的字符串对变量整个赋值。

```python
s='hello'
s[0]='k' # 报错
```
```python
s='hello'
s='bye' # 正确修改字符串
```

**3. 字符串查找子串：find()**

在字符串中查找子串，返回的是第一次出现的位置的下标（从0开始），找不到返回-1
```python
s = 'This is a test.'
print(s.find('is')) # 2 find 与 index 一致在重复元素，但find 能对不存在的元素返回-1而index不能
print(s.index('is')) # 2
print(s.find('OK')) # -1
print(s.find('is',3)) # 5 3表示范围从index为3开始，不包括3
print(s.find('is',3,6)) # -1 表示范围在index3到6，不包括3和6
```

**4. 统计次数：count()**

真的很字面意思啊，，

```python
s='This is a test.'
print(s.count('is')) # 2
```

**5. 修改大小写**

```python
name = 'john s'
print(name.title()) # John S 修改首字母
print(name.upper()) # JOHN S
print(name.lower()) # john s
```

**6. 删除空格**

```python
name=" python "
print(name.strip())  # 'python'
print(name.lstrip()) # 'python '
print(name.rstrip()) # ' python'
```

**7. 替换子串**

```python
s='This is a test.'
t=s.replace('is','eez')
print(t) # Theez eez a test
```

#### 1.6.3 列表和元组

**1. 列表创建**

- 字面：`a=[2.3.7]`

- `list()` 函数：`a=list('hello')` 或者 `a=list(range(1,10,2))`

- 矩阵表示：
`matrix=[[1,2,3],[3,4,5],[5,6,7]]`，访问使用 `matrix[0][0]`

**2. 元素赋值**

列表元素可以被修改

```python
a=[1,2,3,4,5]
a[0]=2
print(a) # [2,2,3,4,5]
```
