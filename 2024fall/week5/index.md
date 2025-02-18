# 基本数据结构与简单搜索技术

$67Plus$

南京航空航天大学

2024/10/26

## 栈和stack

栈是基础数据结构之一，具有“**先进后出**”的特点。例如，在一盒泡腾片中，最先放入的药片位于最底层，最后才被取出。

### stack

**stack**是**STL**（标准模板库）中的一种**容器类型**。

栈的常用操作包括：

```cpp
#include <stack> // 头文件
stack<Type> s;   // 定义栈，Type 为数据类型，例如 int、float 等
s.push(item);    // 将 item 推入栈顶
it = s.top();    // 获取栈顶元素并赋值给 it
s.pop();         // 弹出栈顶元素，但没有返回值
s.size();        // 返回栈中元素的个数
s.empty();       // 检查栈是否为空，若为空返回 true，否则返回 false
```

## 队列和queue

队列也是基础数据结构之一，特点是“**先进先出**”。例如，现实生活中的排队，先来的人先得到服务。

### queue

和**stack**一样，**queue**也是**STL**中的一种**容器类型**。

队列的常用操作包括：

```cpp
#include <queue> // 头文件
queue<Type> q;   // 定义队列，Type 为数据类型，例如 int、float 等
q.push(item);    // 将 item 放进队列尾部
it = q.front();  // 获取队首元素并赋值给 it
q.pop();         // 弹出队首元素，但没有返回值
q.size();        // 返回队列中元素的个数
q.empty();       // 检查队列是否为空，若为空返回 true，否则返回 false
```

## 其他常用基本数据结构

- **优先队列 priority_queue**: 带有排序功能的队列
- **集合 set**: 每个元素只出现一次，且是自动排序的
- **映射 map<key, value>**: 实现从 key 到 value 的一一映射
- **链表 list**: 一种链式存储结构（在竞赛中较少使用）

> 除 list 外，各种数据结构（尤其是 map 和 set）在竞赛中的应用非常广泛。

## 简单搜索技术

搜索技术是“暴力法”思想的具体实现。

> 暴力法 (Brute force): 将所有可能的情况都罗列出来，然后逐一检查，从中找到答案。

**深度优先搜索 (DFS)** 和 **广度优先搜索 (BFS)** 是最基础的两种搜索方法。

### 算法思路

以老鼠走迷宫为例，假设老鼠在每个岔路口有两条路可以走：

- 一只老鼠走迷宫。这只老鼠在每个路口都选择先走右边（或左边），能走多远就走多远，直到碰壁没法继续走，这时它**回退一步**，换另一条路走。这个方法可以走遍**所有**的路径且**不会重复**，这就是**DFS**的思路。
- 一群老鼠走迷宫。假设有无限只老鼠进入迷宫，在每个路口分出一部分老鼠探索所有**未走过的路**。如果某条路的尽头无法再走，走到尽头的老鼠**原地停下**；如果某路口已有其他老鼠探索过，后来的老鼠也**原地停下**。这种思路即**BFS**。

### 迷宫寻路

#### 题目描述

机器猫被困在一个矩形迷宫里。

迷宫可以看作一个 $n \times m$ 矩阵，每个位置要么是空地，要么是墙。机器猫只能从一个空地走到其上、下、左、右相邻的空地。

机器猫初始时位于 $(1, 1)$ 的位置，判断是否可以走到 $(n, m)$ 位置。

#### 输入示例

```
3 5
.##.#
.#...
...#.
```

#### 输出示例

```
Yes
```

## DFS与递归

使用 DFS 的思路解决该问题。

我们用 $visited[i][j]$ 记录 $(i,j)$ 位置是否被访问过。DFS 的执行步骤如下：

1. 标记 $visited[1][1] = true$，表示 $(1,1)$ 位置已被访问。
2. 按顺时针顺序（或任意顺序）选择一个能走的方向走一步（无法行进的情况包括障碍物和**坐标越界**）。
3. 令新的位置为 $(i,j)$，标记 $visited[i][j] = true$。
4. 重复步骤 2，继续前进。
5. 若在某个位置 $(x,y)$ 无路可走，则回退一步（不必设置 $visited[x][y] = false$，因为已访问点无需再次遍历）。
6. 如果过程中出现 $visited[n][m] == true$，则说明能到达，输出 Yes；否则输出 No。

以下是 DFS 的代码实现：

```cpp
void dfs(int x, int y) {
    visited[x][y] = true;
    if (x == n && y == m) { // 达成条件返回
        ok = true;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int tox = x + dx[i];
        int toy = y + dy[i];
        if (check(tox, toy)) dfs(tox, toy); // 递归调用
        if (ok) return; // 达成条件直接返回
    }
}
```

## BFS与队列

BFS 也可以解决该问题。用 BFS 遍历迷宫，$visited[i][j]$ 记录 $(i,j)$ 位置是否访问过。BFS 的执行步骤如下：

1. 将 $(1,1)$ 进队，当前队列为 ${ (1,1) }$。
2. 队首元素 $(1,1)$ 出队，将其邻居 $(1,2)$ 和 $(2,1)$ 入队，即从 $(1,1)$ 向周围扩散。
3. 对队列中的每个元素逐一处理，将其周围未入队的元素入队（记得检查坐标合法性）。
4. 重复步骤 2、3，直到队列为空。如果 $visited[n][m] == true$，则可以到达终点；否则不行。

使用 STL 的 queue 实现 BFS，如下：

```cpp
bool bfs(int x, int y) {
    queue<pair<int, int>> q; // pair 结构可换成 struct
    q.push({ x, y });
    visited[1][1] = true;
    while (!q.empty()) {
        int nowx = q.front().first, nowy = q.front().second; // 获取队首
        q.pop(); // 队首出队
        for (int i = 0; i < 4; i++) {
            int tox = nowx + dx[i];
            int toy = nowy + dy[i];
            if (check(tox, toy)) {
                q.push({ tox, toy }); // 新元素入队
                visited[tox][toy] = true; // 入队即视为已访问
            }
        }
    }
    return visited[n][m];
}
```

```cpp
// 辅助代码示例
bool check(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m && !visited[x][y] && graph[x][y] == '.';
} // 判断坐标合法性
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 }; // 下右上左四个方向
```

## 举一反三

可基于以上迷宫寻路问题扩展：

- 给出任意两个位置，判断是否能从 a 走到 b。
- 限制机器猫只能向右或向下移动，求解：
  - 任意两点之间的路径数
  - 任意两点之间的最短路径长度s