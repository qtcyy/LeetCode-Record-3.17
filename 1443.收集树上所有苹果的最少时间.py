#
# @lc app=leetcode.cn id=1443 lang=python3
#
# [1443] 收集树上所有苹果的最少时间
#
from typing import List


# @lc code=start
class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        apple = [False] * n

        def get_apple(u: int, fa: int):
            apple[u] = hasApple[u]
            for v in g[u]:
                if v != fa:
                    apple[u] |= get_apple(v, u)
            return apple[u]

        get_apple(0, -1)

        ans = 0

        def dfs(u: int, fa: int):
            nonlocal ans
            for v in g[u]:
                if v != fa and apple[v]:
                    ans += 2
                    dfs(v, u)

        dfs(0, -1)

        return ans


# @lc code=end
