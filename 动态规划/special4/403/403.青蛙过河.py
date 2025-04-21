#
# @lc app=leetcode.cn id=403 lang=python3
#
# [403] 青蛙过河
#

# @lc code=start
from collections import defaultdict
from functools import cache
from typing import List


class Solution2:
    def canCross(self, stones: List[int]) -> bool:
        st = set(stones)

        @cache
        def dfs(pos: int, step: int) -> bool:
            if pos == stones[-1]:
                return True
            for d in [-1, 0, 1]:
                if step + d > 0 and pos + step + d in st:
                    if dfs(pos + step + d, step + d):
                        return True
            return False

        return dfs(0, 0)


class Solution:
    def canCross(self, stones: List[int]) -> bool:
        """
        DP递推
        """
        n = len(stones)
        st = set(stones)
        f = defaultdict(set)
        f[0] = {0}
        for s in stones:
            for step in f[s]:
                for d in [-1, 0, 1]:
                    if step + d > 0 and step + d + s in st:
                        f[s + step + d].add(step + d)
        return len(f[stones[-1]]) > 0


# @lc code=end
