# 2.3 求子数组个数

## 2.3.1 越长越合法

一般要写 ans += left。

滑动窗口的内层循环结束时，右端点固定在 right，左端点在 0,1,2,…,left−1 的所有子数组（子串）都是合法的，这一共有 left 个。

**题目列表**

- [1358. 包含所有三种字符的子字符串数目](https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/description/)
- [2962. 统计最大元素出现至少 K 次的子数组](https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/)
- [3325. 字符至少出现 K 次的子字符串 I](https://leetcode.cn/problems/count-substrings-with-k-frequency-characters-i/description/)
- [2799. 统计完全子数组的数目](https://leetcode.cn/problems/count-complete-subarrays-in-an-array/description/)
