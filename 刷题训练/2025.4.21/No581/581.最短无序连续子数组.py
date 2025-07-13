#
# @lc app=leetcode.cn id=581 lang=python3
#
# [581] 最短无序连续子数组
#

# @lc code=start
from typing import List


class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)

        def is_sorted() -> bool:
            for i in range(n - 1):
                if nums[i + 1] < nums[i]:
                    return False
            return True

        if is_sorted():
            return 0

        sorted_nums = sorted(nums)
        left = 0
        while left < n and nums[left] == sorted_nums[left]:
            left += 1
        right = n - 1
        while right >= 0 and nums[right] == sorted_nums[right]:
            right -= 1

        return right - left + 1


# @lc code=end
