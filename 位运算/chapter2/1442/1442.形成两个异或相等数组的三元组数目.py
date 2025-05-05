#
# @lc app=leetcode.cn id=1442 lang=python3
#
# [1442] 形成两个异或相等数组的三元组数目
#

# @lc code=start
from typing import List


class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)
        pre = [0] * (n + 1)
        for i in range(n):
            pre[i + 1] = pre[i] ^ arr[i]

        ans = 0
        for i in range(n):
            for k in range(i + 1, n):
                if pre[i] == pre[k + 1]:
                    ans += k - i
        return ans


# @lc code=end
