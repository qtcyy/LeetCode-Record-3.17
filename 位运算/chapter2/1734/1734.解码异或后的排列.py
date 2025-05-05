#
# @lc app=leetcode.cn id=1734 lang=python3
#
# [1734] 解码异或后的排列
#

# @lc code=start
from typing import List


class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        tot = 0
        n = len(encoded) + 1
        for i in range(1, n + 1):
            tot ^= i
        odd_tot = 0
        for i in range(1, n - 1, 2):
            odd_tot ^= encoded[i]
        ans = [tot ^ odd_tot]
        for x in encoded:
            ans.append(ans[-1] ^ x)
        return ans


# @lc code=end
