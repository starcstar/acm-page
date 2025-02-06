# 最短路径问题

By Coel

[幻灯片PDF](./slide.pdf)

## 前置知识回顾

1. 图的存储。通常有邻接表、链式前向星、邻接矩阵等方法，最短路算法一般使用前两种，掌握其一即可。

```C++
// 邻接表
struct node {
    int v, int w;
};

vector<node> G[maxn]; // G[u] 存放所有以 u 为起点的边

void add(int u, int v, int w) {
    G[u].push_back({v, w});
}

void search(int u) { // 遍历 u 的所有出边
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i].v, w = G[u][i].w;
        // do something
	}
}


// 链式前向星
int head[maxn], nxt[maxn], to[maxn], val[maxn], cnt;

void add(int u, int v, int w) { // 使用前要把 head 数组初始化为 -1
    nxt[cnt] = head[u];
    to[cnt] = v;
    val[cnt] = w;
    head[u] = cnt++;
}

void search(int u) {
    for (int i = head[u]; i != -1; i = nxt[i]) {
        int v = to[i]; w = val[i];
        //do something
    }
}
```

2. 简单的 STL 容器使用。下面介绍的两种算法需要用到优先队列和普通队列两种容器。

```cpp
// 普通队列
queue<int> Q; // 定义一个队列 Q
Q.push(x); // 将元素 x 放进队列末尾
Q.front(); // 返回队列最前面的元素
Q.pop(); // 删除队列最前面的元素
Q.empty(); // 返回一个 bool 变量，表示队列是否为空
Q.size(); // 返回队列中元素的个数

// 优先队列
priority_queue<int> Q; // 定义一个从大到小排序的优先队列（即大根堆）
priority_queue<int, greater<int>, vector<int> > Q; // 定义一个从小到大排序的优先队列（即小根堆）
Q.top(); // 返回优先队列d元素
// 除没有 Q.front() 外，其余操作与普通队列一致
```

图相关的基本概念不再赘述。

## 问题简介

后面介绍的两个算法都是用来解决下面这个问题的。

### [单源最短路径](https://www.luogu.com.cn/problem/P4779)


### 题目描述

给定一个 $n$ 个点，$m$ 条有向边的带非负权图，计算从 $s$ 出发到每个点的距离。

数据保证你能从 $s$ 出发到任意点。

### 输入格式

第一行为三个正整数 $n, m, s$。
第二行起 $m$ 行，每行三个非负整数 $u_i, v_i, w_i$，表示从 $u_i$ 到 $v_i$ 有一条权值为 $w_i$ 的有向边。

### 输出格式

输出一行 $n$ 个空格分隔的非负整数，表示 $s$ 到每个点的距离。

## Dijkstra 算法

Dijkstra 算法用于处理边权非负的情况，且效率优秀，是单源最短路径的首选算法。

这个算法的基本思路是：把所有的点划分到两个集合 $S,T$ 之中，前者包含已经确定最短路径的点，后者包含未确定最短路径的点，并通过**松弛操作**，将所有节点从 $T$ 移动到 $S$ 中，直到 $T$ 变为空集。

下面是用到的记号：

1. 记从源点 $s$ 到节点 $u$ 的最短路径为 $dis_u$；
2. 记节点 $u$ 是否划分到集合 $S$ 的标记为 $vis_u$（即：如果节点 $i$ 的最短路已经确定，则 $vis_u=1$，反之为 $0$）。

则 Dijkstra 算法的步骤如下：

1. 初始化 $dis_s=0$，其余节点 $dis_u=+\infty$；所有节点都在 $T$ 集合中，即 $vis_u=0$。

2. 从 $T$ 集合中选取一个 $dis_u$ 最小的节点 $u$，并将其移入 $S$ 集合（即标记 $vis_u=1$）；

3. 遍历节点 $u$ 的所有出边，并进行松弛操作。

   具体来说，对于节点 $u$ 的任意一个连接到节点 $v$ 、权值为 $w$ 的边，如果有 $dis_v>dis_u+w$，则将 $dis_v$ 更新为 $dis_u+w$。

4. 重复步骤 $2、3$，直到所有节点都被划分到集合 $S$ 中。

直接模拟这个步骤的时间复杂度是 $O(n^2)$，因为每次需要把 $n$ 个点都划分到集合 $T$ 中，而每次寻找 $dis_u$ 最小的节点要进行 $O(n)$ 次比大小。

