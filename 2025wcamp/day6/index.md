# 最小生成树问题

## 前置知识

- 树与图的基本概念，涵盖图的度、图的存储方式、树和森林的概念、生成树的定义等。
- STL容器中优先队列（priority_queue）的使用。

## 一、并查集（Disjoint Set Union, DSU）

### 引入
**并查集**是一种用于管理元素所属集合的数据结构，实现为一个**森林**，其中每棵树表示一个集合，树中的节点表示对应集合中的元素。

它支持两种操作：

- **合并（Union）**：合并两个元素所属集合（合并对应的树）

- **查询（Find）**：查询某个元素所属集合（查询对应的树的根节点），这可以用于判断两个元素是否属于同一集合

### 初始化

**f[]** 存储某个节点的父亲节点。

初始时，每个元素各自构成一个独立的集合，表示为一棵仅包含根节点的树，**其父节点即为自身**。

```c++
#include <vector>
#include <numeric> // iota函数所在头文件
using namespace std;
struct DSU {
    vector<int> f;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        // for (int i = 0; i < n; i++) f[i] = i;
    }
};
```

### 查找

每个集合所代表的树，其根节点均存在且互不相同，根节点可代表一个集合。

查找的目的是确定元素所在的集合，即找到节点在树中的根，具体步骤如下：

1. 如果父节点等于自身，表示找到了根，直接返回。
2. 如果父节点不等于自身，则继续向其父节点递归查找。

```c++
int DSU::find(int x) {
	if (f[x] == x) {	
		return x;
	}
	return find(f[x]);
}
```

#### 路径压缩

查找过程中，经过的每个元素均属于当前集合，因此可以在返回的同时，顺带将每个元素的父节点修改为根。

```c++
int DSU::find(int x) {
    if (f[x] == x) {
        return x;
	}
    return f[x] = find(f[x]);
}
```

### 合并

合并两棵树时，将其中一棵树的根节点指向另一棵树的根节点即可。

```c++
void DSU::merge(int x, int y) {
	f[find(x)] = find(y);
}
```

#### 启发式合并

合并时，选择哪棵树的根节点作为新树的根节点，会对后续操作的复杂度产生影响。可将节点较少或深度较小的树连到另一棵树上，以避免发生退化。

##### 完整代码（按秩合并）

```C++
struct DSU {
    vector<int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        if (f[x] == x) {
            return x;
        }
        return f[x] = find(f[x]);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
};
```

### 并查集的应用

通常认为并查集的时间复杂度为一个较小的常数，若对分析过程感兴趣，可参考以下链接：

[并查集时间复杂度的分析]: https://www.luogu.com.cn/article/x3u368oh

并查集的应用十分广泛，在竞赛多用于解决**图的连通性问题**

#### Luogu P1536 村村通

##### 题目描述

某市调查城镇交通状况，得到现有城镇道路统计表。表中列出了每条道路直接连通的城镇。市政府 "村村通工程" 的目标是使全市任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要相互之间可达即可）。请你计算出最少还需要建设多少条道路？

##### 解法

在这道题中，城镇之间的联通关系构成了一个或多个联通分量，同一联通分量中的城镇两两可达。

从集合的角度来看，这些城镇被划分到不同的集合中，假设集合总数为n，那么答案就是将这些集合两两合并所需的次数，即n-1。

##### 完整代码

```c++
#include <bits/stdc++.h>
using namespace std;

/*
并查集代码，已省略
*/

int main() {
    int n, m;
    while (cin >> n, n) {
        cin >> m;
        DSU dsu(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            dsu.merge(u, v);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (dsu.find(i) == i) { // 如果是一个集合，则集合总数+1
                cnt++;
            }
        }
        cout << cnt - 1 << "\n";
    }
    return 0;
}
```

---

## 二、Kruskal算法

### 原理
**Kruskal算法 **是由 Kruskal 提出的一种基于贪心策略的算法，用于解决**最小生成树**（Minimum Spanning Tree，MST）问题，即求边权和最小的生成树。

算法分为三个步骤：

1. 将所有的边按照边权从小到大排序。
2. 按排序后的顺序枚举每一条边，如果这条边连接的两个点不在同一集合中，就把这条边加入最小生成树，同时**合并**这两点所在的集合；否则，跳过该步骤。
3. 重复执行步骤2，直到选取了**n-1条边**。

由于**并查集**能够高效地完成查找与合并操作，因此非常适合与Kruskal算法配合使用。

