#
# @lc app=leetcode.cn id=3375 lang=python3
#
# [3375] 使数组的值全部为 K 的最少操作次数
#

# @lc code=start
from typing import List


class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        mn = min(nums)
        if k > mn:
            return -1
        if k == mn:
            return len(set(nums)) - 1
        return len(set(nums))


# @lc code=end