```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 5e5 + 10;

int n, m, s;
int dis[maxn], vis[maxn];
int head[maxn], nxt[maxn], to[maxn], val[maxn], cnt;

void add(int u, int v, int w) {
	nxt[cnt] = head[u];
	to[cnt] = v;
	val[cnt] = w;
	head[u] = cnt++;
}

void Dijkstra(int s) {
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0; // 第一步：初始化
	
	for (int i = 1; i <= n; i++) {
		int u = 0, minDis = 0x3f3f3f3f;
		for (int j = 1; j <= n; j++) {
			if (vis[j] == 0 && dis[j] < minDis) {
				minDis = dis[j];
				u = j;
			}
		}
		vis[u] = 1; // 第二步：寻找最小节点，并标记
		
		for (int j = head[u]; j != -1; j = nxt[j]) {
			int v = to[j], w = val[j];
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
			}
		} //第三步：遍历，松弛操作
	}
}

int main() {
	memset(head, -1, sizeof(head));
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	Dijkstra(s);
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << ' ';
	}
	return 0;
}
```

优化：注意到寻找最小值节点的过程可以用优先队列维护，则每次操作的时间复杂度仅为 $O(\log n)$，总时间复杂度变为 $O(m\log n)$。

```cpp
typedef pair<int, int> pii; // pair 的第一维存放 dis 值，第二维存放节点序号
// 这样做之后，优先队列就会默认按照 dis 数值从小到大排序

void Dijkstra(int s) {
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0; //第一步：初始化
	Q.push({0, s});
	
	while (!Q.empty()) {
		int u = Q.top().second;
		Q.pop();
		if (vis[u]) continue;
		vis[u] = 1; // 第二步：寻找最小节点，并标记
        
		for (int i = head[u]; i != -1; i = nxt[i]) {
			int v = to[i], w = val[i];
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) {
					Q.push({dis[v], v});
				}
			}
		} //第三步：遍历，松弛操作
	}
}
```

## SPFA 算法

SPFA 算法可以求解图中含有负权边的情况，既可以判断一张图是否有（可以从源点 $s$ 到达的）负环，也可以计算没有负环时图的最短路（因为如果有负环，那么绕着负环一直走可以让最短路的值无限小）。

这里先介绍 Bellman-Ford 算法，再给出队列优化后得到的 SPFA 算法。

Bellman-Ford 算法的流程为：

1. 初始化 $dis_s=0$，其余节点 $dis_u=+\infty$；
2. 遍历所有从 $u$ 到 $v$ 权值为 $w$ 的边，对其进行松弛操作；
3. 重复第二步，直到无法进行任何松弛操作。

特别来说，因为每遍历一次都会让当前求得的最短路至少向外拓展一条边，而最短路最多只能有 $n-1$ 条边，所以，如果第二步操作可以进行第 $n$ 轮，那么这意味着最短路无解，即存在负环。

```cpp
bool Bellman_Ford(int s) { // 返回值表示图中是否存在可以从点 s 到达的负环
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0; // 第一步：初始化
    
	bool flag;
	for (int i = 1; i <= n; i++) { // 第二步：遍历所有边并进行松弛操作
		flag = false; // 标记是否进行松弛操作
		for (int u = 1; u <= n; u++) {
			for (int j = head[u]; j != -1; j = nxt[j]) {
				int v = to[j], w = val[j];
				if (dis[u] == inf) continue; // 如果 dis[u] 是无穷大，则显然无法进行松弛操作
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					flag = true;
				}
			}
		}
		if (flag == false) break;
	}
    return flag; // 如果仍然进行了松弛操作，则说明负环存在
}
```

SPFA 算法通过对 Bellman-Ford 算法优化得到。由于只有上一次松驰过的节点会影响下一次节点能否进行松弛操作，所以只需要使用一个队列存储“可能需要松弛操作的节点”，这使得需要遍历的边大大减少。

至于判断负环，只需记录最短路的边数是否超过 $n-1$ 即可。虽然这个过程与 Bellman-Ford 算法不同，但背后的原理是一致的。

```cpp
bool SPFA(int s) {
	queue<int> Q;
	memset(dis, 0x3f, sizeof(dis));
	Q.push(s);
	dis[s] = 0; // 第一步：初始化
	vis[s] = true; // vis[u] 表示点 u 是否被存储
	
	while (!Q.empty()) { // 第二步：遍历所有需要松弛的边
		int u = Q.front();
		Q.pop();
		vis[u] = false;
		
		for (int i = head[u]; i != -1; i = nxt[i]) {
			int v = to[i], w = val[i];
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				tot[v] = tot[u] + 1; // tot[u] 记录到达 u 点的最短路边数
				if (tot[v] > n - 1) return false; // 如果边数大于 n - 1，则存在负环
				if (!vis[v]) {
					Q.push(v);
					vis[v] = true;
				}
			}
		}
	}
	return true;
}
```



需要注意的是，SPFA 算法的时间复杂度为 $O(kn)$，通常来说 $k$ 是一个很小的常数，但在特殊结构的图中 $k$ 的值可以近似于 $m$，与普通的 Bellman-Ford 算法相差不大，远远落后于 Dijkstra 算法。因此，如果给定的图是非负权图，尽量不要使用 SPFA 算法。
