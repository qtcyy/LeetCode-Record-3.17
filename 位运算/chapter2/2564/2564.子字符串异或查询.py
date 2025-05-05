#
# @lc app=leetcode.cn id=2564 lang=python3
#
# [2564] 子字符串异或查询
#

# @lc code=start
from typing import List


class Solution:
    def substringXorQueries(self, s: str, queries: List[List[int]]) -> List[List[int]]:
        n = len(s)
        d = {}

        for i in range(n):
            if s[i] == "0":
                if 0 not in d:
                    d[0] = [i, i]
                continue
            val = 0
            for j in range(i, min(i + 32, n)):
                val = (val << 1) | int(s[j])
                if val not in d:
                    d[val] = [i, j]
                elif j - i < d[val][1] - d[val][0]:
                    d[val] = [i, j]

        return [d.get(x ^ y, [-1, -1]) for x, y in queries]


# @lc code=end
