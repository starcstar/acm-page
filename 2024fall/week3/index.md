# C++ 语法基础 Ⅱ

~~Practice Is All You Need~~

AtomFirst

南京航空航天大学

2024-10-10

[幻灯片(PDF)](../week3.pdf)

## 为什么要学编程

### 解决问题的两个步骤

1. Thinking: Problem -> Solution
2. Coding: Solution -> Code

这节课我们解决 `Coding` 的问题

### 怎么学 Coding

- 得到最基本的 `knowledge` （在[这节课及上节课](https://acm.starcstar.club/2024fall/)）
- 进行有质量的 `practice` （在 [OJ](https://www.luogu.com.cn/problem/P1001) 上提交你的代码）
- 现有 `knowledge` 不足后，进行新的 `knowledge-practice 循环` （从书本、网课或者[线上教程](https://www.runoob.com/cplusplus/cpp-tutorial.html)中学习新知识，然后在 OJ 上进行练习）


::: tip
听课不能直接提高你的编程能力，只能给你关于编程的知识。只有通过练习才能提高你的编程能力
:::


### 最小完备程序

#### 图灵完备

- 指可解决一切可计算问题
- 算法问题是可计算问题
- 所以图灵完备的语言可解决一切可计算问题
- 我们将在这一节建立一个完备的内部体系，理论上有能力实现一切可能的 `Coding` （但是实际中不够方便，需要改进）



### 数据 + 运算

程序可以分为数据和对数据的运算



### int 类型的变量

所有的数据在程序中都可以用整数表示

在 C++ 中用 `int` 表示整数类型

```cpp
int a=5; // 声明了一个int类型的变量，并赋值为5
```

::: tip
变量是一个盒子，可以往里面存东西，也可以从里面取东西或
:::

### int 的基本运算

可以对两个 `int` 类型的变量进行加减乘除和取模（求余数）

```cpp
#include<iostream>
using namespace std;

int main(){
    int a=3,b=5;
    int c=a+b;
    // int c=a-b;
    // int c=a*b;
    // int c=a/b;
    // int c=a%b;
    return 0;
}
```

::: details
加法 `+`、减法 `-`、乘法 `*`、除法 `/` 和取模 `%` 是最基本的运算符
:::

## 内部与外部

- 内部：程序核心逻辑
- 外部：调用与世界互动的接口

### 输入输出

虽然我们对 `a` 和 `b` 进行了运算，却不知道结果是什么，因为结果存储在内部

通过 `cout<<` 输出，可以把内部的结果展示到外部

```cpp
#include<iostream>
using namespace std;

int main(){
    int a=3,b=5;
    // cin>>a>>b;
    int c=a+b;
    cout<<c;
    return 0;
}
```

::: tip
`cin` 用于从外部输入数据，`cout` 用于向外部输出数据
:::

### 分支结构

如果条件不同，则用不同方式处理

```cpp
#include<iostream>
using namespace std;

int main(){
    int x; cin>>x;
    if(x>0){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
```

::: details
`if` 语句用于判断条件是否成立，`else` 语句用于处理条件不成立的情况
:::

### 循环结构

让程序做多次相似的工作

```cpp
#include<iostream>
using namespace std;

int main(){
    int x=0;
    while(x<5){
        cout<<x<<" ";
        x=x+1;
    }
    return 0;
}
```

::: tip
`while` 循环会在条件成立时重复执行代码块
:::

### 一维数组

可以存储一列数据

```cpp
#include<iostream>
using namespace std;

int main(){
    int a[5];
    for(int i=0;i<5;i++)
        cin>>a[i];
    for(int i=4;i>=0;i--)
        cout<<a[i];
    return 0;
}
```

::: tip
数组通过下标访问，下标从0开始

这意味着数组的长度为 `n`，下标范围是 `0` 到 `n-1`
:::



## 函数与递归

### 代码复用

不用写多次相同的代码

```cpp
#include<iostream>
using namespace std;

void say_hello(string name){
    cout<<"Hello,"<<name<<"!\n";
}

int main(){
    say_hello("cafebabe");
    say_hello("c10uds");
    return 0;
}
```

::: tip
函数是一段代码，可以在任何地方调用
:::

### 引用与 swap

本质是一个别名

```cpp
#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int t=a;
    a=b; b=t;
}

int main(){
    int x=3,y=5;
    swap(x,y);
    cout<<x<<" "<<y;
    return 0;
}
```

::: details 为什么建议初学者使用引用而不是指针

引用可以看成是 C++ 封装的指针，用来传递它所指向的对象。在 C++ 代码中实际上会经常和引用打交道，但是通常不会显式地表现出来。引用的基本原则是在声明时必须指向对象，以及对引用的一切操作都相当于对原对象操作。另外，引用不是对象，因此不存在引用的数组、无法获取引用的指针，也不存在引用的引用。

左值引用最常用的地方是函数参数，通过左值引用传参可以起到与通过指针传参相同的效果。

> 注意引用类型不属于对象类型，所以才需要 reference_wrapper 这种特殊的包装器。

引用主要分为两种，左值引用和右值引用。此外还有两种特殊的引用：转发引用和垂悬引用，不作详细介绍。

:::



### 递归

调用自己

```cpp
#include<iostream>
using namespace std;

void print(int x){
    if(x/1000)
        print(x/1000);
    cout<<"_"<<x%1000;
}

int main(){
    print(1145141919);
    return 0;
}
```

::: warning 
递归的深度有限制，过深会导致栈溢出

一般来说，OJ的栈深度等于内存限制，但并非总是如此

而且递归涉及到函数调用，会有额外的时间和空间开销，建议用循环代替递归
:::


--- 
## STL 入门

### `container` & `algorithm`

- `container`: 存储多个数据，可以遍历
- `algorithm`: 对多个数据进行操作
  


### `set` 是一种 `container`

```cpp
#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int>st{1,1,4,5,1,4};
    st.insert(19);
    st.erase(19); 
    st.insert(810);
    cout<<st.count(1)<<"\n";
    for(auto x:st)
        cout<<x<<" ";
    return 0;
}
```

::: tip
`set` 是一种 `container`，它的作用是存储数据，且数据不重复
:::



### `sort` 是一种 `algorithm`

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>a{1,1,4,5,1,4,1,9,19,810};
    sort(a.begin(),a.end());
    for(auto &x:a)
        x*=10;
    for(auto x:a)
        cout<<x<<" ";
    return 0;
}
```

::: tip
`sort` 是一个 `algorithm`，它的作用是对 `container` 中的数据进行排序
:::



### 听完课你应该做的事

- 听课不能直接提高你的编程能力，只能给你关于编程的知识。只有通过练习才能提高你的编程能力
- 每天安排一定的时间（建议一小时以上），进行本门课对应的[练习](https://www.luogu.com.cn/training/list)（入门1 到 入门6）
- 遇到问题尝试通过搜索、题解解决，如果自己不能解决可以在招新群中求助同学或学长



### 附：如何成为 ACM 高手

1. 学一点 `C++` （能写就行，参考上面）
2. [多](https://codeforces.com/profile/DGME) [写 题](https://zhuanlan.zhihu.com/p/651241833)