# 2.3 求子数组个数

## 2.3.1 越长越合法

一般要写 ans += left。

滑动窗口的内层循环结束时，右端点固定在 right，左端点在 0,1,2,…,left−1 的所有子数组（子串）都是合法的，这一共有 left 个。

**题目列表**

- [1358. 包含所有三种字符的子字符串数目](https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/description/)
- [2962. 统计最大元素出现至少 K 次的子数组](https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/)
- [3325. 字符至少出现 K 次的子字符串 I](https://leetcode.cn/problems/count-substrings-with-k-frequency-characters-i/description/)
- [2799. 统计完全子数组的数目](https://leetcode.cn/problems/count-complete-subarrays-in-an-array/description/)
- [2537. 统计好子数组的数目](https://leetcode.cn/problems/count-the-number-of-good-subarrays/description/)

# 2.3.2 越短越合法

一般要写 ans += right - left + 1。

滑动窗口的内层循环结束时，右端点固定在 right，左端点在 left,left+1,…,right 的所有子数组（子串）都是合法的，这一共有 right−left+1 个。

**题目列表**

- [713. 乘积小于 K 的子数组](https://leetcode.cn/problems/subarray-product-less-than-k/description/)
- [3258. 统计满足 K 约束的子字符串数量 I](https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-i/description/)
- [2302. 统计得分小于 K 的子数组数目](https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/)
- [LCP 68. 美观的花束](https://leetcode.cn/problems/1GxJYY/description/)
