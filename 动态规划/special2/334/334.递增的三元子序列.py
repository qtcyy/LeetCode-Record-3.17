#
# @lc app=leetcode.cn id=334 lang=python3
#
# [334] 递增的三元子序列
#
from typing import List


# @lc code=start
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        n = len(nums)
        inf = 2**31
        pre_min, suf_max = [inf] * (n + 1), [0] * (n + 1)
        for i in range(n):
            pre_min[i + 1] = min(pre_min[i], nums[i])
        for i in range(n - 1, -1, -1):
            suf_max[i] = max(suf_max[i + 1], nums[i])
        for i in range(1, n - 1):
            if pre_min[i] < nums[i] and nums[i] < suf_max[i + 1]:
                return True

        return False


# @lc code=end
