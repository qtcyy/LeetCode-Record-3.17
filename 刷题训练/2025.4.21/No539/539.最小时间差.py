#
# @lc app=leetcode.cn id=539 lang=python3
#
# [539] 最小时间差
#

# @lc code=start
from typing import List


class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        n = len(timePoints)
        times = []
        for s in timePoints:
            time = int(s[:2]) * 60 + int(s[3:])
            times.append(time)
        times.sort()
        ans = 24 * 60
        for i in range(n - 1):
            ans = min(ans, times[i + 1] - times[i], 1440 - (times[i + 1] - times[i]))
        ans = min(ans, times[-1] - times[0], 1440 - (times[-1] - times[0]))
        return ans


# @lc code=end
