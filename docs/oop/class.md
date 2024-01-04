# OOP czp

## Class

### 定义与声明

- 可以仅声明而不定义，只要这个函数没有被使用
- 成员函数不能重新声明

### using

(`using`的引入是为了支持模版`<template>`)

c++引入`using`来声明类型别名，用途和`typedef`类似，如`typedef struct arraylist_* arraylist;`可以写作`using arraylist = struct arraylist_ *;`

```cpp
struct Foo {
    using elem = int;
    elem x;     // OK, x has type int
    elem add(elem v) { x += v; return x; }
private:
    using type = char;
    type c;     // OK, c has type char
};

// elem y;      // Error: unknown type name 'elem'
Foo::elem z;    // OK, z has type int
// Foo::type c; // Error: 'type' is a private member of 'Foo'   
```

### this 指针

在成员函数的函数体中，访问任何成员时都会被自动添加 `this->`，例如 `void Foo::bar(int v) { x += v; } `中的 `x += v`; 实际是 `this->x += v`;

### inline

- 内联函数减少函数调用的开销
- 内联函数的代价：内联函数会在每处被调用的地方展开，因此，如果被内联的函数太大会导致目标代码太大，对代码空间和性能都会有一定影响
- 只有**函数体**写在类的定义中的**成员函数**才会被内联

### constructor 构造函数 (ctor/c'tor)

构造函数与一般成员函数的区别是，他不写返回值类型，而且直接使用类的名字（构造函数没有名字）。他使程序员能够建立起某种保证，其他成员函数都能依赖这个保证。

```cpp
class Container {
    elem* val;
public:
    Container() {
        val = nullptr;
    }
};
```
`Conrainer` 是一个构造函数，`val = nullptr` 就是前面提到的「保证」，即 val 的值要么是 `nullptr`，要么是其他成员函数赋的值，而不会是个随机的值。

这样，就可以使用 `Container c = Container();` 构造一个对象了。

或者一个构造函数也可以带参数：（注意无参构造时候不能加 `()` ）

```cpp
class Container {
    elem* val;
public:
    Container(unsigned size) {
        val = (elem*)malloc(sizeof(elem) * size);
    }
};
```
这样，就可以使用 `Container c2 = Container(64);` 构造一个自定义大小的容器了。

**Note**
c++ 还有另外一种初始化方式：

`int a = 4;` 等价于 `int a(4);`, `Container c2 = Container(64);` 等价于 `Container c2(64);`

### 内存空间分配 `new` 和 `delete`

**New: 申请内存 + 调用构造函数**

new 返回的是一个指针。

创建对象 `int * p1 = new int;` 创建数组 `int * pa = new int[n];`

如果 new 的是一个类的对象，那么构造函数就会被直接调用：

```cpp
struct Foo{ Foo(){ puts("ctor called");}};

int main(){
    Foo *p = new Foo;
    puts("=======");
    Foo *p = new Foo[5];
}
```
我们可以得到输出：
```
ctor called
=======
ctor called
ctor called
ctor called
ctor called
ctor called
```

Note: `new` or `malloc`

- new 分配成功返回的是对象类型指针，与对象严格匹配，无类型转换，所以 new 是符合类型安全性操作符；malloc 返回值类型是 void* ，一般需要接强制类型转换成我们需要的类型。
- new 可以在内存分配的时候通过调用构造函数来初始化变量，但 malloc 不行。

**Delete: 调用析构函数 + 释放内存**

如果 p 在 new 的时候创建的是单个对象，则应该用 `delete p`; 的形式 (single-object delete expression) 回收；如果 p 在 new 的时候创建的是数组，则应该用 `delete[] p`;

```cpp
struct Foo{ ~Foo(){ puts("dtor called");}};

int main()
{
    Foo *p = new Foo;
    delete p;
    puts("=====");
    Foo *p = new Foo[5];
    delete[] p;
}
```

我们能够得到输出：
```cpp
dtor called
=====
dtor called
dtor called
dtor called
dtor called
dtor called
```

### 函数默认参数

```cpp
void point(int x = 3, int y = 4);

point(1, 2); // calls point(1, 2)
point(1);    // calls point(1, 4)
point();     // calls point(3, 4)
```

因此，对构造函数：
```cpp
class Container {
    elem* val;
public:
    Container(unsigned size = 512) {
        val = (elem*)malloc(sizeof(elem) * size);
    }
};
```
这样，就可以使用 `Container c1`; 构造一个默认大小 (512) 的容器，或者用 `Container c2(64);` 构造一个自定义大小的容器了。前者实际上是 `Container(512)`，而后者是 `Container(64)`。

### 函数重载

用传入的参数来选择不同的构造函数

```cpp
double abd(double);
int abs(int);

abs(1.0);//calls abs(double)
abs(1);//calls abs(int)
```

两个只有返回值类型不同的函数不是合法的重载，因为调用时不能完成重载解析。如：
```cpp
int f(int);
void f(int);//error
```



# Others
## Template

```c++
// C++ Program to demonstrate
// Use of template
#include <iostream>
using namespace std;
 
// One function works for all data types.  This would work
// even for user defined types if operator '>' is overloaded
template <typename T> T myMax(T x, T y)
{
    return (x > y) ? x : y;
}
 
int main()
{
    // Call myMax for int
    cout << myMax<int>(3, 7) << endl;
    // call myMax for double
    cout << myMax<double>(3.0, 7.0) << endl;
    // call myMax for char
    cout << myMax<char>('g', 'e') << endl;
 
    return 0;
}
```

比如说，用c++的template完成一个bubble sort

```c++
// C++ Program to implement
// Bubble sort
// using template function
#include <iostream>
using namespace std;
 
// A template function to implement bubble sort.
// We can use this for any data type that supports
// comparison operator < and swap works for it.
template <class T> void bubbleSort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}
 
// Driver Code
int main()
{
    int a[5] = { 10, 50, 30, 40, 20 };
    int n = sizeof(a) / sizeof(a[0]);
 
    // calls template function
    bubbleSort<int>(a, n);
 
    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
 
    return 0;
}
```

也可以是class templates
```c++
// C++ Program to implement
// template Array class
#include <iostream>
using namespace std;
 
template <typename T> class Array {
private:
    T* ptr;
    int size;
 
public:
    Array(T arr[], int s);
    void print();
};
 
template <typename T> Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}
 
template <typename T> void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}
 
int main()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);
    a.print();
    return 0;
}
```

## nullptr 与 NULL 的区别

`nullptr` 表示空指针，c中 `NULL` 也可以引入 C++ 中使用。