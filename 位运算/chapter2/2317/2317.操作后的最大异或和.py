#
# @lc app=leetcode.cn id=2317 lang=python3
#
# [2317] 操作后的最大异或和
#

# @lc code=start
from typing import List


class Solution:
    def maximumXOR(self, nums: List[int]) -> int:
        ans = 0
        for x in nums:
            ans |= x
        return ans


# @lc code=end
