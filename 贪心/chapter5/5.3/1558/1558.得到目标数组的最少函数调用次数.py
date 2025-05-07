#
# @lc app=leetcode.cn id=1558 lang=python3
#
# [1558] 得到目标数组的最少函数调用次数
#

# @lc code=start
from typing import List


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        mx = max(nums)
        ans = 0
        for x in nums:
            ans += x.bit_count()
        if mx:
            ans += mx.bit_length()
            ans -= 1
        return ans


# @lc code=end
