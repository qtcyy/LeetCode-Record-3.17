# 代码问题分析与修复

## 问题分析

原代码中存在两个主要问题：

1. 在寻找合适的行进行交换时，代码找到了满足条件的行后没有立即跳出循环，而是继续查找并更新`pos`，这会导致选择的行不是最近的符合条件的行，从而增加交换次数。

2. 更关键的是，代码使用`insert`和`erase`操作来移动行，这不符合题目要求。题目规定只能交换相邻的两行，而当前的操作直接将找到的行移动到目标位置，实际上不是通过相邻行交换实现的。

## 修复后的代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSwaps(vector<vector<int>> &grid) {
    int n = grid.size();
    int ans = 0;

    // 统计每行末尾连续0的个数
    vector<int> trailingZeros(n);
    for (int i = 0; i < n; i++) {
      int zeros = 0;
      for (int j = n - 1; j >= 0; j--) {
        if (grid[i][j] == 0)
          zeros++;
        else
          break;
      }
      trailingZeros[i] = zeros;
    }

    // 对每一行进行处理
    for (int i = 0; i < n; i++) {
      // 当前行需要的连续0个数
      int need = n - i - 1;

      // 如果当前行已满足条件，继续处理下一行
      if (trailingZeros[i] >= need) continue;

      // 寻找下方第一个满足条件的行
      int j;
      for (j = i + 1; j < n; j++) {
        if (trailingZeros[j] >= need) break;
      }

      // 如果没找到满足条件的行，返回-1
      if (j == n) return -1;

      // 通过相邻行交换，将满足条件的行移到位置i
      for (int k = j; k > i; k--) {
        swap(trailingZeros[k], trailingZeros[k-1]);
        swap(grid[k], grid[k-1]);
        ans++;
      }
    }

    return ans;
  }
};

signed main() {
  vector<vector<int>> grid = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};
  Solution sol;
  cout << sol.minSwaps(grid) << endl;
}
```

## 修复说明

1. 预处理阶段：计算每一行末尾连续零的个数，这样可以快速判断一行是否满足条件。

2. 对于每一行 i，我们需要满足对角线以上（即右侧）有足够的零，即至少需要 n-i-1 个末尾连续零。

3. 如果当前行不满足条件，从下方找到第一个满足条件的行。

4. 使用相邻行交换（符合题目要求）将找到的行移动到当前位置。

5. 统计交换次数并返回结果。

这个修复后的代码解决了原代码的两个主要问题，并且正确实现了题目要求的操作方式。
