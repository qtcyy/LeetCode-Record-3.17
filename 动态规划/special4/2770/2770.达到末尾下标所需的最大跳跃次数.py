#
# @lc app=leetcode.cn id=2770 lang=python3
#
# [2770] 达到末尾下标所需的最大跳跃次数
#

# @lc code=start
from typing import List


class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        n = len(nums)
        f = [-1] * n
        f[0] = 0
        for i in range(1, n):
            for j in range(i):
                if f[j] != -1 and -target <= nums[i] - nums[j] <= target:
                    f[i] = max(f[i], f[j] + 1)
        return f[-1]


# @lc code=end
