#
# @lc app=leetcode.cn id=1091 lang=python3
#
# [1091] 二进制矩阵中的最短路径
#

# @lc code=start
from collections import deque
from typing import List

dx = [0, 1, 0, -1, 1, 1, -1, -1]
dy = [1, 0, -1, 0, 1, -1, 1, -1]


class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] == 1 or grid[-1][-1] == 1:
            return -1
        n, m = len(grid), len(grid[0])
        q = deque([(0, 0, 1)])
        vis = [[False] * m for _ in range(n)]

        while q:
            x, y, step = q.popleft()
            if x == n - 1 and y == m - 1:
                return step
            for k in range(8):
                tx = x + dx[k]
                ty = y + dy[k]
                if tx < 0 or tx >= n or ty < 0 or ty >= m:
                    continue
                if grid[tx][ty] == 0 and not vis[tx][ty]:
                    q.append((tx, ty, step + 1))
                    vis[tx][ty] = True
        return -1


# @lc code=end
