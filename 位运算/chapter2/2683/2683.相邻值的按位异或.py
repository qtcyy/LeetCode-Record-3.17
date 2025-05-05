#
# @lc app=leetcode.cn id=2683 lang=python3
#
# [2683] 相邻值的按位异或
#

# @lc code=start
from typing import List


class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        num = 0
        for x in derived:
            num ^= x
        return num == 0


# @lc code=end
