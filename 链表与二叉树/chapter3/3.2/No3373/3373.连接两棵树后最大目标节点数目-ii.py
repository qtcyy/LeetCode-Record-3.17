#
# @lc app=leetcode.cn id=3373 lang=python3
#
# [3373] 连接两棵树后最大目标节点数目 II
#
from typing import List


# @lc code=start
class Solution:
    def maxTargetNodes(
        self, edges1: List[List[int]], edges2: List[List[int]]
    ) -> List[int]:
        cnt1, cnt2 = 0, 0
        n = len(edges1) + 1
        g = [[] for _ in range(n)]
        for u, v in edges1:
            g[u].append(v)
            g[v].append(u)

        def dfs(u: int, fa: int, p: int):
            if p & 1:
                nonlocal cnt2
                cnt2 += 1
            else:
                nonlocal cnt1
                cnt1 += 1
            for v in g[u]:
                if v != fa:
                    dfs(v, u, p + 1)

        dfs(0, -1, 0)

        m = len(edges2) + 1
        g2 = [[] for _ in range(m)]
        for u, v in edges2:
            g2[u].append(v)
            g2[v].append(u)
        cnt3, cnt4 = 0, 0

        def dfs2(u: int, fa: int, p: int):
            if p & 1:
                nonlocal cnt4
                cnt4 += 1
            else:
                nonlocal cnt3
                cnt3 += 1
            for v in g2[u]:
                if v != fa:
                    dfs2(v, u, p + 1)

        dfs2(0, -1, 0)
        cnt = max(cnt3, cnt4)

        ans = [cnt] * n

        def dfs3(u: int, fa: int, p: int):
            if p & 1:
                ans[u] += cnt2
            else:
                ans[u] += cnt1
            for v in g[u]:
                if v != fa:
                    dfs3(v, u, p + 1)

        dfs3(0, -1, 0)
        return ans


# @lc code=end
