# Class.py

py 真的是一种很神奇的语言。。。我觉得它真的分不了点 TT，不过也有可能是老师的 PPT 做得太懒了

## 1 to start with

### 1.1 量

#### 1.1.1 关键字

- Python 区分大小写。True *not true*
- raise，is，as，expect，lambda，with，assert，finally，nonlocal，vield，class，from，global，pass
  
#### 1.1.2 id 函数

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