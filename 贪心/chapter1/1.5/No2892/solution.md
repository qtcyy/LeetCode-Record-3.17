# LeetCode 题解：数组相邻元素合并

## 题目描述

给定一个整数数组 nums 和一个整数 k，你可以对数组执行以下操作任意次数：

选择数组中的两个 相邻 元素，例如 x 和 y，使得 x _ y <= k ，并用一个值为 x _ y 的 单个元素 替换它们。

返回 经过任意次数的操作后， nums 的 最小 可能长度。

## 动态规划解法

这是一个区间 DP 问题。我们定义状态`dp[i][j]`表示将子数组`nums[i...j]`通过操作后能达到的最小长度。

### 状态定义

- `dp[i][j]` = 将区间 `[i,j]` 内的元素通过合并操作后得到的最小长度

### 初始状态

- 当 `i == j` 时，`dp[i][j] = 1`（单个元素无法再合并）

### 状态转移方程

对于区间 `[i,j]` 我们可以枚举分割点 `k`，其中 `i ≤ k < j`：

- `dp[i][j] = min(dp[i][k] + dp[k+1][j])` 表示不合并 `k` 和 `k+1` 位置的元素
- 如果区间 `[i,k]` 和 `[k+1,j]` 都已经被合并为单个元素（即 `dp[i][k] = dp[k+1][j] = 1`），并且这两个元素的乘积满足 `nums[i...k] * nums[k+1...j] ≤ k`，则可以将它们进一步合并，此时 `dp[i][j] = 1`

### 实现代码

```cpp
class Solution {
public:
    int minArrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        // val[i][j] 表示区间[i,j]合并后的值
        vector<vector<long long>> val(n, vector<long long>(n, 0));
        // dp[i][j] 表示区间[i,j]的最小长度
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // 初始化单个元素的情况
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            val[i][i] = nums[i];
        }

        // 区间长度从2到n
        for (int len = 2; len <= n; len++) {
            // 枚举区间起点
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;  // 区间终点

                // 枚举分割点
                for (int m = i; m < j; m++) {
                    int currentLen = dp[i][m] + dp[m+1][j];

                    // 如果两个子区间都已经合并成单个元素，且乘积不超过k
                    if (dp[i][m] == 1 && dp[m+1][j] == 1 && val[i][m] * val[m+1][j] <= k) {
                        val[i][j] = val[i][m] * val[m+1][j];
                        dp[i][j] = 1;
                        break;  // 已经找到最优解
                    } else if (currentLen < dp[i][j]) {
                        dp[i][j] = currentLen;
                        // 如果不能合并，val[i][j]的值无关紧要
                    }
                }
            }
        }

        return dp[0][n-1];
    }
};
```

### 时间复杂度分析

- 时间复杂度：O(n³)，其中 n 是数组的长度。我们需要计算所有长度为 1 到 n 的区间，每个区间还需要枚举分割点。
- 空间复杂度：O(n²)，需要两个 n×n 的二维数组来存储 dp 值和区间合并后的值。

### 优化思路

上述实现中有一个问题：当区间 `[i,m]` 和 `[m+1,j]` 都已合并成单个元素并且可以继续合并时，我们需要更新 `val[i][j]`，但如果这两个子区间无法合并成单个元素，`val[i][j]` 的值就没有实际意义。

在实际实现中，我们只在成功合并为单个元素时才会更新 `val[i][j]` 的值，否则该值可以保持不变（或设为无效值）。

## 贪心算法解法

对于这个问题，我们也可以使用贪心策略来解决。直觉上，我们希望尽可能多地合并元素，以最小化数组的长度。

### 贪心策略

1. 使用栈来模拟合并过程
2. 对于每个元素，尝试与栈顶元素合并
3. 如果可以合并（乘积不超过 k），则弹出栈顶元素并将合并后的元素入栈
4. 否则，当前元素直接入栈

### 实现代码

```cpp
class Solution {
public:
    int minArrayLength(vector<int>& nums, int k) {
        if (nums.empty()) return 0;

        vector<int> stack;
        stack.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            // 如果栈非空且栈顶元素与当前元素的乘积不超过k
            if (!stack.empty() && (long long)stack.back() * nums[i] <= k) {
                int top = stack.back();
                stack.pop_back();
                // 合并后的元素入栈
                stack.push_back(top * nums[i]);
            } else {
                // 无法合并，当前元素直接入栈
                stack.push_back(nums[i]);
            }
        }

        return stack.size();
    }
};
```

### 为什么贪心有效

我们可以证明贪心算法能够得到最优解：

1. 如果当前元素与栈顶元素可以合并，那么合并它们总是比不合并更好，因为这减少了数组的长度
2. 问题要求相邻元素才能合并，所以我们只需要考虑栈顶元素（最近的未被合并的元素）
3. 对于每个新元素，我们总是尝试与之前的元素合并，这保证了我们不会错过任何合并机会

### 时间复杂度分析

- 时间复杂度：O(n)，其中 n 是数组的长度。我们只需要遍历数组一次。
- 空间复杂度：O(n)，最坏情况下栈需要存储原数组的所有元素。

### 贪心与动态规划比较

1. 贪心算法时间复杂度为 O(n)，而动态规划方法为 O(n³)，贪心算法效率更高
2. 贪心算法实现更简单，代码量更少
3. 对于这个问题，贪心算法可以得到最优解，但对于一般问题，贪心不一定总是正确的

由于贪心算法在这个问题上具有正确性且效率更高，因此它是解决此问题的首选方法。
