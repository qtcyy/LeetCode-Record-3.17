# LeetCode 1335: 工作计划的最低难度

## 题目分析

这道题目要求我们将 n 个工作分配到 d 天中，满足以下条件：

1. 工作必须按顺序完成（即第 i 个工作必须在第 j 个工作之后完成，其中 j < i）
2. 每天至少要完成一项工作
3. 一天的难度等于当天所做工作中最大的难度值
4. 工作计划的总难度是 d 天难度的总和

我们需要找出总难度最小的工作安排方案。如果无法满足条件（例如工作数量少于天数），则返回-1。

## 解题思路

这是一个典型的动态规划问题，我们可以定义状态并寻找状态转移方程：

1. 定义状态：`dp[i][j]` 表示将前 i 个工作分配到 j 天内所能达到的最小总难度
2. 目标：计算 `dp[n][d]`，即将所有 n 个工作分配到 d 天内的最小总难度
3. 基本情况：如果工作数量少于天数（n < d），返回-1
4. 状态转移：对于每个状态 `dp[i][j]`，我们需要决定第 j 天从哪个工作开始

### 状态转移分析

对于状态 `dp[i][j]`（表示前 i 个工作在 j 天内的最小总难度），我们可以枚举第 j 天的起始工作位置 k：

- 第 j 天包含工作[k, k+1, ..., i-1]
- 前 j-1 天包含工作[0, 1, ..., k-1]
- 第 j 天的难度是 `max(jobDifficulty[k], jobDifficulty[k+1], ..., jobDifficulty[i-1])`
- 前 j-1 天的最小总难度是 `dp[k][j-1]`

状态转移方程：

```
dp[i][j] = min(dp[k][j-1] + max(jobDifficulty[k...i-1])) 对所有 j-1 <= k < i
```

## C++实现

```cpp
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        // 边界情况：工作数量少于天数，不可能完成
        if (n < d) return -1;

        // dp[i][j] = 前i个工作在j天内的最小总难度
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2)); // 避免溢出

        // 基础情况：0个工作0天的难度为0
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, d); j++) {
                // 尝试不同的分割点，决定第j天从哪个工作开始
                int maxDifficulty = 0;
                for (int k = i - 1; k >= j - 1; k--) {
                    // maxDifficulty是第j天工作的最大难度（工作k到i-1）
                    maxDifficulty = max(maxDifficulty, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[k][j-1] + maxDifficulty);
                }
            }
        }

        return dp[n][d];
    }
};
```

## Python 实现

```python
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)

        # 边界情况：工作数量少于天数，不可能完成
        if n < d:
            return -1

        # dp[i][j] = 前i个工作在j天内的最小总难度
        dp = [[float('inf')] * (d + 1) for _ in range(n + 1)]

        # 基础情况：0个工作0天的难度为0
        dp[0][0] = 0

        for i in range(1, n + 1):
            for j in range(1, min(i, d) + 1):
                # 尝试不同的分割点，决定第j天从哪个工作开始
                max_difficulty = 0
                for k in range(i - 1, j - 2, -1):
                    # max_difficulty是第j天工作的最大难度（工作k到i-1）
                    max_difficulty = max(max_difficulty, jobDifficulty[k])
                    dp[i][j] = min(dp[i][j], dp[k][j-1] + max_difficulty)

        return dp[n][d]
```

## 解题分析与优化

### 时间复杂度

- 总时间复杂度：O(n²d)，其中 n 是工作数量，d 是天数
  - 三重循环：i 从 1 到 n，j 从 1 到 d，k 从 i-1 到 j-1
  - 在实际情况中，由于 j<=min(i,d)，所以复杂度会小于 O(n²d)

### 空间复杂度

- 空间复杂度：O(nd)，用于存储动态规划表

### 示例演示

考虑示例：jobDifficulty = [6, 5, 4, 3, 2, 1], d = 2

1. 首先，n = 6，检查 n >= d，条件满足
2. 初始化 dp 数组，设置 dp[0][0] = 0
3. 开始填充 dp 表：

   - dp[1][1] = 6（第一个工作在第一天完成）
   - dp[2][1] = 6（前两个工作在一天内完成，最大难度是 6）
   - ...
   - dp[6][1] = 6（所有工作在一天内完成，最大难度是 6）

   - dp[2][2] = 11（工作 1 在第一天，工作 2 在第二天：6+5=11）
   - dp[3][2] = 10（工作 1-2 在第一天，工作 3 在第二天：6+4=10）
   - dp[4][2] = 9（工作 1-3 在第一天，工作 4 在第二天：6+3=9）
   - dp[5][2] = 8（工作 1-4 在第一天，工作 5 在第二天：6+2=8）
   - dp[6][2] = 7（工作 1-5 在第一天，工作 6 在第二天：6+1=7）

4. 最终结果是 dp[6][2] = 7

## 总结

这道题展示了动态规划解决工作调度类问题的典型应用。关键点在于：

1. 明确定义状态：前 i 个工作在 j 天内的最小总难度
2. 找出合适的状态转移：尝试所有可能的分割点，决定每一天应该做哪些工作
3. 处理好边界条件：工作数少于天数时直接返回-1
4. 优化计算过程：在计算最大难度时使用增量方式而非重复计算

这种解决方案可以高效地找出工作计划的最低难度，时间复杂度为 O(n²d)，空间复杂度为 O(nd)。
