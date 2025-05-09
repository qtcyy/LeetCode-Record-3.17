# 1969. 数组元素的最小非零乘积

## 题目

给你一个正整数 p 。你有一个下标从 1 开始的数组 nums ，这个数组包含范围 $[1, 2^p - 1]$ 内所有整数的二进制形式（两端都包含）。你可以进行以下操作任意次：

- 从 nums 中选择两个元素 x 和 y
- 选择 x 中的一位与 y 对应位置的位交换。对应位置指的是两个整数相同位置的二进制位。
- 比方说，如果 x = 1101 且 y = 0011 ，交换右边数起第 2 位后，我们得到 x = 1111 和 y = 0001 。

请你算出进行以上操作任意次以后，nums 能得到的最小非零乘积。将乘积对 $10^9 + 7$ 取余后返回。

## 思路

首先分析一下这个问题:

1. 我们有一个数组包含从 1 到 $2^p-1$ 的所有整数
2. 我们可以交换任意两个数之间的对应位
3. 我们的目标是最小化这些数的乘积

关键洞察:

- 当我们交换两个数的对应位时，如果这两位不同(一个是 0，一个是 1)，交换会使一个数变大，另一个数变小
- 对于乘积 $a \times b$，如果 $a$ 减少 $x$，$b$ 增加 $x$，那么新的乘积为 $(a-x) \times (b+x) = (a \times b) - (a-b) \times x - x^2$
- 当 $a > b$ 时，$(a-x) \times (b+x) < a \times b$，即交换使乘积变小

为了使乘积最小，我们应该尽可能将数组中的数调整为:

- 尽量多的数变为 1(最小正整数)
- 其余数尽可能大

考虑数字的配对。对于每对数 $(i, 2^p-1-i)$，它们的二进制表示刚好互补(异或值为 $2^p-1$)。通过位交换，我们可以将每对中的一个数变为 1，另一个变为 $2^p-2$。

例如，$p=3$ 时，可以配对:

- $(1, 6) \rightarrow (1, 6)$
- $(2, 5) \rightarrow (1, 6)$
- $(3, 4) \rightarrow (1, 6)$

例外情况是 $2^p-1$ 本身无法被配对，它将保持不变。

因此，最小乘积为:

- $1^{(2^p-2)/2} \times (2^p-2)^{(2^p-2)/2} \times (2^p-1)$
- 简化为: $(2^p-2)^{(2^p-2)/2} \times (2^p-1)$

## 代码实现

```cpp
class Solution {
public:
    int minNonZeroProduct(int p) {
        if (p == 1) return 1;

        const int MOD = 1e9 + 7;

        // 计算 2^p - 1
        long long maxVal = (1LL << p) - 1;

        // 计算 2^p - 2
        long long val = maxVal - 1;

        // 计算幂次: (2^p - 2) / 2
        long long power = (maxVal - 1) / 2;

        // 计算 (2^p - 2)^((2^p - 2)/2) % MOD
        long long res = fastPow(val, power, MOD);

        // 计算 (2^p - 2)^((2^p - 2)/2) * (2^p - 1) % MOD
        res = (res * (maxVal % MOD)) % MOD;

        return (int)res;
    }

private:
    // 快速幂算法计算 (base^power) % mod
    long long fastPow(long long base, long long power, int mod) {
        long long result = 1;
        base %= mod;

        while (power > 0) {
            if (power & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            power >>= 1;
        }

        return result;
    }
};
```

## 复杂度分析

- 时间复杂度: $O(p)$，主要是快速幂计算的复杂度
- 空间复杂度: $O(1)$，只使用了常数额外空间

## 总结

这道题的关键在于理解二进制位交换的本质和如何使乘积最小化。通过将数组分成配对，并将每对数中的一个变为 1，另一个变为 $2^p-2$，我们可以得到最小乘积。使用快速幂算法处理大数取模是解决此类问题的常用技巧。
