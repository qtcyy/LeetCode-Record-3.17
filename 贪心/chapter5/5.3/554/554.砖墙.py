#
# @lc app=leetcode.cn id=554 lang=python3
#
# [554] 砖墙
#

# @lc code=start
from collections import defaultdict
from typing import List


class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        cnt = defaultdict(int)
        for row in wall:
            pre = 0
            for i, x in enumerate(row):
                if i == len(row) - 1:
                    break
                pre += x
                cnt[pre] += 1
        n = len(wall)
        if len(cnt):
            return n - max(cnt.values())
        else:
            return n


# @lc code=end
