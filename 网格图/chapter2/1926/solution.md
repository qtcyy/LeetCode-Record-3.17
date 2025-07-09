# LeetCode 1926. 迷宫中离入口最近的出口

## 题目分析

这是一道经典的 BFS（广度优先搜索）题目。给定一个迷宫矩阵，其中：

- `'.'` 表示可以通行的空地
- `'+'` 表示墙壁
- `entrance` 表示入口位置

要求找到从入口到最近出口的最短路径长度。出口定义为：

1. 在迷宫边界上（第一行、最后一行、第一列、最后一列）
2. 不是入口位置

## 代码问题分析

您的代码存在以下几个问题：

### 1. **队列使用错误**

```python
q = [(entrance[0], entrance[1], 0)]
# ...
x, y, step = q[-1]  # 错误：使用q[-1]而不是q[0]
q.pop()             # 错误：使用pop()而不是pop(0)
```

您使用了`q[-1]`和`q.pop()`，这相当于在使用栈（后进先出）而不是队列（先进先出）。BFS 应该使用队列来保证按层次遍历。

### 2. **边界判断逻辑错误**

```python
if (x, y) != st and (x == 0 or y == 0):
    return step
```

这个判断只检查了`x == 0`或`y == 0`，但忽略了右边界和下边界。正确的边界判断应该是：

```python
if (x, y) != st and (x == 0 or x == n-1 or y == 0 or y == m-1):
```

### 3. **入口标记问题**

代码没有将入口位置标记为已访问，可能导致重复访问。

## 修正后的代码

```python
from typing import List
from collections import deque

class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        n, m = len(maze), len(maze[0])
        entrance_x, entrance_y = entrance[0], entrance[1]

        # 使用deque作为队列，更高效
        q = deque([(entrance_x, entrance_y, 0)])

        # 方向数组：右、下、左、上
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]

        # 标记已访问的位置
        visited = [[False] * m for _ in range(n)]
        visited[entrance_x][entrance_y] = True  # 标记入口为已访问

        while q:
            x, y, step = q.popleft()  # 使用popleft()从队列头部取出

            # 检查是否到达出口（边界且不是入口）
            if (x, y) != (entrance_x, entrance_y) and (x == 0 or x == n-1 or y == 0 or y == m-1):
                return step

            # 向四个方向探索
            for k in range(4):
                nx, ny = x + dx[k], y + dy[k]

                # 检查边界和是否可通行
                if 0 <= nx < n and 0 <= ny < m and maze[nx][ny] == '.' and not visited[nx][ny]:
                    visited[nx][ny] = True
                    q.append((nx, ny, step + 1))

        return -1  # 没有找到出口
```

## 关键改进点

1. **使用正确的队列操作**：`deque`的`popleft()`方法
2. **完整的边界判断**：检查所有四个边界
3. **正确的访问标记**：包括入口位置的标记
4. **更清晰的变量命名**：`nx, ny`表示下一个位置

## 时间复杂度分析

- **时间复杂度**：O(n×m)，其中 n 和 m 是迷宫的行数和列数
- **空间复杂度**：O(n×m)，用于存储访问标记和队列

## 算法思路

1. 从入口开始进行 BFS
2. 每次从队列中取出一个位置，检查是否到达出口
3. 如果到达出口且不是入口，返回步数
4. 否则向四个方向探索，将可达的未访问位置加入队列
5. 如果队列为空仍未找到出口，返回-1

BFS 保证了第一次到达出口时就是最短路径。
