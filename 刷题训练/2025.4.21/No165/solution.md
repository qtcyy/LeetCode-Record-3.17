# LeetCode 165: 比较版本号

## 题目描述

给你两个 版本号字符串 `version1` 和 `version2`，请你比较它们。版本号由被点 '.' 分开的修订号组成。修订号的值是它转换为整数并忽略前导零。

比较版本号时，请按从左到右的顺序依次比较它们的修订号。如果其中一个版本字符串的修订号较少，则将缺失的修订号视为 0。

返回规则如下：

- 如果 `version1 < version2` 返回 -1
- 如果 `version1 > version2` 返回 1
- 除此之外返回 0

## 解题思路

这道题的核心是要正确处理版本号的比较逻辑：

1. **分割字符串**：将两个版本号按 '.' 分割成修订号数组
2. **逐个比较**：从左到右依次比较对应位置的修订号
3. **类型转换**：将修订号字符串转换为整数（自动忽略前导零）
4. **长度处理**：当某个版本号的修订号较少时，缺失部分视为 0
5. **返回结果**：根据比较结果返回 -1、0 或 1

## 算法实现

### 方法一：双指针 + 分割字符串

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = split(version1, '.');
        vector<string> v2 = split(version2, '.');

        int n1 = v1.size(), n2 = v2.size();
        int maxLen = max(n1, n2);

        for (int i = 0; i < maxLen; i++) {
            int num1 = (i < n1) ? stoi(v1[i]) : 0;
            int num2 = (i < n2) ? stoi(v2[i]) : 0;

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }

        return 0;
    }

private:
    vector<string> split(string str, char delimiter) {
        vector<string> result;
        stringstream ss(str);
        string item;

        while (getline(ss, item, delimiter)) {
            result.push_back(item);
        }

        return result;
    }
};
```

### 方法二：直接遍历（优化空间）

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.length(), n2 = version2.length();

        while (i < n1 || j < n2) {
            int num1 = 0, num2 = 0;

            // 提取version1的下一个修订号
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            i++; // 跳过 '.'

            // 提取version2的下一个修订号
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            j++; // 跳过 '.'

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }

        return 0;
    }
};
```

## 示例分析

### 示例 1

```
输入：version1 = "1.2", version2 = "1.10"
输出：-1
解释：
- 第1个修订号：1 == 1
- 第2个修订号：2 < 10
- 因此 version1 < version2，返回 -1
```

### 示例 2

```
输入：version1 = "1.01", version2 = "1.001"
输出：0
解释：
- 第1个修订号：1 == 1
- 第2个修订号：01 -> 1, 001 -> 1, 所以 1 == 1
- 因此 version1 == version2，返回 0
```

### 示例 3

```
输入：version1 = "1.0", version2 = "1.0.0.0"
输出：0
解释：
- 第1个修订号：1 == 1
- 第2个修订号：0 == 0
- version1缺失的修订号视为0，与version2的0相等
- 因此 version1 == version2，返回 0
```

## 复杂度分析

### 方法一（分割字符串）

- **时间复杂度**：O(n + m)，其中 n 和 m 分别是两个版本号的长度
- **空间复杂度**：O(n + m)，用于存储分割后的字符串数组

### 方法二（直接遍历）

- **时间复杂度**：O(n + m)，其中 n 和 m 分别是两个版本号的长度
- **空间复杂度**：O(1)，只使用常数额外空间

## 关键要点

1. **前导零处理**：通过将字符串转换为整数自动忽略前导零
2. **长度不等处理**：较短版本号的缺失部分视为 0
3. **逐段比较**：不能直接进行字符串比较，必须按修订号逐个比较
4. **边界情况**：处理空字符串、单个数字等特殊情况

## 相关题目

- LeetCode 14: 最长公共前缀
- LeetCode 415: 字符串相加
- LeetCode 43: 字符串相乘
