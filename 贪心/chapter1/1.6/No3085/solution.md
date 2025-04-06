# LeetCode 3085: K 特殊字符串的最小删除数

## 题目描述

给你一个字符串 word 和一个整数 k。

如果 |freq(word[i]) - freq(word[j])| <= k 对于字符串中所有下标 i 和 j 都成立，则认为 word 是 k 特殊字符串。

此处，freq(x) 表示字符 x 在 word 中的出现频率，而 |y| 表示 y 的绝对值。

返回使 word 成为 k 特殊字符串 需要删除的字符的最小数量。

## 正向思维解法

原代码中采用的是正向思维，通过枚举每个可能的频率作为基准，计算需要删除的字符数：

1. 对于频率低于下限的字符，需要全部删除
2. 对于频率高于上限的字符，需要删除超出部分
3. 取所有可能情况下删除字符数的最小值

## 逆向思维解法

逆向思维的关键是：不直接计算需要删除多少字符，而是计算最多能保留多少字符，然后用字符串总长度减去这个数值。

### 算法思路

1. 统计每个字符的频率
2. 对频率排序
3. 枚举一个频率作为下限值，那么上限值就是下限值+k
4. 对于每个可能的下限值：
   - 频率小于下限的字符全部无法保留
   - 频率大于上限的字符只能部分保留（每个字符最多保留上限个）
   - 频率在区间[下限, 上限]之间的字符可以全部保留
5. 计算在每种下限值下能保留的最大字符数
6. 总字符数减去能保留的最大字符数，即为需要删除的最小字符数

### 代码实现

```cpp
class Solution {
public:
    int minimumDeletions(string word, int k) {
        // 统计每个字符的频率
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }

        // 移除频率为0的字符，并排序
        vector<int> nonZeroFreq;
        for (int f : freq) {
            if (f > 0) {
                nonZeroFreq.push_back(f);
            }
        }
        sort(nonZeroFreq.begin(), nonZeroFreq.end());

        int n = word.length();
        int maxKeep = 0;  // 最多能保留的字符数

        // 枚举每个频率作为下限
        for (int i = 0; i < nonZeroFreq.size(); i++) {
            int lower = nonZeroFreq[i];  // 下限
            int upper = lower + k;       // 上限

            int keep = 0;  // 当前下限下能保留的字符数

            for (int j = 0; j < nonZeroFreq.size(); j++) {
                if (nonZeroFreq[j] < lower) {
                    // 频率小于下限的字符不保留
                    continue;
                } else if (nonZeroFreq[j] > upper) {
                    // 频率大于上限的字符部分保留
                    keep += upper;
                } else {
                    // 频率在区间内的字符全部保留
                    keep += nonZeroFreq[j];
                }
            }

            maxKeep = max(maxKeep, keep);
        }

        // 总长度减去最多能保留的字符数，就是需要删除的最小字符数
        return n - maxKeep;
    }
};
```

### 时间复杂度分析

- 统计频率：O(n)，其中 n 是字符串长度
- 排序频率：O(26 log 26) = O(1)
- 枚举下限并计算保留数：O(26²) = O(1)
- 总时间复杂度：O(n)

### 空间复杂度

- 频率数组：O(26) = O(1)
- 总空间复杂度：O(1)

### 两种思维方式的比较

1. **正向思维**：直接计算需要删除多少字符

   - 优点：直观，易于理解
   - 缺点：可能需要考虑多种情况，代码较复杂

2. **逆向思维**：计算最多能保留多少字符
   - 优点：更清晰，代码更简洁
   - 缺点：可能需要转换思维方式，不那么直观

对于这个问题，逆向思维更为简洁有效，因为我们可以很容易计算在给定条件下最多能保留多少字符，从而得到需要删除的最小字符数。
