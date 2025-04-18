#
# @lc app=leetcode.cn id=3372 lang=python3
#
# [3372] 连接两棵树后最大目标节点数目 I
#
from typing import List


# @lc code=start
class Solution:
    def maxTargetNodes(
        self, edges1: List[List[int]], edges2: List[List[int]], k: int
    ) -> List[int]:
        n = len(edges1) + 1
        g = [[] for _ in range(n)]
        for u, v in edges1:
            g[u].append(v)
            g[v].append(u)

        cnt = [0] * n
        sum = 0

        def dfs(u: int, fa: int, dist: int):
            if dist > k:
                return
            nonlocal sum
            sum += 1
            for v in g[u]:
                if v != fa:
                    dfs(v, u, dist + 1)

        for i in range(n):
            sum = 0
            dfs(i, -1, 0)
            cnt[i] = sum

        m = len(edges2) + 1
        g = [[] for _ in range(m)]
        for u, v in edges2:
            g[u].append(v)
            g[v].append(u)

        mx = sum = 0

        def dfs2(u: int, fa: int, dist: int):
            if dist > k - 1:
                return
            nonlocal sum
            sum += 1
            for v in g[u]:
                if v != fa:
                    dfs2(v, u, dist + 1)

        for i in range(m):
            sum = 0
            dfs2(i, -1, 0)
            mx = max(mx, sum)

        ans = []
        for val in cnt:
            ans.append(val + mx)
        return ans


# @lc code=end
