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
  - `/` 表示浮点数除法，`//` 表示整数除法，`//` 计算后的结果的type，如果前面两个数中有一个数float，那么最后结果也float，但是按照整除来算，跟上 .0。
  - `**` 表示幂
- 浮点数的表示方式
  - 科学计数法，1.2e-5，e后面的值就是幂次方，必须为整数，e前后不能为空
  - 浮点数计算有误差，如 `2.1-2.0==0.1` False
  - 浮点数的整除还是浮点数，取余也是浮点数
- 复数：real 和 imaginary
  - 使用 `complex()` 函数来创建一个值为 `real + imag * J ` 的复数
- `round()` 函数表示四舍五入
  - 函数只有一个参数：四舍五入
  - 有两个参数：第二个参数表示限制小数点位数。`round(10.678,2)` 为 10.67，`round(12345,-2)` 为 12300
- 位运算要使用补码，使用符号扩展扩展至32位，注意负数。


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

```python
if ...
    ......
elif ...
  ......
else ...
```



#### 1.5.2 循环

```python
for variable in 列表:
  ......
```
```python
while ...:
  ......
else:
  ......
```

注意使用 `break` 语句和 `continue` 语句。

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

**8. 数字转换字符串**

`str()`:
```python
age = 23	
print('Happy Birthday '+ str(age) +'!') # Happy Birthday 23!
```

`format()`:
```python
age = 23
print('Happy Birthday {}!'.format(age)) # Happy Birthday 23!
```
多个空就多个format允许，如：
```python
print('My name is {}, age {}'.format('Mary','18')) # My name is Mary, age 18
# 第二个format直接写18不写'18'也可以
```


#### 1.6.3 列表

**1. 列表创建**

- 字面：`a=[2.3.7]`

- `list()` 函数：`a=list('hello')` 或者 `a=list(range(1,10,2))`

- 矩阵表示：
`matrix=[[1,2,3],[3,4,5],[5,6,7]]`，访问使用 `matrix[0][0]`

*输入一串数字空格隔开，输出排序后的数字*
```python
nums = input()
numl = [int(n) for n in nums.split()]
numl.sort()
print(numl)
```

- 使用 `append()` 函数
```python
lst = []
for i in range(4):
  lst.append(input())
```

**2. 元素赋值**

列表元素可以被修改

```python
a=[1,2,3,4,5]
a[0]=2
print(a) # [2,2,3,4,5]
```

可以用 `del()` 语句删除列表中的元素

```python
name = ['Alice', 'Kim', 'Karl', 'John']
del name[2]
print(name) # ['Alice', 'Kim', 'John']
```

**3. 切片赋值**

感觉就是把多个元素当成一个切片去用，跟元素赋值一样

```python
name = list('Perl')
name[2:] = list('ar')
print(name) # ['P', 'e', 'a', 'r']
```

**4. 列表函数**

| 函数 | 描述 | 使用 | 说明 |
| -- | -- | -- | -- |
| l.append(x) | 在列表尾部追加元素 x | `l.append(13)` |
| l.clear() | 清空 |
| l.count(x) | 计算 x 出现次数 | 
| l.copy() | 列表的备份 | `a = c.copy()` | id 不同，作用相当于对 c 取全部切片 |
| l.extend(x) | 将列表 x 扩充到列表 l 中 | `l.extend([13,17])` |
| l.index(value,start,end) | 计算指定范围内 value 出现的第一个下标 |
| l.insert(index,x) | 在下标index位置插入x | `l.insert(2,4)`, `l.insert(12,3)` | 指定插入的位置不存在，则插入到最后 | `a.index(3)` | 寻找 3 的下标 |
| l.pop(index) | 返回并删除index处的元素 | `a.pop()`, `a.pop(2)` | 不带参数时候默认弹出最后一个元素 |
| l.remove(value) | 删除值为value的第一个元素 |
| l.reverse() | 倒置列表 | `a.reverse()` |
| l.sort() | 对列表元素进行排序 |

**5. 字符串和列表的相互操作**

`split()` 函数：不带参数表示用空格来划分，带参数则用参数划分。

```python
date = '3/11/2018'
a = date.split('/')
print(a) # ['3', '11', '2018']
```

`join()` 函数：参数表示中间用什么东西来间隔

```python
a = ['hello','good','boy','wii']
print(' '.join(a)) # hello good boy wii
print(':'.join(a)) # hello:good:boy:wii
```

#### 1.6.4 元组

元组不可修改，可以任何类型、任何数量。

**1. 元组创建**

用元组的字面量：`d = (100,20)`

用 `tuple()` 函数：`a = tuple([2,3,5,7,11])`

**2. 常用函数**

元组不可修改，所以大部分对元组都不适用

