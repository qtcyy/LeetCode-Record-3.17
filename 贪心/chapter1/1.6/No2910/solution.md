# LeetCode 2910: 最小分组数目

## 题目分析

题目要求将具有不同编号的球分到盒子中，需要满足两个条件：

1. 同一个盒子中的球必须有相同的编号
2. 最大的盒子只能比最小的盒子多一个球

目标是返回符合规则的最小盒子数量。

## 解题思路

这个问题可以转化为：对于每个编号，我们需要将相同编号的球分成若干组，每组大小为 `k` 或 `k+1`（最多只相差 1 个），使得最终的总组数最小。

### 关键洞察

1. 对于同一个编号的球，我们必须将它们分成若干个大小为 `k` 或 `k+1` 的组
2. 所有编号的球都必须使用相同的 `k` 值
3. 由于最小频率的编号无法分成比其频率更大的组，因此 `k` 最大只能是最小频率

### 算法步骤

1. 统计每个编号的频率
2. 找出最小频率 `minFreq`
3. 从 `minFreq` 开始递减尝试每个可能的 `k` 值
4. 对于每个 `k`，检查所有编号是否都能有效分组
5. 计算总组数并返回第一个可行解

## 代码解析

```cpp
int minGroupsForValidAssignment(vector<int> &nums) {
  unordered_map<int, int> cnt;
  for (int x : nums) {
    cnt[x]++;  // 统计每个数字的频率
  }

  // 找出最小频率值
  int k = min_element(cnt.begin(), cnt.end(),
               [](const auto &a, const auto &b) {
                 return a.second < b.second;
               })->second;

  // 从k开始递减尝试每个可能的分组大小
  while (k--) {
    int ans = 0;
    for (auto &[_, c] : cnt) {
      if (c / k < c % k) {
        // 无法有效分组
        ans = 0;
        break;
      }
      // 计算这个编号需要的组数并累加
      ans += (c + k) / (k + 1);
    }
    if (ans) {
      return ans;  // 找到可行解，返回结果
    }
  }
  return 0;  // 理论上不会到达这里
}
```

### 核心判断条件解析

最关键的判断条件是 `if (c / k < c % k)`，它用来确定频率为 `c` 的编号是否可以按照当前的 `k` 值有效分组。这个条件实际上是检查：**现有的组数是否足够多，能够容纳所有剩余的球**。

详细解释：

假设我们有 `c` 个相同编号的球，初步尝试将它们分成大小为 `k` 的组：

- `c / k` 表示可以完整分出的大小为 `k` 的组数（整除部分）
- `c % k` 表示分组后剩余的球数（余数部分）

为了处理这些剩余的球，我们需要将一些大小为 `k` 的组"升级"为大小为 `k+1` 的组，每个组增加一个球。因此：

- 需要升级的组数 = 剩余的球数 = `c % k`
- 可用于升级的组数 = 总组数 = `c / k`

如果 `c / k < c % k`，表示可用于升级的组数少于需要升级的组数，这种情况下无法进行有效分组。

#### 举例说明：

1. **可以有效分组的例子**：`c = 7, k = 2`

   - `c / k = 3`（可以分出 3 个大小为 2 的组）
   - `c % k = 1`（还剩 1 个球）
   - 需要升级 1 个组，而我们有 3 个组可用
   - `3 < 1` 不成立，所以条件不触发，可以有效分组
   - 最终分组：[3, 2, 2]（1 个大小为 3 的组，2 个大小为 2 的组）

2. **无法有效分组的例子**：`c = 5, k = 3`

   - `c / k = 1`（可以分出 1 个大小为 3 的组）
   - `c % k = 2`（还剩 2 个球）
   - 需要升级 2 个组，但我们只有 1 个组可用
   - `1 < 2` 成立，所以条件触发，无法有效分组

3. **临界例子**：`c = 8, k = 3`

   - `c / k = 2`（可以分出 2 个大小为 3 的组）
   - `c % k = 2`（还剩 2 个球）
   - 需要升级 2 个组，刚好我们有 2 个组可用
   - `2 < 2` 不成立，所以条件不触发，可以有效分组
   - 最终分组：[4, 4]（2 个大小为 4 的组）

这个判断条件巧妙地检查了分组的可行性，是算法中最关键的部分。若满足条件，我们使用 `ans += (c + k) / (k + 1)` 计算这个编号需要的最少组数，这是将 `c` 除以 `k+1` 并向上取整的简便方法。

## 时间复杂度分析

- 统计频率: O(n)，其中 n 是球的数量
- 找出最小频率: O(m)，其中 m 是不同编号的数量
- 尝试每个可能的 k: O(m \* k)，k 最大为最小频率，通常远小于 n
- 总时间复杂度: O(n + m \* minFreq)，其中 minFreq 是最小频率值

## 空间复杂度分析

- 哈希表存储频率: O(m)，其中 m 是不同编号的数量
- 总空间复杂度: O(m)

## 结论

这是一个贪心算法结合数学证明的问题。关键在于理解：找到一个有效的 `k`，使得所有编号都能分成大小为 `k` 或 `k+1` 的组，并且总组数最小。这个解法巧妙地利用了数学性质来高效地找到最优解。
