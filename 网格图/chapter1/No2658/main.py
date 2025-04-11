from typing import List


class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        de = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        cnt = 0

        def dfs(x, y):
            nonlocal cnt
            cnt += grid[x][y]
            grid[x][y] = 0
            for d in de:
                tx, ty = x + d[0], y + d[1]
                if tx < 0 or tx >= n or ty < 0 or ty >= m:
                    continue
                if grid[tx][ty]:
                    dfs(tx, ty)

        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    cnt = 0
                    dfs(i, j)
                    ans = max(ans, cnt)
        return ans


def main():
    grid = [[0, 2, 1, 0], [4, 0, 0, 3], [1, 0, 0, 4], [0, 3, 2, 0]]
    sol = Solution()
    print(sol.findMaxFish(grid))


main()
