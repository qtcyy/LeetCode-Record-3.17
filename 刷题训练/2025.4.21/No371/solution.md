# LeetCode 371: 两整数之和

## 题目描述

给你两个整数 `a` 和 `b`，不使用运算符 `+` 和 `-`，计算并返回两整数之和。

## 解题思路

这道题是经典的位运算问题，核心思想是用位运算来模拟加法的过程。

### 加法的本质分析

在二进制加法中，我们需要考虑两个部分：

1. **不考虑进位的和**：相当于按位异或（XOR）
2. **进位**：相当于按位与（AND）后左移一位

### 位运算原理

```
例如：3 + 2 = 5
3: 011
2: 010

步骤1：不考虑进位的和
3 ^ 2 = 011 ^ 010 = 001

步骤2：计算进位
(3 & 2) << 1 = (011 & 010) << 1 = 010 << 1 = 100

步骤3：将结果相加
001 + 100 = 101 = 5
```

### 算法流程

1. 计算不考虑进位的和：`sum = a ^ b`
2. 计算进位：`carry = (a & b) << 1`
3. 如果进位不为 0，则继续：`a = sum, b = carry`，重复步骤 1-2
4. 如果进位为 0，则返回 sum

## 算法实现

### 方法一：迭代实现

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int sum = a ^ b;        // 不考虑进位的和
            int carry = (unsigned int)(a & b) << 1;  // 进位
            a = sum;
            b = carry;
        }
        return a;
    }
};
```

### 方法二：递归实现

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;       // 递归终止条件

        int sum = a ^ b;            // 不考虑进位的和
        int carry = (unsigned int)(a & b) << 1;  // 进位

        return getSum(sum, carry);  // 递归调用
    }
};
```

### 方法三：处理负数的通用版本

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
```

## 详细执行过程

### 示例 1：getSum(1, 2)

```
a = 1 (001), b = 2 (010)

第1次循环：
sum = 1 ^ 2 = 001 ^ 010 = 011 = 3
carry = (1 & 2) << 1 = (001 & 010) << 1 = 000 << 1 = 000 = 0
a = 3, b = 0

b == 0，退出循环，返回 a = 3
```

### 示例 2：getSum(2, 3)

```
a = 2 (010), b = 3 (011)

第1次循环：
sum = 2 ^ 3 = 010 ^ 011 = 001 = 1
carry = (2 & 3) << 1 = (010 & 011) << 1 = 010 << 1 = 100 = 4
a = 1, b = 4

第2次循环：
sum = 1 ^ 4 = 001 ^ 100 = 101 = 5
carry = (1 & 4) << 1 = (001 & 100) << 1 = 000 << 1 = 000 = 0
a = 5, b = 0

b == 0，退出循环，返回 a = 5
```

## 负数处理

对于负数，需要特别注意符号扩展的问题：

```cpp
// 处理负数的安全版本
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // 使用unsigned避免符号扩展问题
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = (int)carry;
        }
        return a;
    }
};
```

## 位运算基础知识

### 异或运算 (XOR)

- `0 ^ 0 = 0`
- `0 ^ 1 = 1`
- `1 ^ 0 = 1`
- `1 ^ 1 = 0`

### 与运算 (AND)

- `0 & 0 = 0`
- `0 & 1 = 0`
- `1 & 0 = 0`
- `1 & 1 = 1`

### 左移运算

- `x << 1` 相当于 `x * 2`
- 用于将进位向左移动一位

## 复杂度分析

- **时间复杂度**：O(log(max(a,b)))，最多需要 32 次循环（32 位整数）
- **空间复杂度**：O(1)，只使用常数额外空间

## 扩展应用

### 1. 实现减法

```cpp
int subtract(int a, int b) {
    return getSum(a, getSum(~b, 1));  // a - b = a + (-b) = a + (~b + 1)
}
```

### 2. 实现乘法

```cpp
int multiply(int a, int b) {
    int result = 0;
    while (b != 0) {
        if (b & 1) {
            result = getSum(result, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}
```

## 关键要点

1. **位运算模拟**：用 XOR 计算不进位和，用 AND+左移计算进位
2. **循环终止**：当进位为 0 时停止
3. **负数处理**：使用 unsigned 避免符号扩展问题
4. **溢出考虑**：在实际应用中需要考虑整数溢出

## 相关题目

- LeetCode 2: 两数相加
- LeetCode 67: 二进制求和
- LeetCode 415: 字符串相加
- LeetCode 989: 数组形式的整数加法
- LeetCode 190: 颠倒二进制位
- LeetCode 191: 位 1 的个数

## 总结

这道题巧妙地运用了位运算的特性来模拟加法运算，是理解位运算应用的经典例题。掌握了这个方法后，可以进一步实现减法、乘法等运算，对于理解计算机底层运算原理很有帮助。
