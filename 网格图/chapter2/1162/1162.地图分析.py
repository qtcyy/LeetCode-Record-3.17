#
# @lc app=leetcode.cn id=1162 lang=python3
#
# [1162] 地图分析
#

# @lc code=start
from collections import deque
from typing import List

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)

        # 多源BFS：将所有陆地作为起点
        q = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    q.append((i, j, 0))  # (x, y, distance)

        # 如果没有陆地或没有海洋，返回-1
        if len(q) == 0 or len(q) == n * n:
            return -1

        max_dist = -1

        while q:
            x, y, dist = q.popleft()

            for k in range(4):
                tx = x + dx[k]
                ty = y + dy[k]

                if tx < 0 or tx >= n or ty < 0 or ty >= n:
                    continue

                # 如果是海洋且未被访问过
                if grid[tx][ty] == 0:
                    grid[tx][ty] = 1  # 标记为已访问
                    q.append((tx, ty, dist + 1))
                    max_dist = max(max_dist, dist + 1)

        return max_dist


# @lc code=end
