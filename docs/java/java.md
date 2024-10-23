# 1 Introduction to Computers, Programs, and Java

## Programming Errors

- SyntaxErrors
  - Detectedbythecompiler

```java
public class ShowSyntaxErrors {
    public static main(String[] args) {
        System.out.println("Welcome to Java);
    }
}
```

- RuntimeErrors
  - Causestheprogramtoabort

```java
//注意这个是timeout
publicclassShowRuntimeErrors{
    publicstaticvoidmain(String[]args){
        System.out.println(1 / 0);
    }
}
```

- LogicErrors
  - Producesincorrectresult

```java
public class ShowLogicErrors {
    public static void main(String[] args) {
        System.out.println("Celsius 35 is Fahrenheit degree ");
        System.out.println((9 / 5) * 35 + 32);
    }
}
```

# 2 Elementary Programming

## Input

```java
Scanner input = new Scanner(System.in);     //创建一个 Scanner 客体
System.out.print("Enter a double value: "); 
double d = input.nextDouble();              //用 nextxx 取值
```

对其他种类的input选择其他的type进行输入：

`nextByte()` `nextShort()` `nextInt()` `nextLong()` `nextFloat()` `next Double()`

## Identifier

- identifier的定义
  - 字母 数字 _ $
  - 不可以始于数字
  - identifier 的类型不可以是null或者bool
  - 区分大小写
  - 不可以是保留字
- variable
  - 声明: int x; 赋值：x=1; 
  - 不区分声明和定义
  - no default value：print一个没有赋值的x会报错 编译错误

## final

`final datatype constantname = value;`

- final 修饰变量
  - 变量的值不可改变 = const
  - 变量的值可以在编译时初始化，在运行时初始化，在构造函数里初始化
    - final int i = 1;
    - final int i = (int)(MathRandom() * 10);
    - final int i;//等到要用到时才在构造函数中初始化
- final 修饰类对象
  - 表示这个变量不可以被赋值为其他对象，例如cpp中 class const *p；
    - final Value v = new Value(); 后不可以 v = new Value(); 报错
- final 修饰 method
  - 表示一个函数不可更改不可重载
  - final 不代表修饰返回值
- final 修饰 class
  - 表示整个类不可以被继承，class 中所有的 method 也被加了 final

## Calculation

- Calculations involving floating-point numbers are approximated because these numbers are not stored with complete accuracy.涉及浮点数的计算是近似的，因为这些数字没有完全准确地存储。

```java
System.out.println(1.0-0.1-0.1-0.1-0.1-0.1); //显示0.5000000000000001
System.out.println(1.0-0.9); //显示 0.09999999999999998
```

- operation: + - * / % , Math.pow(2,3), 

- double vs float

```java
System.out.println("1.0 / 3.0 is " + 1.0 / 3.0);//默认double
//1.0 / 3.0 is 0.3333333333333333 （16个）
System.out.println("1.0F / 3.0F is " + 1.0F / 3.0F);//标记float
//1.0F / 3.0F is 0.33333334(7个3)
```

- 特殊的浮点数值: 
  - 正无穷大：Double.POSITIVE_INFINITY
  - 负无穷大：Double.NEGATIVE_INFINITY
  - NaN（不是一个数字）: Double.NaN
  - 用Double.isNaN来判断是否是数字

# PPT 2 PAGE 42