#
# @lc app=leetcode.cn id=2925 lang=python3
#
# [2925] 在树上执行操作以后得到的最大分数
#

# @lc code=start
from typing import List


class Solution:
    def maximumScoreAfterOperations(
        self, edges: List[List[int]], values: List[int]
    ) -> int:
        n = len(values)
        g = [[] for _ in range(n)]
        g[0].append(-1)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        tot = sum(values)

        def dfs(u: int, fa: int) -> int:
            if len(g[u]) == 1:
                return values[u]
            loss = 0
            for v in g[u]:
                if v == fa:
                    continue
                loss += dfs(v, u)
            return min(loss, values[u])

        return tot - dfs(0, -1)


# @lc code=end
