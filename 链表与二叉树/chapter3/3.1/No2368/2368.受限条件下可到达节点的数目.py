#
# @lc app=leetcode.cn id=2368 lang=python3
#
# [2368] 受限条件下可到达节点的数目
#

# @lc code=start
from typing import List


class Solution:
    def reachableNodes(
        self, n: int, edges: List[List[int]], restricted: List[int]
    ) -> int:
        s = set(restricted)
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        ans = 0

        def dfs(u: int, fa: int):
            nonlocal ans
            ans += 1
            for v in g[u]:
                if v == fa or v in s:
                    continue
                dfs(v, u)

        dfs(0, -1)
        return ans


# @lc code=end
