#
# @lc app=leetcode.cn id=926 lang=python3
#
# [926] 将字符串翻转到单调递增
#
from typing import List


# @lc code=start
class Solution2:
    def minFlipsMonoIncr(self, s: str) -> int:
        """
        DP方法
        """
        n = len(s)
        a = list(s)
        f = [[0, 1] for _ in range(n + 1)]
        for i in range(n):
            if i == 0:
                continue
            if a[i] == "0" and a[i - 1] == "0":
                f[i + 1][0] = f[i][0]
                f[i + 1][1] = min(f[i][0], f[i][1]) + 1
            elif a[i] == "0" and a[i - 1] == "1":
                f[i + 1][0] = f[i][1]
                f[i + 1][1] = min(f[i][0], f[i][1]) + 1
            elif a[i] == "1" and a[i - 1] == "0":
                f[i + 1][0] = min(f[i][0], f[i][1])
                f[i + 1][1] = f[i][0] + 1
            elif a[i] == "1" and a[i - 1] == "1":
                f[i + 1][0] = min(f[i][0], f[i][1])
                f[i + 1][1] = f[i][1] + 1
        return min(f[n])


class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        """
        前后缀分解方法
        """
        a: List[str] = list(s)
        n = len(a)
        pre, suf = [0] * (n + 1), [0] * (n + 1)
        for i in range(n):
            if a[i] == "1":
                pre[i + 1] = pre[i] + 1
            else:
                pre[i + 1] = pre[i]
        for i in range(n - 1, -1, -1):
            if a[i] == "0":
                suf[i] = suf[i + 1] + 1
            else:
                suf[i] = suf[i + 1]
        ans = n + 1
        for i in range(n + 1):
            ans = min(ans, pre[i] + suf[i])
        return ans


# @lc code=end
