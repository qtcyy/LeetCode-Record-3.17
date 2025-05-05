#
# @lc app=leetcode.cn id=2857 lang=python3
#
# [2857] 统计距离为 k 的点对
#

# @lc code=start
from collections import defaultdict
from typing import List


class Solution:
    def countPairs(self, coordinates: List[List[int]], k: int) -> int:
        n = len(coordinates)
        s = defaultdict(int)
        s[coordinates[0][0] << 32 | coordinates[0][1]] = 1
        ans = 0
        for i in range(1, n):
            for a in range(0, k + 1):
                b = k - a
                pre = (a ^ coordinates[i][0]) << 32 | (b ^ coordinates[i][1])
                if pre in s:
                    ans += s[pre]
            s[coordinates[i][0] << 32 | coordinates[i][1]] += 1
        return ans


# @lc code=end
