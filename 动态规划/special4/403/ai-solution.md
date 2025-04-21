# LeetCode 403: 青蛙过河

## 题目分析

这道题目描述了一只青蛙过河的问题，其中：

- 青蛙初始站在第一块石头上（`stones[0]`）
- 第一步只能跳 1 个单位
- 如果上一步跳了 k 个单位，下一步只能跳 k-1、k 或 k+1 个单位
- 青蛙只能向前跳
- 青蛙不能跳入水中（必须跳到石头上）

我们需要判断青蛙能否成功跳到最后一块石头。

这是一个动态规划问题，其中状态与当前位置和上一步的跳跃距离有关。让我详细讲解两种解法。

## 方法一：记忆化搜索

记忆化搜索是自顶向下的动态规划方法，通过递归实现，并用缓存避免重复计算。

### 思路

1. 我们定义状态为 `(i, k)`，表示"青蛙当前在第 i 个石头，上一步跳了 k 个单位"
2. 对于每个状态，青蛙可以尝试跳 k-1、k 或 k+1 个单位
3. 使用哈希表记录已经计算过的状态，避免重复计算

### C++实现

```cpp
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        // 创建哈希表，快速查找石头位置
        unordered_map<int, int> posToIdx;
        for (int i = 0; i < n; i++) {
            posToIdx[stones[i]] = i;
        }

        // 记忆化数组，memo[i][k]表示从石头i开始，上一步跳了k个单位，能否到达终点
        unordered_map<int, unordered_map<int, bool>> memo;

        return dfs(0, 0, stones, posToIdx, memo);
    }

    bool dfs(int idx, int k, vector<int>& stones, unordered_map<int, int>& posToIdx,
             unordered_map<int, unordered_map<int, bool>>& memo) {
        // 基本情况：已到达最后一块石头
        if (idx == stones.size() - 1) {
            return true;
        }

        // 检查是否已计算过这个状态
        if (memo.count(idx) && memo[idx].count(k)) {
            return memo[idx][k];
        }

        // 尝试所有可能的跳跃距离：k-1, k, k+1
        for (int jump : {k - 1, k, k + 1}) {
            // 跳跃距离必须为正
            if (jump > 0) {
                // 计算下一个位置
                int nextPos = stones[idx] + jump;

                // 检查该位置是否有石头
                if (posToIdx.count(nextPos)) {
                    int nextIdx = posToIdx[nextPos];
                    // 确保只向前跳
                    if (nextIdx > idx) {
                        // 递归搜索
                        if (dfs(nextIdx, jump, stones, posToIdx, memo)) {
                            // 记录成功状态
                            memo[idx][k] = true;
                            return true;
                        }
                    }
                }
            }
        }

        // 记录失败状态
        memo[idx][k] = false;
        return false;
    }
};
```

### Python 实现

```python
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)

        # 创建哈希表，快速查找石头位置
        stone_idx_map = {stone: i for i, stone in enumerate(stones)}

        # 记忆化搜索缓存
        memo = {}

        def dfs(idx, k):
            # 基本情况：已到达最后一块石头
            if idx == n - 1:
                return True

            # 检查是否已计算过这个状态
            if (idx, k) in memo:
                return memo[(idx, k)]

            # 尝试所有可能的跳跃距离：k-1, k, k+1
            for jump in [k - 1, k, k + 1]:
                if jump > 0:
                    # 计算下一个位置
                    next_pos = stones[idx] + jump

                    # 检查该位置是否有石头
                    if next_pos in stone_idx_map:
                        next_idx = stone_idx_map[next_pos]
                        # 确保只向前跳
                        if next_idx > idx:
                            # 递归搜索
                            if dfs(next_idx, jump):
                                # 记录成功状态
                                memo[(idx, k)] = True
                                return True

            # 记录失败状态
            memo[(idx, k)] = False
            return False

        # 从第一个石头开始，初始跳跃距离为0
        return dfs(0, 0)
```

## 方法二：DP 递推

DP 递推是自底向上的动态规划方法，通过迭代实现。

### 思路

1. 定义状态 `dp[i][j]` 表示"能否到达第 i 个石头，且上一步跳了 j 个单位"
2. 初始状态：`dp[0][0] = true`（青蛙一开始站在第一块石头上，上一步跳跃距离视为 0）
3. 对于每个可达的状态 `dp[i][j] = true`，尝试三种跳跃距离 j-1、j、j+1
4. 检查是否能到达最后一块石头

