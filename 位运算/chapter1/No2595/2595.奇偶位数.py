#
# @lc app=leetcode.cn id=2595 lang=python3
#
# [2595] 奇偶位数
#

# @lc code=start
from typing import List


class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        MASK = 0x55555555
        return [(n & MASK).bit_count(), (n & (~MASK)).bit_count()]


# @lc code=end
