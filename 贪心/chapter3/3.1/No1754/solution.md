# 1754. 构造字典序最大的合并字符串（Largest Merge Of Two Strings）

## 问题描述

给你两个字符串 word1 和 word2 。你需要按下述方式构造一个新字符串 merge：如果 word1 或 word2 非空，选择下面选项之一继续操作：

1. 如果 word1 非空，将 word1 中的第一个字符附加到 merge 的末尾，并将其从 word1 中移除。
   例如，word1 = "abc" 且 merge = "dv" ，在执行此选项操作之后，word1 = "bc" ，同时 merge = "dva" 。

2. 如果 word2 非空，将 word2 中的第一个字符附加到 merge 的末尾，并将其从 word2 中移除。
   例如，word2 = "abc" 且 merge = "" ，在执行此选项操作之后，word2 = "bc" ，同时 merge = "a" 。

返回你可以构造的字典序最大的合并字符串 merge。

长度相同的两个字符串 a 和 b 比较字典序大小，如果在 a 和 b 出现不同的第一个位置，a 中字符在字母表中的出现顺序位于 b 中相应字符之后，就认为字符串 a 按字典序比字符串 b 更大。例如，"abcd" 按字典序比 "abcc" 更大，因为两个字符串出现不同的第一个位置是第四个字符，而 d 在字母表中的出现顺序位于 c 之后。

## 解题思路

### 贪心策略

这道题的关键是每一步都要做出能使最终合并字符串字典序最大的选择。由于我们每次只能从两个字符串的首字符中选择一个添加到结果中，直观的想法是选择字典序较大的那个字符。但这种策略在某些情况下并不总是最优的。

例如，考虑 word1 = "ab", word2 = "aa"：

- 如果仅仅比较首字符，两者都是 'a'，随便选一个
- 如果选择 word1，结果是 "aab"
- 如果选择 word2，结果是 "aab" (结果相同)

但考虑 word1 = "abc", word2 = "abd"：

- 首字符都是 'a'，然后都是 'b'
- 但第三个字符，word1 是 'c'，word2 是 'd'
- 应该选择 word2，因为 'd' > 'c'，这样可以得到更大的字典序

因此，正确的贪心策略是：当首字符相同时，需要比较从当前位置开始的剩余子串的字典序，选择字典序更大的那个字符串的首字符。

### 算法步骤

1. 初始化一个空字符串 `res` 用于存储结果
2. 使用两个指针 `i` 和 `j` 分别遍历 word1 和 word2
3. 当两个指针都未到达字符串末尾时：
   - 比较 word1[i:] 和 word2[j:] 的字典序
   - 如果 word1[i:] > word2[j:]，取 word1 的当前字符，`i++`
   - 否则，取 word2 的当前字符，`j++`
4. 将剩余的字符（如果有）追加到结果中
5. 返回最终的 `res` 字符串

### 时间复杂度和空间复杂度

- 时间复杂度：O((n+m)²)，其中 n 和 m 分别是 word1 和 word2 的长度。在最坏的情况下，每次比较两个子串需要 O(n+m) 的时间，总共需要进行 O(n+m) 次比较。
- 空间复杂度：O(n+m)，用于存储最终的合并字符串。

### 代码实现

```python
class Solution:
    def largestMerge(self, word1: str, word2: str) -> str:
        res = ""
        i, j = 0, 0
        n, m = len(word1), len(word2)
        while i < n and j < m:
            if word1[i:] > word2[j:]:
                res += word1[i]
                i += 1
            else:
                res += word2[j]
                j += 1
        return res + word1[i:] + word2[j:]
```

## 示例分析

以题目中的示例 word1 = "cabaa"，word2 = "bcaaa" 为例：

1. 初始状态：i=0, j=0, res=""
2. 比较 "cabaa" 和 "bcaaa"，"cabaa" > "bcaaa"（因为 'c' > 'b'），所以选择 word1[0]，res="c", i=1
3. 比较 "abaa" 和 "bcaaa"，"bcaaa" > "abaa"（因为 'b' > 'a'），所以选择 word2[0]，res="cb", j=1
4. 比较 "abaa" 和 "caaa"，"caaa" > "abaa"（因为 'c' > 'a'），所以选择 word2[1]，res="cbc", j=2
5. 比较 "abaa" 和 "aaa"，"abaa" > "aaa"（因为第二个字符 'b' > 'a'），所以选择 word1[1]，res="cbca", i=2
6. 比较 "baa" 和 "aaa"，"baa" > "aaa"（因为 'b' > 'a'），所以选择 word1[2]，res="cbcab", i=3
7. 比较 "aa" 和 "aaa"，"aaa" > "aa"（因为长度更长），所以选择 word2[2]，res="cbcaba", j=3
8. 继续比较，最终将所有剩余字符追加到结果中，得到最终结果 "cbcabaaaa"

## 总结

这道题的核心是理解什么时候应该选择哪个字符串的首字符。关键点在于不仅要比较当前字符，还要考虑后续字符的影响。通过比较两个子串的字典序，可以确保每一步的选择都是最优的，从而构造出字典序最大的合并字符串。
