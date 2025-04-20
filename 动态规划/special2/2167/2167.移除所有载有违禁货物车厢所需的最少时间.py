#
# @lc app=leetcode.cn id=2167 lang=python3
#
# [2167] 移除所有载有违禁货物车厢所需的最少时间
#


# @lc code=start
class Solution:
    def minimumTime(self, s: str) -> int:
        n = len(s)
        a = list(s)
        pre, suf = [0] * (n + 1), [0] * (n + 1)
        for i in range(n):
            if a[i] == "1":
                pre[i + 1] = min(i + 1, pre[i] + 2)
            else:
                pre[i + 1] = pre[i]
        for i in range(n - 1, -1, -1):
            if a[i] == "1":
                suf[i] = min(n - i, suf[i + 1] + 2)
            else:
                suf[i] = suf[i + 1]
        ans = 2**31
        for i in range(n + 1):
            ans = min(ans, pre[i] + suf[i])
        return ans


# @lc code=end
