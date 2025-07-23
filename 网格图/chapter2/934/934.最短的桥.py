#
# @lc app=leetcode.cn id=934 lang=python3
#
# [934] 最短的桥
#

# @lc code=start
from collections import deque
from typing import List

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        q = deque([])

        def dfs(x, y):
            if x < 0 or x >= n or y < 0 or y >= n or grid[x][y] != 1:
                return
            q.append((x, y))
            grid[x][y] = -1
            for k in range(4):
                dfs(x + dx[k], y + dy[k])

        found = False
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    dfs(i, j)
                    found = True
                if found:
                    break
            if found:
                break

        res = 0
        while q:
            size = len(q)
            while size:
                size -= 1
                x, y = q.popleft()
                for k in range(4):
                    tx = x + dx[k]
                    ty = y + dy[k]
                    if tx < 0 or tx >= n or ty < 0 or ty >= n:
                        continue
                    if grid[tx][ty] == 1:
                        return res
                    if grid[tx][ty] == 0:
                        q.append((tx, ty))
                        grid[tx][ty] = -1
            res += 1
        return res


# @lc code=end
