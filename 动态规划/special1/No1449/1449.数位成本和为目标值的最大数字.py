#
# @lc app=leetcode.cn id=1449 lang=python3
#
# [1449] 数位成本和为目标值的最大数字
#
import sys
from typing import List


# @lc code=start
class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        sys.set_int_max_str_digits(5005)
        inf = 2**31
        f = [0] + [-inf] * target
        for i in range(9, 0, -1):
            for j in range(1, target + 1):
                if j >= cost[i - 1]:
                    f[j] = max(f[j], f[j - cost[i - 1]] * 10 + i)
        return str(f[target]) if f[target] > 0 else "0"


# @lc code=end
