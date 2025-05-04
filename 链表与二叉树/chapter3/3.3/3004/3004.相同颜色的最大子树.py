#
# @lc app=leetcode.cn id=3004 lang=python3
#
# [3004] 相同颜色的最大子树
#

# @lc code=start
from typing import List


class Solution:
    def maximumSubtreeSize(self, edges: List[List[int]], colors: List[int]) -> int:
        n = len(colors)
        g = [[] for _ in range(n)]
        for p in edges:
            g[p[0]].append(p[1])
            g[p[1]].append(p[0])

        ans = 0

        def dfs(u: int, fa: int) -> tuple:
            co = colors[u]
            sz = 1
            valid = True
            for v in g[u]:
                if v == fa:
                    continue
                c_valid, c_sz = dfs(v, u)
                sz += c_sz
                if not c_valid or co != colors[v]:
                    valid = False
            if valid:
                nonlocal ans
                ans = max(ans, sz)
            return valid, sz

        dfs(0, -1)

        return ans


# @lc code=end
