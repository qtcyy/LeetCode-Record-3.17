#
# @lc app=leetcode.cn id=2467 lang=python3
#
# [2467] 树上最大得分和路径
#
from typing import List


# @lc code=start
class Solution:
    def mostProfitablePath(
        self, edges: List[List[int]], bob: int, amount: List[int]
    ) -> int:
        n = len(edges) + 1
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        time = [n] * n

        def dfs_bob(u: int, fa: int, t: int) -> bool:
            if u == 0:
                time[0] = t
                return True
            for v in g[u]:
                if v != fa and dfs_bob(v, u, t + 1):
                    time[u] = t
                    return True
            return False

        dfs_bob(bob, -1, 0)

        ans = -(2**31)
        g[0].append(-1)

        def dfs_alice(u: int, fa: int, cnt: int, t: int) -> None:
            if t < time[u]:
                cnt += amount[u]
            elif t == time[u]:
                cnt += amount[u] // 2
            if len(g[u]) == 1:
                nonlocal ans
                ans = max(ans, cnt)
            for v in g[u]:
                if v != fa:
                    dfs_alice(v, u, cnt, t + 1)

        dfs_alice(0, -1, 0, 0)
        return ans


# @lc code=end
