#
# @lc app=leetcode.cn id=2657 lang=python3
#
# [2657] 找到两个数组的前缀公共数组
#

# @lc code=start
from typing import List


class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        ans = []
        p = q = 0
        for i in range(n):
            p |= 1 << A[i]
            q |= 1 << B[i]
            ans.append((p & q).bit_count())
        return ans


# @lc code=end