### C++实现

```cpp
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        // 第一步必须是跳1个单位，如果第二个石头不在位置1，直接返回false
        if (n > 1 && stones[1] != 1) {
            return false;
        }

        // 创建哈希表，快速查找石头位置
        unordered_map<int, int> posToIdx;
        for (int i = 0; i < n; i++) {
            posToIdx[stones[i]] = i;
        }

        // 创建DP数组，dp[i][j]表示能否到达第i个石头，且上一步跳了j个单位
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));

        // 初始状态：青蛙站在第一个石头上，上一步跳了0个单位
        dp[0][0] = true;

        // 填充DP数组
        for (int i = 0; i < n; i++) {
            for (int k = 0; k <= n; k++) {
                if (dp[i][k]) {  // 如果能够到达位置i，且上一步跳了k个单位
                    // 尝试跳 k-1, k, k+1 个单位
                    for (int jump : {k - 1, k, k + 1}) {
                        if (jump > 0) {
                            // 计算下一个位置
                            int nextPos = stones[i] + jump;

                            // 检查该位置是否有石头
                            if (posToIdx.count(nextPos)) {
                                int nextIdx = posToIdx[nextPos];
                                if (nextIdx > i) {  // 确保只向前跳
                                    dp[nextIdx][jump] = true;

                                    // 如果已到达最后一块石头，提前返回
                                    if (nextIdx == n - 1) {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // 检查是否能到达最后一块石头（遍历所有可能的跳跃距离）
        for (int k = 0; k <= n; k++) {
            if (dp[n - 1][k]) {
                return true;
            }
        }

        return false;
    }
};
```

### Python 实现

```python
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)

        # 第一步必须是跳1个单位，如果第二个石头不在位置1，直接返回false
        if n > 1 and stones[1] != 1:
            return False

        # 创建哈希表，快速查找石头位置
        stone_idx_map = {stone: i for i, stone in enumerate(stones)}

        # 创建DP数组，dp[i][j]表示能否到达第i个石头，且上一步跳了j个单位
        dp = [[False] * (n + 1) for _ in range(n)]

        # 初始状态：青蛙站在第一个石头上，上一步跳了0个单位
        dp[0][0] = True

        # 填充DP数组
        for i in range(n):
            for k in range(n + 1):
                if dp[i][k]:  # 如果能够到达位置i，且上一步跳了k个单位
                    # 尝试跳 k-1, k, k+1 个单位
                    for jump in [k - 1, k, k + 1]:
                        if jump > 0:
                            # 计算下一个位置
                            next_pos = stones[i] + jump

                            # 检查该位置是否有石头
                            if next_pos in stone_idx_map:
                                next_idx = stone_idx_map[next_pos]
                                if next_idx > i:  # 确保只向前跳
                                    dp[next_idx][jump] = True

                                    # 如果已到达最后一块石头，提前返回
                                    if next_idx == n - 1:
                                        return True

        # 检查是否能到达最后一块石头
        return any(dp[n - 1])
```

## 算法优化与细节分析

1. **提前判断**：如果第二个石头不在位置 1，那么青蛙一定无法从第一个石头跳到任何地方，可以提前返回 false。

2. **哈希表优化**：我们使用哈希表来快速查找位置对应的索引，避免每次都在数组中线性查找，大大提高了效率。

3. **状态定义**：在记忆化搜索和 DP 递推中，我们都使用了"当前位置"和"上一步跳跃距离"来定义状态，这样能够完整表示青蛙的跳跃过程。

4. **提前返回**：在填充 DP 数组时，一旦发现能够到达最后一块石头，就可以提前返回 true，无需继续计算。

## 时间与空间复杂度

**记忆化搜索**：

- 时间复杂度：O(n²)，每个状态 (i, k) 最多计算一次，总共有 O(n²) 个状态
- 空间复杂度：O(n²)，用于存储记忆化数组

**DP 递推**：

- 时间复杂度：O(n²)，需要填充 O(n²) 个状态，每个状态的计算需要 O(1) 时间
- 空间复杂度：O(n²)，用于存储 DP 数组

两种方法在渐进复杂度上相同，但在实际运行中，记忆化搜索可能更快，因为它不会计算所有不可达的状态。而 DP 递推则更为直观，容易理解。

希望这份详细的解析能够帮助你理解这个问题！