| 函数 | 描述 | 使用 | 备注 |
| -- | -- | -- | -- |
| t.count(x) | 计算x的出现次数 |
| t.index(x) | 计算x的出现下标 |

**3.一些案例**

*输入字符串，排序后按从小到大输出每个字符及该字符在原字符串中的索引。*
```python
s = input()
lst = [(s[index], index) for index in range(len(s))]
lst.sort()
print(lst)
```

*列表加元素表述二维表格*
```python
students = [(3180102988,"褚好"),
          (3170102465,"王凯亮"),
          (3160104456,"李永"),
          (3171104169,"陈鑫"),
          (318400429,"徐杭诚")]
for row in students: # 按行存取
  print(row[0],row[1])
print()

for id, name in students: # 按行拆包存取
  print(id, name)
print()

for index in range(len(students)):
  print(students[index][0],students[index][1])

```

#### 1.6.5 随机函数库

使用 `import random` 来导入random随机函数库

| 函数名 | 含义 | 使用 | 备注 |
| -- | -- | -- | -- |
| random.random() | 返回一个在[0,1)之间的数字 |
| random.uniform(a,b) | 返回一个在[a,b]之间的浮点数 |
| random.randint(a,b) | 返回一个在[a,b]之间的整数 |
| random.randrange(start,stop,step) | 在指定范围内返回一个随机数 |
| random.choice(sequences) | 从序列中随机返回一个数字 |
| random.shuffle(x) | 将列表x中顺序打乱 |
| random.sample(sequence,k) | 从一个序列中随机获得一个长度为k的序列并随机排序 |
| random.seed(n) | 对随机数生成器初始化，n表示随机种子。参数为空时随机种子为系统时间 |

*掷硬币，正面向上的概率是多少？*
```python
import random
t = [random.randint(0,1) for i in range(10000)]
print(sum(test) / len(test)) # 0.5006
```

#### 1.6.6 集合

set，一类容器，**无序**，元素值不可重复（如果重复的话python会把重复的直接消除）

**列表等可变对象不能做集合的元素**

**1. 集合创建**

- 直接给变量赋值：` fruit = {'apple', 'orange', 'pear', 'banana'}`
- 使用 `set()` 创建空集合
  - 也可以将列表或元组转换为集合

**2. 操作集合的元素**

| 函数    | 说明 |
| ------- | ---- |
| `len()` |      |
| `min()` |      |
| `max()`       |      |
| `sum()` |      |
| `add()` | `s.add(3)`，把元素3加入到集合 s 中 |
| `remove()` | `s.remove(3)`，删除元素3。如果不存在抛出KeyError异常 |
|         |      |

- 用循环遍历：`for x in s` 集合无序，输出结果也无序
- `in` ，`not in ` 可判断
- `s1.issubset(s2)` 或 `s1.issuperset(s2)` 判断子集或超集
  - 返回 True False
- `==` , `!=` 判断元素
- `<`, `<=` , `>`, `>=` 真子集，子集，真超集，超集

**3. 集合运算**

| 函数                      | 运算符   | 说明                                       |
| ------------------------- | -------- | ------------------------------------------ |
| `union()`                 | `|` 或   | 并集                                       |
| `intersection()`          | `&` 与   | 交集                                       |
| `difference()`            | `-` 减   | 差集                                       |
| `symmertric_difference()` | `^` 异或 | 对称性，结果是除了一个共同元素外的所有元素 |

**4. 一些案例**

*找指定范围内的质数*

```python
import math
m=int(input())
primes=set(2,m+1)
for i in range(2, int(math.sqrt(m))+1):
    if i in primes:
        primes=primes-set(range(i*i,m+1,i))
        
print(primes)
```

#### 1.6.7 字典

### 1.7 函数

#### 1.7.1 定义

- 内置函数：`len()`
- 自定义函数：先定义，才能使用
```python
def f(x):
  value=x**2+1
  return value
n=int(input())
y=f(x)
print(y)
```

**函数是一种对象：有id，type，value**

#### 1.7.2 参数

**1. 位置参数**

传入参数按照顺序复制上去。

```python
from math import sqrt
def dis(x1,y1,x2,y2):
  print("x1={},y1={},x2={},y2={}".format(x1,y1,x2,y2)) 
  return sqrt((x1-x2)**2+(y1-y2)**2)
print(dis(1,3,4,5))
```

**2. 关键字参数**

如位置参数，添加具体顺序调用：
```python
....
print(dis(x1=1,y2=5,y1=3,x2=4))
```

**当同时存在位置和关键词参数时，要先写位置参数再写关键词参数。**
```python
...
print(dis(1,3,y2=5,x2=4))
```

