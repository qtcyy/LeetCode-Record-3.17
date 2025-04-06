# 1.4 阶乘分解

**题目列表**

- [172. 阶乘后的零](https://leetcode.cn/problems/factorial-trailing-zeroes/description/)
- [793. 阶乘函数后 K 个零](https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function/description/)

## 总结

求 n!后有几个 0

```cpp
int sum = 0;
while (x) {
    sum += x / 5;
    x /= 5;
}
return x;
```
