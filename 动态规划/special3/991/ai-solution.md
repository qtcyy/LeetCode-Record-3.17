# 坏了的计算器问题解析

## 问题概述

给定两个整数 `startValue` 和 `target`，我们需要通过以下两种操作将 `startValue` 变成 `target`：

1. 双倍（Double）：将数字乘以 2
2. 递减（Decrement）：将数字减 1

要求返回最小操作次数。

## 解题思路：逆向思考

这个问题看似可以用广度优先搜索(BFS)求解，但有一个更巧妙的方法：**从 `target` 开始反向操作**。

当我们反向考虑时，可用的操作变成了：

- 除以 2（对应正向的乘以 2）
- 加 1（对应正向的减 1）

### 关键洞察

1. 当 `target > startValue` 时：

   - 如果 `target` 是偶数，最优操作是将其除以 2（对应正向的乘以 2）
   - 如果 `target` 是奇数，我们必须先加 1 再除以 2（对应正向的先减 1 再乘以 2）

2. 当 `target <= startValue` 时：
   - 只能通过减法（对应反向的加法）来达到目标

### 算法步骤

1. 如果 `startValue >= target`，直接返回 `startValue - target`（需要的减法次数）
2. 当 `target > startValue` 时，重复以下步骤：
   - 如果 `target` 是偶数，将 `target` 除以 2，操作次数加 1
   - 如果 `target` 是奇数，将 `target` 加 1，操作次数加 1
3. 最后，如果 `target < startValue`，还需要加上 `startValue - target` 次操作

## 代码实现

```cpp
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // 情况1: 起始值大于或等于目标值，只能使用递减操作
        if (startValue >= target) {
            return startValue - target;
        }

        int operations = 0;

        // 情况2: 从目标值反向工作到起始值
        while (target > startValue) {
            if (target % 2 == 0) {
                // 目标是偶数，除以2（反向的乘以2操作）
                target /= 2;
            } else {
                // 目标是奇数，加1（反向的减1操作）
                target += 1;
            }
            operations++;
        }

        // 情况3: 如果反向操作后target小于startValue，需要额外的递减操作
        return operations + (startValue - target);
    }
};
```

## 复杂度分析

- **时间复杂度**：O(log(target))
  - 每次操作都会将 `target` 除以 2 或加 1，而除以 2 的操作会显著减小数值，所以最多需要 O(log(target)) 次操作
- **空间复杂度**：O(1)
  - 只使用了常数额外空间

## 示例分析

让我们通过两个例子来理解这个算法：

### 示例 1: startValue = 2, target = 10

从 `target = 10` 开始反向操作：

1. `target = 10`（偶数）→ 除以 2 → `target = 5`, 操作次数 = 1
2. `target = 5`（奇数）→ 加 1 → `target = 6`, 操作次数 = 2
3. `target = 6`（偶数）→ 除以 2 → `target = 3`, 操作次数 = 3
4. `target = 3`（奇数）→ 加 1 → `target = 4`, 操作次数 = 4
5. `target = 4`（偶数）→ 除以 2 → `target = 2`, 操作次数 = 5
6. `target = 2 = startValue`，完成

总操作次数：5

### 示例 2: startValue = 5, target = 8

从 `target = 8` 开始反向操作：

1. `target = 8`（偶数）→ 除以 2 → `target = 4`, 操作次数 = 1
2. 现在 `target = 4 < startValue = 5`，需要额外 5 - 4 = 1 次操作

总操作次数：1 + 1 = 2

## 为什么这种方法有效？

这个问题的关键在于，从 `startValue` 到 `target` 的路径可能不直观，但从 `target` 反向操作到 `startValue` 却非常明确：

1. 对于偶数，我们总是选择除以 2 而不是加 1，因为乘法操作（在正向思考中）可以更快地接近目标
2. 对于奇数，我们只能加 1 然后再除以 2，因为无法直接将奇数除以 2
3. 通过这种贪心策略，我们保证了操作次数的最小化

此算法的优雅之处在于，我们通过逆向思考把一个看似需要搜索的问题转化为了一个简单的贪心算法。
