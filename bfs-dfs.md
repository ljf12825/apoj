# BFS

BFS, Breadth-First Search 广度优先搜索

核心思想：像水波纹一样，从起点开始，由近及远一层一层地向外扩散。先访问离起点最近的节点，再访问稍远一点的节点

核心数据结构：队列，队列FIFO的特性，正好符合一层一层推进的特性

经典应用场景：

- 求无权图的最短路径
- 树的层序遍历
- 社交网络中“一度好友”，“二度好友”的查找

```cpp
#include <iostream>
#include <vector>
#include <queue>

// graph 表示邻接表，start_node是起点
void bfs(int start_node, const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<bool> visited(n, false); // 记录访问状态，防止重复访问
    std::queue<int> q;

    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop()

        // 在这里处理当前节点curr的逻辑
        
        // 遍历相邻节点
            for (int neighbor : graph[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
    }
}
```

# DFS

DFS，Depth-First Search 深度优先搜索

核心思想：沿着一条分支一直往下搜，直到这条路走到头，然后回溯到上一个分叉口，继续探索另一条未走过的分支

核心数据结构：栈，可以用编程语言的函数递归调用栈来实现，也可以用显式栈来实现

经典应用场景：

- 寻找所有可能的路径、全排列、组合问题
- 连通块问题
- 拓扑排序、迷宫的所有解法

```cpp
#include <iostream>
#include <vector>

// 递归辅助函数
void dfs_helper(int curr, const std::vector<int>>& graph, std::vector<bool>& visited) {
    visited[curr] = true;

    // 在这里处理当前节点 curr 的逻辑

    // 遍历相邻节点
    for (int neighbor : graph[curr]) {
        if (!visited[neighbor]) {
            dfs_helper(neighbor, graph, visited);
        }
    }
}

// 主 DFS 函数
void dfs(int start_node, const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<bool> visited(n, false);

    // 如果图可能不连通，需要遍历所有节点作为起点
    // for (int i = 0; i < n; ++i) {
    //    if (!visited[i]) {
    //        dfs_helper(i, graph, visited);
    //    }
    // }

    dfs_helper(start_node, graph, visited);
}
```
