#
# @lc app=leetcode.cn id=1926 lang=python3
#
# [1926] 迷宫中离入口最近的出口
#

# @lc code=start
from collections import deque
from typing import List

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        n, m = len(maze), len(maze[0])
        st = (entrance[0], entrance[1])

        q = deque([(entrance[0], entrance[1], 0)])
        vis = [[False] * m for _ in range(n)]
        while q:
            x, y, step = q.popleft()
            if (x, y) != st and (x == 0 or y == 0 or x == n - 1 or y == m - 1):
                return step
            for k in range(4):
                tx = x + dx[k]
                ty = y + dy[k]
                if tx < 0 or tx >= n or ty < 0 or ty >= m:
                    continue
                if maze[tx][ty] == "." and not vis[tx][ty]:
                    vis[tx][ty] = True
                    q.append((tx, ty, step + 1))
        return -1


# @lc code=end
