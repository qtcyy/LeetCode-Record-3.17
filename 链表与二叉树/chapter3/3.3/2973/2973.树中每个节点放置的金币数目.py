#
# @lc app=leetcode.cn id=2973 lang=python3
#
# [2973] 树中每个节点放置的金币数目
#

# @lc code=start
from typing import List


class Solution:
    def placedCoins(self, edges: List[List[int]], cost: List[int]) -> List[int]:
        n = len(edges) + 1
        g = [[] for _ in range(n)]
        for p in edges:
            g[p[0]].append(p[1])
            g[p[1]].append(p[0])

        ans = [1] * n

        def dfs(u: int, fa: int) -> List[int]:
            a = [cost[u]]
            for v in g[u]:
                if v != fa:
                    a.extend(dfs(v, u))
            a.sort()
            m = len(a)
            if m >= 3:
                ans[u] = max(a[-3] * a[-2] * a[-1], a[-1] * a[0] * a[1], 0)

            if m > 5:
                a = a[:2] + a[-3:]
            return a

        dfs(0, -1)
        return ans


# @lc code=end
