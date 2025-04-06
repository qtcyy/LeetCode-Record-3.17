# 3.1 字典序最小/最大

字典序的定义如下：

- 对于两个字符串 $a$ 和 $b$，从左到右依次比较 $a[i]$ 和 $b[i]$ 的字符 ASCII 值的大小。
- $a[i] \neq b[i]$ 时，如果 $a[i] < b[i]$，那么 $a$ 的字典序更小，否则 $b$ 的字典序更小。
- 如果没有出现 $a[i] \neq b[i]$，则短的字符串字典序更小。
- 如果两个字符串的长度和内容均相同，那么两个字符串的字典序一样。

字典序的定义也可以推广到数组上，按照上述方法比较两个数组的字典序。

**题目列表**

- [1323. 6 和 9 组成的最大数字](https://leetcode.cn/problems/maximum-69-number/description/)
- [3216. 交换后字典序最小的字符串](https://leetcode.cn/problems/lexicographically-smallest-string-after-a-swap/description/)
- [2697. 字典序最小回文串](https://leetcode.cn/problems/lexicographically-smallest-palindrome/description/)
- [1881. 插入后的最大值](https://leetcode.cn/problems/maximum-value-after-insertion/description/)
