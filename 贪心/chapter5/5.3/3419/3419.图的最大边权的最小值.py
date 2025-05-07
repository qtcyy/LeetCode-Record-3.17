#
# @lc app=leetcode.cn id=3419 lang=python3
#
# [3419] 图的最大边权的最小值
#

# @lc code=start
from heapq import heappop, heappush
from typing import List


class Solution:
    def minMaxWeight(self, n: int, edges: List[List[int]], threshold: int) -> int:
        m = len(edges)
        if m < n - 1:
            return -1

        g = [[] for _ in range(n)]
        for x, y, w in edges:
            g[y].append((x, w))
        inf = 10**9
        dis = [inf] * n
        dis[0] = 0
        h = [(0, 0)]
        while h:
            d, x = heappop(h)
            if d > dis[x]:
                continue
            for y, w in g[x]:
                new_d = max(d, w)
                if new_d < dis[y]:
                    dis[y] = new_d
                    heappush(h, (new_d, y))
        ans = max(dis)
        return -1 if ans == 10**9 else ans


# @lc code=end
