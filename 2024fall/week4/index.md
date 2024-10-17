---
mathjax: true
---

# 算法入门与数学基础

Kareninahui

南京航空航天大学

2024-10-18

## 什么是算法

### 定义
算法就是解决问题的一系列步骤。在计算机中，算法就是一组指令，每条指令告诉计算机该做什么。

### 基本特性
算法有几个重要的特性：

- **输入**：算法可以有零个或多个输入。
- **输出**：算法至少会有一个输出结果。
- **有穷性**：算法在执行有限的步骤后会结束，不会无限循环，每一步都能在合理时间内完成。
- **确定性**：算法的每一步都是明确的，不会有歧义。
- **可行性**：算法的每一步都是可执行的，也就是说，每一步都能通过有限次数的操作完成。


## 求最小公约数的几种算法

### 题目描述

定义两个正整数的最大公约数 $\gcd(a,b)$ 为最大的正整数 $d$，使得 $d$ 可以同时整除 $a$ 和 $b$。

例如，$\gcd(9,12)=3$，因为 $9\div 3$ 和 $12\div 3$ 的余数是 $0$，而无法找到一个比 $3$ 更大的正整数满足要求。

现在给定两个正整数 $a,b$，要求出 $\gcd(a,b)$。


### （1）直接枚举法

也就是从 $\min(a, b)$ 枚举到 $1$ 直到找到第一个即是 $a$ 的约数也是 $b$ 的约数的数字为止

```cpp
int gcd(int a, int b) {
    if (a < b) swap(a, b);
    for (int i = b; i > 0; i--) {
        if (a % i == 0 && b % i == 0) return i;
    }
}
```


### （2）更相减损法

更相减损术是中国古代数学中的一种求最大公约数（GCD）的方法，它是基于“减而治之”的策略。
这种方法在《九章算术》中有记载，其基本原理是：两个正整数，一个减小，一个保持不变，用较大的数去减较小的数，然后再用较小的数与所得的差求最大公约数，
如此循环，直到两数相等，那么相等的数就是这两个数的最大公约数。

```cpp
int gcd(int a, int b) {
    
    while(a!=b){
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}
```

::: details 更相减损法的证明

设 $a$ 和 $b$ 是两个正整数，且 $a \geq b$，我们要证明 $\gcd(a, b) = \gcd(a - b, b)$。

1. 假设 $d = \gcd(a, b)$，这意味着 $d$ 是 $a$ 和 $b$ 的公约数，即 $d \mid a$ 且 $d \mid b$。
2. 因为 $d \mid a$ 且 $d \mid b$，所以 $d \mid (a - b)$。
3. 所以 $d$ 也是 $a - b$ 和 $b$ 的公约数。
4. 现在假设 $e = \gcd(a - b, b)$，这意味着 $e$ 是 $a - b$ 和 $b$ 的公约数，即 $e \mid (a - b)$ 且 $e \mid b$。



5. 因为 $e \mid (a - b)$ 且 $e \mid b$，所以 $e \mid a$。
6. 因此，$e$ 也是 $a$ 和 $b$ 的公约数。
7. 由步骤 2 和步骤 5 可知，$d$ 和 $e$ 都是 $a$ 和 $b$ 的公约数，所以 $d$ 和 $e$ 都是 $\gcd(a, b)$ 的约数。
8. 由于 $d$ 和 $e$ 都是 $\gcd(a, b)$ 和 $\gcd(a - b, b)$ 的约数，并且 $d = \gcd(a, b)$，$e = \gcd(a - b, b)$，因此 $d \mid e$ 且 $e \mid d$，因此 $d$ 必须等于 $e$。

因此，我们证明了 $\gcd(a, b) = \gcd(a - b, b)$。

:::

### （3）欧几里得算法

欧几里得算法，也称为辗转相除法，是用来计算两个非负整数 $a$ 和 $b$ 的最大公约数（记作 $\gcd(a, b)$）的一种方法。其基本步骤是：用较大的数除以较小的数，然后再用除数除以上一次的余数，如此重复，直到余数为 0 时，最后的除数就是这两个数的最大公约数。

#### 迭代写法
```cpp
int gcd(int a, int b) {
    //若 a<b 第一次辗转相处刚好把a和b互换
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```
#### 递归写法

```cpp
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
```

