# LeetCode 934. 最短的桥

## 题目描述

给你一个大小为 n x n 的二元矩阵 grid，其中 1 表示陆地，0 表示水域。

岛是由四面相连的 1 形成的一个最大组，即不会与非组内的任何其他 1 相连。grid 中恰好存在两座岛。

你可以将任意数量的 0 变为 1，以使两座岛连接起来，变成一座岛。

返回必须翻转的 0 的最小数目。

## 解题思路

这是一个典型的**最短路径问题**，可以通过**DFS + BFS**的组合来解决：

### 核心思想

1. **找到第一个岛屿**：用 DFS 遍历找到第一个岛屿的所有格子
2. **标记第一个岛屿**：将第一个岛屿的所有格子标记为特殊值（如 2），与第二个岛屿区分
3. **多源 BFS**：从第一个岛屿的边界开始 BFS，向外扩展寻找第二个岛屿
4. **计算最短距离**：当 BFS 到达第二个岛屿时，返回扩展的层数

### 详细步骤

#### 第一步：找到并标记第一个岛屿

- 遍历矩阵找到第一个值为 1 的格子
- 用 DFS 将整个岛屿的所有格子标记为 2
- 在 DFS 过程中收集岛屿的边界格子（与水域相邻的陆地格子）

#### 第二步：从第一个岛屿边界开始 BFS

- 将第一个岛屿的所有边界格子加入 BFS 队列
- 每次 BFS 扩展到相邻的水域格子（值为 0）
- 记录 BFS 的层数，代表需要翻转的 0 的数量

#### 第三步：找到第二个岛屿

- 当 BFS 扩展到值为 1 的格子时，说明找到了第二个岛屿
- 此时的 BFS 层数就是连接两个岛屿需要翻转的最少 0 的数目

## 算法实现

```cpp
class Solution {
private:
    int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    // DFS标记第一个岛屿，并收集边界
    void dfs(vector<vector<int>>& grid, int x, int y, queue<pair<int,int>>& boundary) {
        int n = grid.size();
        grid[x][y] = 2; // 标记为第一个岛屿

        // 检查是否为边界格子（与水域相邻）
        bool isBoundary = false;
        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (grid[nx][ny] == 0) {
                    isBoundary = true;
                } else if (grid[nx][ny] == 1) {
                    dfs(grid, nx, ny, boundary);
                }
            }
        }

        if (isBoundary) {
            boundary.push({x, y});
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> boundary;

        // 第一步：找到第一个岛屿并标记
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, boundary);
                    found = true;
                }
            }
        }

        // 第二步：从第一个岛屿边界开始BFS
        int steps = 0;
        while (!boundary.empty()) {
            int size = boundary.size();

            for (int i = 0; i < size; i++) {
                auto [x, y] = boundary.front();
                boundary.pop();

                for (int j = 0; j < 4; j++) {
                    int nx = x + directions[j][0];
                    int ny = y + directions[j][1];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (grid[nx][ny] == 1) {
                            // 找到第二个岛屿
                            return steps;
                        } else if (grid[nx][ny] == 0) {
                            // 扩展到水域
                            grid[nx][ny] = 2;
                            boundary.push({nx, ny});
                        }
                    }
                }
            }
            steps++;
        }

        return steps;
    }
};
```

## 复杂度分析

- **时间复杂度**：O(n²)

  - DFS 遍历第一个岛屿：O(岛屿大小)
  - BFS 遍历整个矩阵：O(n²)
  - 总体时间复杂度为 O(n²)

- **空间复杂度**：O(n²)
  - BFS 队列最多存储 O(n²)个格子
  - DFS 递归栈深度最多为 O(n²)

## 关键点总结

1. **两阶段算法**：先 DFS 标记第一个岛屿，再 BFS 寻找最短路径
2. **边界处理**：正确识别第一个岛屿的边界格子是关键
3. **多源 BFS**：从整个岛屿边界同时开始 BFS，保证找到最短距离
4. **状态标记**：用不同数值区分第一个岛屿(2)、第二个岛屿(1)和水域(0)

这种解法巧妙地将连接两个岛屿的问题转化为从一个岛屿到另一个岛屿的最短路径问题，是网格图 BFS 的经典应用。
