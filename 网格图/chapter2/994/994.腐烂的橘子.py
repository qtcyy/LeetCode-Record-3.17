#
# @lc app=leetcode.cn id=994 lang=python3
#
# [994] 腐烂的橘子
#

# @lc code=start
from collections import deque
from typing import List

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        q = deque([])
        vis = [[False] * m for _ in range(n)]

        cnt = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.append((i, j, 0))
                    vis[i][j] = True
                elif grid[i][j] == 1:
                    cnt += 1

        if cnt == 0:
            return 0

        while q:
            x, y, step = q.popleft()
            if cnt == 0:
                return step
            for k in range(4):
                tx = x + dx[k]
                ty = y + dy[k]
                if tx < 0 or tx >= n or ty < 0 or ty >= m:
                    continue
                if grid[tx][ty] != 0 and not vis[tx][ty]:
                    vis[tx][ty] = True
                    cnt -= 1
                    if cnt == 0:
                        return step + 1
                    q.append((tx, ty, step + 1))

        return -1


# @lc code=end
