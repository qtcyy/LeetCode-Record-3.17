#
# @lc app=leetcode.cn id=1519 lang=python3
#
# [1519] 子树中标签相同的节点数
#

# @lc code=start
from typing import List


class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        g = [[] for _ in range(n)]
        for p in edges:
            g[p[0]].append(p[1])
            g[p[1]].append(p[0])
        val = []
        for ch in labels:
            num = ord(ch) - 97
            val.append(num)
        ans = [0] * n

        def dfs(u: int, fa: int) -> List[int]:
            cnt = [0] * 26
            cnt[val[u]] = 1
            for v in g[u]:
                if v != fa:
                    tmp = dfs(v, u)
                    for i in range(26):
                        cnt[i] += tmp[i]
            ans[u] = cnt[val[u]]
            return cnt

        dfs(0, -1)
        return ans


# @lc code=end
