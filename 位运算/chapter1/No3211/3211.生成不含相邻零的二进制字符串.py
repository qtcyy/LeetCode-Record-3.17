#
# @lc app=leetcode.cn id=3211 lang=python3
#
# [3211] 生成不含相邻零的二进制字符串
#

# @lc code=start
from typing import List


class Solution:
    def validStrings(self, n: int) -> List[str]:
        if n == 1:
            return ["0", "1"]
        ans = []
        for s in range(1, (1 << n) + 1):
            t = ""
            k = s
            while k:
                if k & 1:
                    t += "1"
                else:
                    t += "0"
                k >>= 1
            t = t[::-1]
            t = "0" * (n - len(t)) + t
            flag = True
            for i in range(len(t) - 1):
                if int(t[i]) | int(t[i + 1]) == 0:
                    flag = False
                    break

            if not flag:
                continue
            ans.append(t)
        return ans


# @lc code=end
