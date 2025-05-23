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
- [2734. 执行子串操作后的字典序最小字符串](https://leetcode.cn/problems/lexicographically-smallest-string-after-substring-operation/description/)
- [1946. 子字符串突变后可能得到的最大整数](https://leetcode.cn/problems/largest-number-after-mutating-substring/description/)
- [1663. 具有给定数值的最小字符串](https://leetcode.cn/problems/smallest-string-with-a-given-numeric-value/description/)
- [1328. 破坏回文串](https://leetcode.cn/problems/break-a-palindrome/description/)
- [2259. 移除指定数字得到的最大结果](https://leetcode.cn/problems/remove-digit-from-number-to-maximize-result/description/)
- [2566. 替换一个数字后的最大差值](https://leetcode.cn/problems/maximum-difference-by-remapping-a-digit/description/)
- [670. 最大交换](https://leetcode.cn/problems/maximum-swap/description/)
- [3106. 满足距离约束且字典序最小的字符串](https://leetcode.cn/problems/lexicographically-smallest-string-after-operations-with-constraint/description/)
- [1053. 交换一次的先前排列](https://leetcode.cn/problems/previous-permutation-with-one-swap/description/)
- [2375. 根据模式串构造最小数字](https://leetcode.cn/problems/construct-smallest-number-from-di-string/description/)
- [2182. 构造限制重复的字符串](https://leetcode.cn/problems/construct-string-with-repeat-limit/description/)
- [738. 单调递增的数字](https://leetcode.cn/problems/monotone-increasing-digits/description/)
- [3403. 从盒子中找出字典序最大的字符串 I](https://leetcode.cn/problems/find-the-lexicographically-largest-string-from-the-box-i/solutions/3033286/mei-ju-zuo-duan-dian-tan-xin-pythonjavac-y2em/)
- [1363. 形成三的最大倍数](https://leetcode.cn/problems/largest-multiple-of-three/description/)
- [1754. 构造字典序最大的合并字符串](https://leetcode.cn/problems/largest-merge-of-two-strings/description/)
- [1202. 交换字符串中的元素](https://leetcode.cn/problems/smallest-string-with-swaps/description/)
- [2434. 使用机器人打印字典序最小的字符串](https://leetcode.cn/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/)
- [2948. 交换得到字典序最小的数组](https://leetcode.cn/problems/make-lexicographically-smallest-array-by-swapping-elements/description/)
