#
# @lc app=leetcode.cn id=2997 lang=python3
#
# [2997] 使数组异或和等于 K 的最少操作次数
#

# @lc code=start
from typing import List


class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        base = 0
        for x in nums:
            base ^= x
        return (base ^ k).bit_count()


# @lc code=end