### 实现代码
```c++
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

/*
并查集代码，已省略
*/

struct edge {
    int u, v, w;
    bool operator<(const edge &e)const {
        return w < e.w;
    }
};
int n, m, ans;
vector<edge> ed;

bool kruskal() {
    sort(ed.begin(), ed.end());
    DSU dsu(n + 1);
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int u = ed[i].u, v = ed[i].v;
        if (dsu.find(u) != dsu.find(v)) {
            dsu.merge(u, v);
            ans += ed[i].w;
            cnt++;
        }
    }
    return cnt == n - 1;
}
```

### 时间复杂度
- 边的排序：`O(mlogm)`
- 并查集操作：`O(mα(m, n))`（`α(m,n)`近似为常数）
- **总复杂度**：`O(mlogm)`

---

## 三、Prim算法

### 原理
**Prim算法**也是一种贪心算法，其流程与Dijkstra算法类似。

算法包含以下三个步骤：

1. 从任意顶点出发，将该顶点的距离初始化为0，其余顶点的距离初始化为正无穷。
2. 选择未访问过的距离最小的一个顶点，利用该顶点连接的边更新其他顶点的距离。
3. 重复执行步骤2，直到选取了**n个点**。

### 关键代码
```c++
struct edge {
    int v, w;
};
int n, m, ans;
vector<vector<edge>> adj;
const int inf = 0x3f3f3f3f; // 无穷大
bool prim(int s) { // 参数s为选择出发的顶点
    vector<int> dis(n + 1, inf);
    vector<bool> vis(n + 1);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
    	int u = 0;
    	for (int j = 1; j <= n; j++) {
    		if (vis[j] == false && dis[j] < dis[u]) {
    			u = j;
			}
		}
		if (dis[u] == inf) { // 无法拓展至新的顶点，表示该图不联通
			return false;
		}
		vis[u] = true; // 标记该顶点已访问
		ans += dis[u];
		for (edge ed : adj[u]) {
			int v = ed.v, w = ed.w;
			if (dis[v] > w) {
				dis[v] = w;
			}
		}
	}
	return true;
}
```

暴力版本的时间复杂度为`O(n²)`，在稀疏图（顶点数通常较大）中难以满足需求，可以借鉴Dijkstra算法的优化方法，使用优先队列维护查找顶点的过程，从而得到另一种时间复杂度。

### 实现代码（堆优化）

```c++
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
    int v, w;
};
int n, m, ans;
vector<vector<edge>> adj;
const int inf = 0x3f3f3f3f;

bool prim(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // 小根堆
    vector<int> dis(n + 1, inf);
    vector<bool> vis(n + 1);
    int cnt = 0;
    dis[s] = 0;
    q.push({0, s});
    while (q.size()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) { // 已访问该顶点，跳过
            continue;
        }
        vis[u] = true; // 标记该顶点已访问
        ans += dis[u];
        cnt++;
        for (edge ed : adj[u]) {
            int v = ed.v, w = ed.w;
            if (dis[v] > w) {
                dis[v] = w;
                q.push({dis[v], v}); // 将更新过的顶点加入队列
            }
        }
    }
    return cnt == n;
}
```

### 时间复杂度

#### 暴力版

- 二重循环：`O(n²)`
- 更新操作：`O(m)`
- **总复杂度**：`O(n²)`

#### 堆优化版

- 优先队列操作：`O(mlogm)`
- 更新操作：`O(m)`
- **总复杂度**：`O(mlogm)`

---

## 四、Kruskal算法与Prim算法的比较

| **特性**         | **Kruskal算法**          | **Prim算法**（暴力） | Prim算法（堆优化）               |
| ---------------- | ------------------------ | -------------------- | -------------------------------- |
| **特殊数据结构** | 并查集                   | 无                   | 优先队列                         |
| **时间复杂度**   | `O(mlogm)`               | `O(n²)`              | `O(mlogm)`                       |
| **适用图类型**   | 稀疏图（点多边少）       | 稠密图（点少边多）   | 稀疏图                           |
| **实现难度**     | 简单（仅需排序和并查集） | 简单                 | 中等（需维护优先队列和顶点状态） |

---

## 总结
- **Kruskal**和**堆优化Prim**都适合处理稀疏图，其中Kruskal实现较为简单，而且常数较小。
- **暴力Prim**在稠密图中效率更高。
- 在实际应用中，若图以邻接表等形式存储，优先考虑Prim；若边列表已排序，则优先考虑Kruskal。