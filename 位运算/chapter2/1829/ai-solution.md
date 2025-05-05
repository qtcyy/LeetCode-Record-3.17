# LeetCode 1829. 每个查询的最大异或值

## 题目理解

题目给我们一个有序的非负整数数组`nums`和一个整数`maximumBit`，需要执行`n`次查询（`n`是数组长度）：

1. 找到一个非负整数`k < 2^maximumBit`，使得`nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k`的结果最大化
2. 删除数组中的最后一个元素
3. 重复以上操作，直到数组为空

返回每次查询的结果`k`。

## 解题思路

要找到使异或结果最大化的`k`，需要理解异或的性质。对于异或操作，如果我们希望结果最大，那么需要尽可能多的位为 1，特别是高位。

由于`k < 2^maximumBit`，我们只能影响结果的低`maximumBit`位。所以，如果要使最终结果的低`maximumBit`位全为 1，`k`应该满足:

`(nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1]) XOR k = (2^maximumBit - 1)`

解这个等式，得到：
`k = (nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1]) XOR (2^maximumBit - 1)`

## 算法分析

### 解法详解

1. 初始化掩码 `mask = (1 << maximumBit) - 1`，即低 `maximumBit` 位全为 1
2. 计算原始数组的异或和 `xorSum`
3. 对于每次查询：
   - 计算 `k = xorSum ^ mask`，这样可以保证 `xorSum ^ k` 的低 `maximumBit` 位全为 1，从而最大化结果
   - 更新 `xorSum` 以移除最后一个元素的影响：`xorSum ^= nums[n-1-i]`
   - 将 `k` 加入答案数组

### 异或运算的关键性质

为什么 `k = xorSum ^ mask` 能使结果最大化？

- 对于异或运算，如果 `a ^ b = c`，则 `a ^ c = b` 和 `b ^ c = a`
- 我们希望最终结果 `xorSum ^ k` 的低 `maximumBit` 位全为 1（即等于 `mask`）
- 因此，`xorSum ^ k = mask`
- 解得 `k = xorSum ^ mask`

### 复杂度分析

- **时间复杂度**：O(n)，其中 n 是数组长度。我们计算一次初始异或和，然后处理每次查询，每次只需 O(1)操作。
- **空间复杂度**：O(n)，用于存储答案数组。

## 示例演示

以示例 `nums = [0,1,1,3]` 和 `maximumBit = 2` 来演示算法：

1. 计算掩码：`mask = (1 << 2) - 1 = 3`（二进制为 `11`）
2. 计算异或和：`xorSum = 0 ^ 1 ^ 1 ^ 3 = 3`
3. 第一次查询：
   - `k = xorSum ^ mask = 3 ^ 3 = 0`
   - 从 `xorSum` 移除最后一个元素：`xorSum = 3 ^ 3 = 0`
4. 第二次查询：
   - `k = xorSum ^ mask = 0 ^ 3 = 3`
   - 从 `xorSum` 移除最后一个元素：`xorSum = 0 ^ 1 = 1`
5. 第三次查询：
   - `k = xorSum ^ mask = 1 ^ 3 = 2`
   - 从 `xorSum` 移除最后一个元素：`xorSum = 1 ^ 1 = 0`
6. 第四次查询：
   - `k = xorSum ^ mask = 0 ^ 3 = 3`

因此，答案是 `[0, 3, 2, 3]`。

## 总结

这道题目考察了异或运算的性质以及如何最大化异或结果。关键思路是找到合适的 `k` 使得异或结果的低 `maximumBit` 位全为 1，并且高效地处理数组元素的删除操作。通过维护异或和，我们可以避免重复计算，实现 O(n)的时间复杂度。
