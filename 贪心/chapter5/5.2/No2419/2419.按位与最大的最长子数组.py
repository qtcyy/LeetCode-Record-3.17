#
# @lc app=leetcode.cn id=2419 lang=python3
#
# [2419] 按位与最大的最长子数组
#
from typing import List


# @lc code=start
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        mx = max(nums)
        ans, sum = 1, 1
        for i in range(1, n):
            if nums[i] == mx and nums[i] == nums[i - 1]:
                sum += 1
                ans = max(ans, sum)
            else:
                sum = 1
        return ans


# @lc code=end
