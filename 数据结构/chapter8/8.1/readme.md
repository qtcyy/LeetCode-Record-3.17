# 8.1 树状数组

**题目列表**

- [307. 区域和检索 - 数组可修改](https://leetcode.cn/problems/range-sum-query-mutable/description/)
- [3187. 数组中的峰值](https://leetcode.cn/problems/peaks-in-array/description/)

**做题总结**

    如No3187中出现的这种区间操作，可以封装更新函数，在新的操作到来前去除之前的影响后再更新现在的影响。

```cpp
auto update = [&](const int &i, const int &val) {
    if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
        f.update(i, val);
    }
};
for (int i = 1; i < n - 1; i++) {
    update(i, 1);
}
vector<int> ans;
    for (auto &q : queries) {
        if (q[0] == 1) {
            if (q[2] - 1 < q[1]) {
                ans.push_back(0);
            } else {
            ans.push_back(f.query(q[2] - 1) - f.query(q[1]));
        }
        } else {
            int i = q[1];
            for (int j = max(1, i - 1); j <= min(n - 2, i + 1); j++) {
                update(i, -1);
            }
            nums[i] = q[2];
            for (int j = max(1, i - 1); j <= min(n - 2, i + 1); j++) {
                update(i, 1);
            }
      }
    }
```
