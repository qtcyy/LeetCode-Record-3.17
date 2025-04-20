#
# @lc app=leetcode.cn id=2100 lang=python3
#
# [2100] 适合野炊的日子
#
from typing import List


# @lc code=start
class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)
        if time == 0:
            return list(range(n))
        pre, suf = [1] * n, [1] * n
        for i in range(1, n):
            if security[i - 1] >= security[i]:
                pre[i] = pre[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if security[i] <= security[i + 1]:
                suf[i] = suf[i + 1] + 1
        ans = []
        for i in range(time, n - time):
            if pre[i] >= time + 1 and suf[i] >= time + 1:
                ans.append(i)
        return ans


# @lc code=end
