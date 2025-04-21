# LeetCode 2472: 不重叠回文子字符串的最大数目

## 题目分析

这道题要求在字符串 s 中选择最多数量的不重叠回文子字符串，同时满足以下条件：

1. 每个子字符串的长度至少为 k
2. 每个子字符串是回文串（正着读和倒着读相同）
3. 所选的子字符串之间不能重叠

这是一个结合了回文判断和区间调度的动态规划问题。我们需要先找出所有满足条件的回文子字符串，然后找出可以选择的最大数量。

## 解题思路

我们可以将问题分为两个步骤：

1. 预处理：找出所有长度至少为 k 的回文子串
2. 动态规划：计算最多能选择多少个不重叠的回文子串

### 第一步：预处理回文子串

使用动态规划来识别所有回文子串：

- 定义`isPalindrome[i][j]`表示从索引 i 到 j 的子串是否为回文串
- 初始化单个字符和相邻两个字符的情况
- 利用回文串的性质：如果`s[i] == s[j]`且`s[i+1...j-1]`是回文串，那么`s[i...j]`也是回文串

### 第二步：动态规划找最大不重叠数量

- 定义`dp[i]`表示使用字符串 s 的前 i 个字符（索引 0 到 i-1）能够形成的最大不重叠回文子串数量
- 对于每个位置 i，我们有两种选择：
  1. 不使用位置 i-1 结尾的子串：`dp[i] = dp[i-1]`
  2. 使用一个以位置 i-1 结尾的回文子串：尝试所有可能的起始位置 j，使得子串`s[j...i-1]`是一个回文串且长度至少为 k，然后取`dp[j] + 1`的最大值

## 代码实现

### C++实现

```cpp
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();

        // 预处理：找出所有回文子串
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        // 初始化长度为1的回文串
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }

        // 初始化长度为2的回文串
        for (int i = 0; i < n - 1; i++) {
            isPalindrome[i][i+1] = (s[i] == s[i+1]);
        }

        // 填充长度大于2的回文串
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i+1][j-1];
            }
        }

        // 动态规划：找出最大不重叠回文子串数量
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // 不使用位置i-1结尾的子串
            dp[i] = dp[i-1];

            // 尝试使用以位置i-1结尾的回文子串
            for (int j = i - k; j >= 0; j--) {
                if (isPalindrome[j][i-1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};
```

### Python 实现

```python
class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)

        # 预处理：找出所有回文子串
        isPalindrome = [[False] * n for _ in range(n)]

        # 初始化长度为1的回文串
        for i in range(n):
            isPalindrome[i][i] = True

        # 初始化长度为2的回文串
        for i in range(n - 1):
            isPalindrome[i][i+1] = (s[i] == s[i+1])

        # 填充长度大于2的回文串
        for length in range(3, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                isPalindrome[i][j] = (s[i] == s[j] and isPalindrome[i+1][j-1])

        # 动态规划：找出最大不重叠回文子串数量
        dp = [0] * (n + 1)

        for i in range(1, n + 1):
            # 不使用位置i-1结尾的子串
            dp[i] = dp[i-1]

            # 尝试使用以位置i-1结尾的回文子串
            for j in range(i - k, -1, -1):
                if isPalindrome[j][i-1]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return dp[n]
```

## 代码优化

我们可以对代码进行一些优化：

1. 只需要检查长度大于等于 k 的回文子串
2. 当找到一个以 i-1 结尾的回文子串后，可以立即更新 dp[i]并跳出内层循环（贪心优化）

### 优化后的 C++代码

```cpp
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();

        // 预处理：找出所有回文子串
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        // 初始化长度为1的回文串
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }

        // 初始化长度为2的回文串
        for (int i = 0; i < n - 1; i++) {
            isPalindrome[i][i+1] = (s[i] == s[i+1]);
        }

        // 填充长度大于2的回文串
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i+1][j-1];
            }
        }

        // 动态规划：找出最大不重叠回文子串数量
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // 不使用位置i-1结尾的子串
            dp[i] = dp[i-1];

            // 尝试使用以位置i-1结尾的回文子串，按照长度从大到小尝试（贪心策略）
            for (int len = k; len <= i; len++) {
                int j = i - len;
                if (j >= 0 && isPalindrome[j][i-1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    break;  // 找到一个最长的就可以跳出（贪心优化）
                }
            }
        }

        return dp[n];
    }
};
```

注意：上面的贪心优化（找到一个最长的回文就跳出）在这个问题中可能不总是正确的。因为有时选择多个较短的回文可能比选择一个长回文更优。所以我们应该保留原始解法。

## 算法分析

### 时间复杂度

- 预处理回文子串：O(n²)
- 动态规划找最大不重叠数量：O(n²)
- 总时间复杂度：O(n²)

### 空间复杂度

- isPalindrome 数组：O(n²)
- dp 数组：O(n)
- 总空间复杂度：O(n²)

## 示例分析

让我们用一个例子分析算法：
s = "abaccdbbd", k = 3

1. 预处理回文子串:

   - 长度为 3 的回文子串：("aba", "bdb")
   - 长度为 4 的回文子串：("acca")
   - 没有更长的回文子串

2. 动态规划:
   - dp[0] = 0
   - dp[1] = 0
   - ...
   - dp[3] = 1 (使用回文子串"aba" [0-2])
   - dp[4] = 1
   - dp[5] = 1
   - dp[6] = 1
   - dp[7] = 2 (使用回文子串"aba" [0-2]和"acca" [3-6])
   - dp[8] = 2
   - dp[9] = 3 (使用回文子串"aba" [0-2], "acca" [3-6]和"bdb" [6-8])

所以最大不重叠回文子串数量是 3。

## 总结

1. 我们使用动态规划找出所有回文子串
2. 然后用另一层动态规划找出最大不重叠回文子串数量
3. 关键是定义状态转移方程：dp[i] = max(dp[i-1], dp[j] + 1)，其中 j 是满足条件的回文子串的起始位置
4. 优化时可以按长度从大到小尝试，但不能使用贪心策略立即跳出循环

这个解决方案能够高效地解决不重叠回文子字符串的最大数目问题。
