# LeetCode 3004. 相同颜色的最大子树 解析

## 问题理解

这道题给定一棵以节点 0 为根的树，每个节点都有一个颜色（由 colors 数组给出）。我们需要找到一个节点 v，使得以 v 为根的子树中所有节点都具有相同的颜色。在满足这个条件的所有子树中，我们要返回节点数量最多的子树的大小。

## 解题思路

这是一个典型的树形 DP 问题，可以使用 DFS（深度优先搜索）来解决。关键思路如下：

1. 构建树的邻接表表示
2. 从根节点开始进行 DFS 遍历
3. 对于每个节点，我们需要判断其子树是否具有相同的颜色
4. 如果一个子树中所有节点颜色相同，则更新最大子树大小

## 代码实现

## Python 实现

```python
class Solution:
    def maximumSubtreeSize(self, edges: List[List[int]], colors: List[int]) -> int:
        n = len(colors)

        # 构建无向图
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        self.max_size = 0

        # DFS函数，返回(是否颜色一致, 子树大小)
        def dfs(node, parent):
            node_color = colors[node]
            subtree_size = 1  # 当前节点
            is_uniform = True

            for neighbor in graph[node]:
                if neighbor == parent:
                    continue  # 跳过父节点

                child_uniform, child_size = dfs(neighbor, node)
                subtree_size += child_size

                # 如果子树不是颜色一致，或者子节点颜色与当前节点不同，则当前子树不是颜色一致的
                if not child_uniform or colors[neighbor] != node_color:
                    is_uniform = False

            # 如果当前子树颜色一致，更新最大大小
            if is_uniform:
                self.max_size = max(self.max_size, subtree_size)

            return is_uniform, subtree_size

        dfs(0, -1)  # 从根节点开始DFS，没有父节点

        return self.max_size
```

## 复杂度分析

- **时间复杂度**: $O(n)$，其中 $n$ 是节点数量。我们需要遍历树中的每个节点一次。
- **空间复杂度**: $O(n)$，用于存储图的邻接表和递归调用栈（在最坏情况下，如果树是一条链，调用栈的深度可能达到 $n$）。

## 算法解释

我们使用后序遍历（Post-order traversal）的方式处理树：

1. **构建无向图**：因为题目给出的边没有指明方向，但我们知道节点 0 是根节点，所以我们首先构建一个无向图。

2. **DFS 函数**：

   - 接收当前节点和父节点作为参数
   - 返回一个包含两个值的 pair/tuple：(是否颜色一致, 子树大小)
   - 对于当前节点，首先假设其子树是颜色一致的
   - 然后遍历所有相邻节点（除了父节点）

3. **判断子树是否颜色一致**：

   - 如果任何一个子节点的颜色与当前节点不同，则当前子树不是颜色一致的
   - 如果任何一个子节点的子树不是颜色一致的，则当前子树也不是颜色一致的

4. **更新最大大小**：
   - 如果当前子树是颜色一致的，则更新全局最大大小变量

## 示例演示

以一个简单例子来说明算法流程：

假设有一棵树，节点 0-4，颜色为[1,1,2,2,2]，边为[[0,1], [0,2], [2,3], [2,4]]（即 0 是根节点，连接 1 和 2；2 连接 3 和 4）。

DFS 执行过程：

- 节点 3（父节点 2）：颜色一致，大小 1
- 节点 4（父节点 2）：颜色一致，大小 1
- 节点 2（父节点 0）：颜色一致（和子节点 3、4 都是颜色 2），大小 3
- 节点 1（父节点 0）：颜色一致，大小 1
- 节点 0：不是颜色一致（因为有子节点 1 颜色为 1，子节点 2 颜色为 2）

最大的颜色一致子树是以节点 2 为根的子树，大小为 3。

所以算法返回 3。
