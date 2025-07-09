#
# @lc app=leetcode.cn id=1765 lang=python3
#
# [1765] 地图中的最高点
#

# @lc code=start
from collections import deque
from typing import List

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        n, m = len(isWater), len(isWater[0])
        q = deque([])
        vis = [[False] * m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if isWater[i][j] == 1:
                    vis[i][j] = True
                    q.append((i, j, 0))

        ans = [[0] * m for _ in range(n)]
        while q:
            x, y, step = q.popleft()
            ans[x][y] = step

            for k in range(4):
                tx = x + dx[k]
                ty = y + dy[k]
                if tx < 0 or tx >= n or ty < 0 or ty >= m:
                    continue
                if isWater[tx][ty] == 0 and not vis[tx][ty]:
                    vis[tx][ty] = True
                    q.append((tx, ty, step + 1))
        return ans


# @lc code=end
