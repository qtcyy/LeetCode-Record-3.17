#
# @lc app=leetcode.cn id=2917 lang=python3
#
# [2917] 找出数组中的 K-or 值
#

# @lc code=start
from typing import List


class Solution:
    def findKOr(self, nums: List[int], k: int) -> int:
        mx = max(nums)
        n = 0
        while mx:
            n += 1
            mx >>= 1
        ans = 0
        for i in range(0, n):
            cnt = 0
            for j in range(len(nums)):
                if nums[j] & 1:
                    cnt += 1
                nums[j] >>= 1
            if cnt >= k:
                ans |= 1 << i
        return ans


# @lc code=end