::: details 欧几里得算法的证明
设 $a$ 和 $b$ 是两个非负整数，且 $a > b$，我们要证明 $\gcd(a, b) = \gcd(b, a \% b)$。

证明：

1. 首先，我们知道任何整数 $a$ 都可以表示为 $b$ 的倍数加上余数，即存在整数 $q$ 和 $r$ 使得 $a = bq + r$，其中 $0 \le r < b$。这里的 $r$ 就是 $a$ 除以 $b$ 的余数，即 $r = a \% b$。
2. 假设 $d$ 是 $a$ 和 $b$ 的一个公约数，即 $d \mid a$ 且 $d \mid b$。由于 $r = a - bq$，我们可以得出 $d \mid r$（因为如果 $d$ 整除 $a$ 和 $b$，那么它也必须整除 $a$ 和 $b$ 的任何线性组合）。
3. 因此，$a$ 和 $b$ 的任何公约数也是 $b$ 和 $r$ 的公约数。所以，$\gcd(a, b) \le \gcd(b, r)$。



4. 反过来，假设 $d$ 是 $b$ 和 $r$ 的一个公约数，即 $d \mid b$ 且 $d \mid r$。由于 $a = bq + r$，我们可以得出 $d \mid a$。
5. 因此，$b$ 和 $r$ 的任何公约数也是 $a$ 和 $b$ 的公约数。所以，$\gcd(b, r) \le \gcd(a, b)$。
6. 由步骤 3 和步骤 5，我们得出 $\gcd(a, b) = \gcd(b, r)$。
7. 重复上述过程，用 $b$ 代替 $a$，用 $r$ 代替 $b$，继续进行，直到余数变为 0。最终，我们会得到 $\gcd(a, b) = \gcd(b, a \% b) = \gcd(a \% b, b \% (a \% b)) = \ldots = \gcd(x, 0) = x$，其中 $x$ 是最后的非零余数，也就是 $a$ 和 $b$ 的最大公约数。
:::


