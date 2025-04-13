# 9.2 排列型 ② 相邻相关

一般定义 $f[S][i]$ 表示未选（或者已选）的集合为 $S$，且上一个填的元素（下标）为 $i$ 时，和题目有关的最优值。通过枚举当前位置要填的元素（下标）来转移。

时间复杂度（通常来说）是 $O(n^2\cdot 2^n)$

**题目列表**

- [996. 平方数组的数目](https://leetcode.cn/problems/number-of-squareful-arrays/description/)
- [2741. 特别的排列](https://leetcode.cn/problems/special-permutations/description/)
