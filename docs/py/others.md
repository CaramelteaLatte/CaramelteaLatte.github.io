# Others.py

## 1 `eval()`函数

### 1.1 `eval(expression, globals, locals)`

表达式字符串，变量作用域（第23个参数）（可选）

如果忽略后面两个参数，eval 表示在当前作用域执行

```python
a = 1
print(eval("a+1")) #2
```

如果指定 globals 参数

```python
a = 1
g = {"a": 10}
print(eval("a+1", g)) #11
```

如果指定locals参数

```python
a = 10
b = 20
c = 20
g = {"a": 6, "b": 8}
l = {"b": 9, "c": 10}
print(eval("a+b+c", g, l)) #25，这里要注意字典覆盖
```

### 1.2 `eval(input())`

将输入的 str 表达式类型返回为 int, list, dict, tuple

