#
# @lc app=leetcode.cn id=1975 lang=python3
#
# [1975] 最大方阵和
#

# @lc code=start
from typing import List


class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        nums = []
        res = 0
        has = False
        for row in matrix:
            for x in row:
                if x == 0:
                    has = True
                if x < 0:
                    nums.append(-x)
                else:
                    res += x
        if len(nums) % 2 and not has:
            res += sum(nums) - 2 * min(nums)
        else:
            res += sum(nums)
        return res


# @lc code=end
