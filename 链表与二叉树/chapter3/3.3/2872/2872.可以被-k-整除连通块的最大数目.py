#
# @lc app=leetcode.cn id=2872 lang=python3
#
# [2872] 可以被 K 整除连通块的最大数目
#

# @lc code=start
from typing import List


class Solution:
    def maxKDivisibleComponents(
        self, n: int, edges: List[List[int]], values: List[int], k: int
    ) -> int:
        g = [[] for _ in range(n)]
        for p in edges:
            g[p[0]].append(p[1])
            g[p[1]].append(p[0])
        ans = 0

        def dfs(u: int, fa: int) -> int:
            s = values[u]
            for v in g[u]:
                if v != fa:
                    s += dfs(v, u)
            nonlocal ans
            ans += s % k == 0
            return s

        dfs(0, -1)
        return ans


# @lc code=end