### 习题
[课堂例题](https://www.luogu.com.cn/problem/B4025)

[最大公约数](https://www.luogu.com.cn/problem/B3736)  

[最大公约数和最小公倍数](https://www.luogu.com.cn/problem/P1029)  
[三角函数](https://www.luogu.com.cn/problem/P1888)


## 如何比较算法的好坏

### 时间复杂度
计算机科学中，算法的时间复杂度是一个函数，它定量描述了该算法的运行时间。这是一个关于代表算法输入值的字符串的长度的函数。时间复杂度常用 $O$ 符号表述，记作 
$$T(n) = O(f(n))$$
这个函数的低阶项和首项系数常常忽略，只保留最高阶项。

### 计算方式

1. 确定算法中的基本操作：基本操作通常是算法中执行次数最多的部分，通常是赋值、比较、算术运算等。

2. 找出基本操作的执行次数：通过分析代码结构（循环、递归等），找出基本操作执行的次数。

3. 忽略低阶项和常数项：只关注输入规模 $n$ 变化时的增长情况，忽略低阶项和常数因子。

4. 用大 $O$ 表示法描述增长率：使用大 $O$ 表示法来描述执行次数与输入规模之间的关系。

### 计算基本操作的执行次数
以下是一些基本操作：

加减乘除：一般来说认为是 $O(1)$。

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 3, b = 5;
    int c = a + b, d = a * b, e = a - b, f = b / a;
    cout << c << " " << d << " " << e << " " << f << endl;
    return 0;
}
```
---

线性搜索：在数组中查找一个元素，需要遍历整个数组，时间复杂度为 $O(n)$。

```cpp
int search(const int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}
```

---

二分搜索、快速幂：每次比较将搜索范围减半，时间复杂度为 $O(\log n)$。

```cpp
int binarySearch(const int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
```

---

插入排序、冒泡排序：对于每个元素，可能需要遍历之前排序好的所有元素，时间复杂度为 $O(n^{2})$。

```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

### 分析算法结构
考虑以下几种常见的算法结构：

**顺序结构**：基本操作的执行次数是累加的。

**循环结构**：基本操作的执行次数通常是循环次数乘以每次循环中的操作次数。

**条件结构**：条件语句本身不增加时间复杂度，但是条件内的操作需要考虑。

**递归结构**：相较于前三种，递归的时间复杂度分析稍复杂，递归的时间复杂度通常通过递归树或主定理来分析。

 
### 递归结构的时间复杂度分析

主定理（Master Theorem）用于分析分治算法的时间复杂度，适用于形如 

$$T(n) = aT\left(\frac{n}{b}\right) + f(n)$$ 

的递归关系式，其中：

- $T(n)$：问题规模为 $n$ 时的运行时间
- $a$：递归调用次数
- $n/b$：每次递归输入规模，$b > 1$
- $f(n)$：当前层的计算工作

::: tip 主定理的三种情况
1. 如果 $f(n) = O(n^{\log_{b}a-\epsilon})$，其中 $\epsilon > 0$，则 $T(n) = \Theta(n^{\log_{b}a})$。
2. 如果 $f(n) = \Theta(n^{\log_{b}a})$，则 $T(n) = \Theta(n^{\log_{b}a} \log n)$。
3. 如果 $f(n) = \Omega(n^{\log_{b}a+\epsilon})$，其中 $\epsilon > 0$，$a f\left(\frac{n}{b}\right) \le k f(n)$，其中 $k < 1$ 和 $n$ 足够大，则 $T(n) = \Theta(f(n))$。
:::

::: details 主定理的证明
1. 证明第一种情况：$f(n) = O(n^{\log_{b}a-\epsilon})$，其中 $\epsilon > 0$，则 $T(n) = \Theta(n^{\log_{b}a})$。

    由于 $f(n) = O(n^{\log_{b}a-\epsilon})$，所以存在一个常数 $c$ 使得 $f(n) \le c n^{\log_{b}a-\epsilon}$ 对于所有足够大的 $n$ 成立。因此，我们有：
    $$a f\left(\frac{n}{b}\right) \le a c\left(\frac{n}{b}\right)^{\log_{b}a-\epsilon} = c n^{\log_{b}a-\epsilon} = c f(n)$$
    由于 $f(n) = O(n^{\log_{b}a-\epsilon})$，所以 $a f\left(\frac{n}{b}\right) \le k f(n)$ 对于所有足够大的 $n$ 成立，其中 $k = c < 1$。因此，根据主定理的第三种情况，$T(n) = \Theta(f(n)) = \Theta(n^{\log_{b}a})$。

2. 证明第二种情况：$f(n) = \Theta(n^{\log_{b}a})$，则 $T(n) = \Theta(n^{\log_{b}a} \log n)$。
3. 证明第三种情况：$f(n) = \Omega(n^{\log_{b}a+\epsilon})$，其中 $\epsilon > 0$，$a f\left(\frac{n}{b}\right) \le k f(n)$，其中 $k < 1$ 和 $n$ 足够大，则 $T(n) = \Theta(f(n))$。
:::

## 分析三种求最大公约数的算法的算法复杂度

**方法一：枚举法**

```cpp
int gcd(int a, int b) {
    if (a < b) swap(a, b);
    for (int i = b; i > 0; i--) {
        if (a % i == 0 && b % i == 0) return i;
    }
}
```

该方法是循环结构，有一层 for 循环，可知时间复杂度为 $O(n)$，空间复杂度为 $O(1)$。


**方法二：更相减损法**

```cpp
int gcd(int a, int b) {
    while(a!=b){
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}

```
可以很容易地看出其时间复杂度与 $a/b$ 的大小有关：

- 当 $a/b$ 较小时其时间复杂度约为 $O(\log n)$；

- 当其极大时（$a$ 远大于 $b$）时，由于时间与相减的次数挂钩，其时间复杂度会退化为 $O(n)$。

空间复杂度为 $O(1)$。


**方式三 辗转相除法**
```cpp
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
```

欧几里得算法（也称为辗转相除法）的时间复杂度是 $O(\log(n))$。

> 确切地说，在输入为两个长为 $n$ 的二进制整数时，欧几里得算法的时间复杂度为 $O(n)$。（换句话说，在默认 $a, b$ 同阶的情况下，时间复杂度为 $O(\log\max(a, b))$
::: details 复杂度的证明
当我们求 $\gcd(a,b)$ 的时候，会遇到两种情况：

-   $a < b$，这时候 $\gcd(a,b)=\gcd(b,a)$；
-   $a \geq b$，这时候 $\gcd(a,b)=\gcd(b,a \bmod b)$，而对 $a$ 取模会让 $a$ 至少折半。这意味着这一过程最多发生 $O(\log a) = O(n)$ 次。

第一种情况发生后一定会发生第二种情况，因此第一种情况的发生次数一定 **不多于** 第二种情况的发生次数。

从而我们最多递归 $O(n)$ 次就可以得出结果。
:::

## 数的表示

在数学中，我们常用十进制数，而在计算机中会接触到更多的进制。常见的进制有：

**二进制（Binary）**：基数为2，只使用0和1。例如，二进制的1010代表十进制的10。
**八进制（Octal）**：基数为8，使用0到7。例如，八进制的12代表十进制的10。
**十进制（Decimal）**：基数为10，使用0到9。例如，十进制的10就是10。
**十六进制（Hexadecimal）**：基数为16，使用0到9和A到F，其中A到F代表十进制的10到15。例如，十六进制的A代表十进制的10。




### 例题：10 进制转 x 进制

#### 题目描述
给定一个十进制整数 $n$ 和一个小整数 $x$。将整数 $n$ 转为 $x$ 进制。对于超过十进制的数码，用 `A`，`B` ... 表示。

#### 代码实现

```cpp
string dict = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string ten_to_x(int n, int x)  //十进制转 x 进制函数。 
{
    string ans = "";
    while (n != 0) //模拟短除法。 
    {
        ans += dict[n % x];
        n /= x;
    }
    string t = "";  //倒取余数。
    for (int i = ans.length()-1; i >= 0; i--) t += ans[i];
    return t; 
}
```
易知时间复杂度为 $O(\log n)$，空间复杂度为 $O(1)$。


### 相关练习

[十进制转x进制](https://www.luogu.com.cn/problem/B3619)

[x进制转十进制](https://www.luogu.com.cn/problem/B3620)

[x进制转y进制](https://www.luogu.com.cn/problem/P1143)

[「CZOI-R1」进制](https://www.luogu.com.cn/problem/P10797)

## 位运算

位运算是指按照二进制进行的运算，主要用于对整数的二进制位进行操作。在 C/C++ 语言中，位运算符提供了对整型数据进行高效操作的能力。

在 C 语言中，提供了 6 种位运算符，它们分别是按位与 `&`，按位或 `|`，按位异或 `^`，按位取反 `~`，左移 `<<` 和右移 `<<`。

这些运算符只能用整型操作数，也就是说只能用于带符号和不带符号的 `short`，`int`，`long`，`char` 类型。



### 按位运算

- 按位与 `&`：对两个操作数的每一位进行与操作，只有当两个对应的二进制位都为1时，结果才为1。
- 按位或 `|`：对两个操作数的每一位进行或操作，只要两个对应的二进制位有一个为1，结果就为1。
- 按位异或 `^`：对两个操作数的每一位进行异或操作，当两个对应的二进制位不同时，结果为1。
- 按位取反 `~`：对操作数的每一位进行取反操作，即1变为0，0变为1。



### 左移和右移

- 左移 `<<`：将操作数的所有二进制位向左移动指定的位数，右边补0。
- 右移 `>>`：将操作数的所有二进制位向右移动指定的位数，左边补符号位（对于有符号数）或0（对于无符号数）。

不难看出，左移$n$位相当于乘以$2^{n}$，右移$n$位相当于除以$2^{n}$。

### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int main() { 
    int a = 60; // 二进制: 0011 1100 
    int b = 13; // 二进制: 0000 1101 
    int result = 0; 
    result = a & b; // 按位与 
    printf("a & b = %d\n", result); // 输出: 12 (二进制: 0000 1100) 
    result = a | b; // 按位或 
    printf("a | b = %d\n", result); // 输出: 61 (二进制: 0011 1101) 
    result = a ^ b; // 按位异或 
    printf("a ^ b = %d\n", result); // 输出: 49 (二进制: 0011 0001) 
    result = ~a; // 按位取反 
    printf("~a = %d\n", result); // 输出: -61 (二进制: 1100 0011) 
    result = a << 2; // 左移2位 
    printf("a << 2 = %d\n", result); // 输出: 240 (二进制: 1111 0000) 
    result = a >> 2; // 右移2位 
    printf("a >> 2 = %d\n", result); // 输出: 15 (二进制: 0000 1111) 
 
    return 0; 
} 
```