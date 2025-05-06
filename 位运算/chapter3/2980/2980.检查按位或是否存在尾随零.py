#
# @lc app=leetcode.cn id=2980 lang=python3
#
# [2980] 检查按位或是否存在尾随零
#

# @lc code=start
from typing import List


class Solution:
    def hasTrailingZeros(self, nums: List[int]) -> bool:
        cnt = 0
        for x in nums:
            if x & 1 == 0:
                cnt += 1
        return cnt >= 2


# @lc code=end
