# LeetCode 2770: 达到末尾下标所需的最大跳跃次数

## 题目分析

这个问题给我们一个数组和一个目标值 `target`，要求我们从下标 0 开始，每一步可以跳到满足特定条件的任何后续下标，并求出到达最后一个下标所需的最大跳跃次数。

跳跃的条件是：

- 只能向前跳（`i < j`）
- 两个位置的值差在目标范围内（`-target ≤ nums[j] - nums[i] ≤ target`）

这道题的关键点在于我们需要**最大化**跳跃次数，而不是最小化，这与常见的路径问题不同。

## 解题思路

这是一个典型的动态规划问题：

1. 定义状态：`dp[i]` 表示从下标 0 到下标 i 的最大跳跃次数
2. 初始状态：`dp[0] = 0`（到达起点不需要跳跃）
3. 状态转移：对于每个位置 i，我们考虑所有可能的起跳点 j（其中 j < i）
   - 如果可以从 j 跳到 i（即满足 `-target ≤ nums[i] - nums[j] ≤ target`）
   - 则 `dp[i] = max(dp[i], dp[j] + 1)`
4. 最终答案：如果 `dp[n-1]` 仍为初始值 -1，则无法到达，否则 `dp[n-1]` 就是答案

## C++ 代码实现

```cpp
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // 初始化dp数组，-1表示不可达
        vector<int> dp(n, -1);
        dp[0] = 0;  // 起始位置

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // 如果j可达，且从j到i的跳跃满足条件
                if (dp[j] != -1 && -target <= nums[i] - nums[j] && nums[i] - nums[j] <= target) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n-1];
    }
};
```

## Python 代码实现

```python
class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        n = len(nums)
        # 初始化dp数组，-1表示不可达
        dp = [-1] * n
        dp[0] = 0  # 起始位置

        for i in range(1, n):
            for j in range(i):
                # 如果j可达，且从j到i的跳跃满足条件
                if dp[j] != -1 and -target <= nums[i] - nums[j] <= target:
                    dp[i] = max(dp[i], dp[j] + 1)

        return dp[n-1]
```

## 复杂度分析

- **时间复杂度**：O(n²)，其中 n 是数组长度。我们有两层嵌套循环，外层循环 n 次，内层循环最多 n 次。
- **空间复杂度**：O(n)，用于存储动态规划数组。

## 算法思路解释

这个问题本质上是求一条从起点到终点的路径，使得跳跃次数最多。我们使用动态规划自底向上构建解决方案：

1. 对于每个位置 i，我们考虑所有可能的前驱位置 j
2. 如果从 j 可以跳到 i（两个位置的值差在目标范围内），并且 j 是可达的
3. 我们更新到达 i 的最大跳跃次数

这样一步步构建，最终就能得到到达终点的最大跳跃次数。如果终点不可达，dp 值仍为初始的-1。

以上就是这道题的完整解析，希望对您的算法竞赛备考有所帮助！
