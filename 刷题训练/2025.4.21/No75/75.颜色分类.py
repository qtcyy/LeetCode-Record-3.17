#
# @lc app=leetcode.cn id=75 lang=python3
#
# [75] 颜色分类
#

# @lc code=start
from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        for i in range(1, n):
            for j in range(i):
                if nums[i] < nums[j]:
                    nums[i], nums[j] = nums[j], nums[i]


# @lc code=end
