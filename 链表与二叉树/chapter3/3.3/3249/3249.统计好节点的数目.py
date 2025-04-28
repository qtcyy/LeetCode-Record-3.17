#
# @lc app=leetcode.cn id=3249 lang=python3
#
# [3249] 统计好节点的数目
#

# @lc code=start
from collections import Counter
from typing import List


class Solution:
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        g = [[] for _ in range(n)]
        for p in edges:
            g[p[0]].append(p[1])
            g[p[1]].append(p[0])

        res = 0
        # g[0].append(-1)

        def dfs(u: int, fa: int) -> int:
            nonlocal res

            rec = []
            for v in g[u]:
                if v != fa:
                    rec.append(dfs(v, u))
            if not rec or len(Counter(rec).keys()) == 1:
                res += 1

            return sum(rec) + 1

        dfs(0, -1)
        return res


# @lc code=end
