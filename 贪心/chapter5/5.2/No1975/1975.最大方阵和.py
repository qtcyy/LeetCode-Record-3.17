#
# @lc app=leetcode.cn id=1975 lang=python3
#
# [1975] 最大方阵和
#

# @lc code=start
from typing import List


class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        res = 0
        mn = 2**30
        cnt = 0
        for row in matrix:
            for x in row:
                res += abs(x)
                mn = min(mn, abs(x))
                if x < 0:
                    cnt += 1
        if cnt % 2 != 0:
            res -= 2 * mn

        return res


# @lc code=end
