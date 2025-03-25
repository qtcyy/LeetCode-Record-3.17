# 4.4 单调队列

**题目列表**

- [239](https://leetcode.cn/problems/sliding-window-maximum/description/). 滑动窗口最大值
- [1438](https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/). 绝对差不超过限制的最长连续子数组
- [2762](https://leetcode.cn/problems/continuous-subarrays/description/). 不间断子数组
- [2398](https://leetcode.cn/problems/maximum-number-of-robots-within-budget/description/). 预算内的最多机器人数目

## 做题总结

No2398 和 No2762 中出现的双指针单调队列，其出队条件有独特的写法

```cpp
while (!deq.empty() && [conditions]){
    // 如果单调队列中存在需要去掉的arr[left]就将其出队
    if (arr[left]==arr[deq.front()]){
        deq.pop_front();
    }
    left++;
}
```