**3. 默认值参数**
当调用方没有提供对应的参数值时，你可以指定默认参数值。如果你提供参数值，在调用时会代替默认值。
```python
from math import sqrt
def	dis(x1,y1,x2,y2=5): #求平 面上两点距离  
    print("x1={},y1={},x2={},y2={}".format(x1,y1,x2,y2)) 
    return sqrt((x1-x2)**2+(y1-y2)**2)
print(dis(1,3,4))
```

**4. 不定长数目参数**
当函数参数数目不确定时，星号将一组可变数量的位置参数集合成参数值的元组。

```python
def countnum(a,*b): #计算参数个数
  print(b)
  print(len(b)+1)
countnum(3,7,9)
countnum(5,8,1,6,89)
```

输出：
```python
(7, 9)      #以元组的形式存放
3
(8, 1, 6, 89)
5
```

**一个星号表示输出到元组，两个星号表示输出到字典**

```python
def countnum(a,**d): #计算参数个数
    print(d)
    print(len(d)+1)
countnum(3,x1=9,x2=1,x3=6,x4=89)
```

输出：
```python
{'x1': 9, 'x2': 1, 'x3': 6, 'x4': 89}
5
```


**5. print 参数**

- `print(*object, sep=" ", end="\n", file=sys.stdout)`
  - object: 输出参数, sys.stdout：输出到屏幕
- `I=[2,7,5]`
  - `print(I)` ，输出 [2,7,5]
  - `print(*I)`，输出 2 7 5
- *表示将序列拆成一个个单独的实参，而**则表示将字典拆成一个个单独的带变量名的实参.

#### 1.7.3 返回值

return

**匿名函数：lambda表达式**

lambda 用来编写简单的函数，而def用来处理更强大的任务的函数。

```python
g = lambda x,y,z : x+y+z    
#把lambda定义的匿名函数赋给函数g
print(g(1,4,5))
```

全局变与局部变量，global 关键字

#### 1.7.4 递归

斐波那契：

```python
def fib(n):
  if n == 0 or  n == 1:
    return 1
  else:
    return fib(n-1)+fib(n-2)
print(fib(4))
```

*卧槽。。。。*

动态规划

```python
pre = {o:1, 1:1}
def fib(n):
  if n in pre:
    return pre[n]
  else:
    newvalue = fib(n-1)+fib(n-2)
    pre[n] = newvalue
    return newvalue
print(fib(100))
# 感觉也不是很dynamic programming，只是拿了一个字典（数组）来记录不用每次都递归罢了
```

#### 1.7.5 内置函数

**sorted:** 对于列表有用

sort(iterable, key, reverse)
```python
students = [('江幸',89, 15), (' 方鹏',80, 14), ('陈可', 85, 14)] #第二个分量是成绩，第三个分量是年龄
print(sorted(students, key=lambda s: s[2])) # 按年龄从小到大排序
# [(' 方鹏', 80, 14), ('陈可', 85, 14), ('江幸', 89, 15)]
print(sorted(students, key=lambda s: s[1], reverse=True))# 按成绩从大到小降序
# [('江幸', 89, 15), ('陈可', 85, 14), (' 方鹏', 80, 14)]
```


**map:** 多用于input
```python
print(list(map(lambda x: x ** 2, [1, 2, 3, 4, 5]))) # 使用 lambda 匿名函数
# [1, 4, 9, 16, 25]
```
```python
print(list(map(lambda x, y: x + y, [1, 3, 5, 7, 9], [2, 4, 6, 8, 10])))
# 提供了两个列表，对相同位置的列表数据进行相加
# [3, 7, 11, 15, 19]
```

**zip:**
```python
a = [1,2,3]
b = [4,5,6]
c = [4,5,6,7,8]
print(list(zip(a,b))) # [(1, 4), (2, 5), (3, 6)]
print(list(zip(a,c))) # 元素个数与最短的列表一致
# [(1, 4), (2, 5), (3, 6)]
```
或者字典键值互换
```python
d={'blue':500,'red':100,'white':300} 
d1=dict(zip(d.values(),d.keys())
print(d1)
# {500: 'blue', 100: 'red', 300: 'white'}
```

**eval:**
```python
x,y=3,7
eval(‘x+3*y-4’)
# 20
```

**exec:**
```python
exec(‘print(“hello world”)’)
Hello world 
```

**all:**
```python
n=47
print(all([1 if n%k!=0 else 0 for k in range(2,n)])) #True
n=15
print(all([1 if n%k!=0 else 0 for k in range(2,n)])) #False
```

**any:**
```python
any([[],False,0])   #空列表和0都表示False
#False
```

### 1.8 程序模块

```
import  模块名
import  模块名 as 别名 
from  模块名 import  *
这种方法引入模块中的所有函数，调用的时候不需要再加模块名
from  模块名 import  函数名
这种方法引入模块中的单个函数，调用的时候也不需要再加模块名
del 模块名       删除引入的模块名
```

