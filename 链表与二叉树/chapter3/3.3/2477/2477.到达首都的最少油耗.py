#
# @lc app=leetcode.cn id=2477 lang=python3
#
# [2477] 到达首都的最少油耗
#

# @lc code=start
from typing import List


class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        n = len(roads) + 1
        g = [[] for _ in range(n)]
        for p in roads:
            g[p[0]].append(p[1])
            g[p[1]].append(p[0])

        ans = 0

        def dfs(u: int, fa: int) -> int:
            sz = 1
            for v in g[u]:
                if v != fa:
                    sz += dfs(v, u)
            if u:
                nonlocal ans
                ans += (sz - 1) // seats + 1
            return sz

        dfs(0, -1)
        return ans


# @lc code=end
