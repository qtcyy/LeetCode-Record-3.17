#
# @lc app=leetcode.cn id=1653 lang=python3
#
# [1653] 使字符串平衡的最少删除次数
#


# @lc code=start
class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        a = list(s)
        pre, suf = [0] * (n + 1), [0] * (n + 1)
        for i in range(n):
            if a[i] == "b":
                pre[i + 1] = pre[i] + 1
            else:
                pre[i + 1] = pre[i]
        for i in range(n - 1, -1, -1):
            if a[i] == "a":
                suf[i] = suf[i + 1] + 1
            else:
                suf[i] = suf[i + 1]
        ans = n + 1
        for i in range(n + 1):
            ans = min(ans, pre[i] + suf[i])
        return ans


# @lc code=end
