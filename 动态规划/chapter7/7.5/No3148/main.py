from typing import List


class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        """
        状态:
            从上方或左侧移动过来
            f[i][j]=max(f[i-1][j]+c2-c1,f[i][j-1]+c2-c1,grid[i][j])
        """
        INF = 1 << 31
        n, m = len(grid), len(grid[0])
        f = [[0] * m for _ in range(n)]
        f[0][0] = -INF
        for i in range(1, m):
            val = grid[0][i] - grid[0][i - 1]
            f[0][i] = max(val, f[0][i - 1] + val)
        for i in range(1, n):
            val = grid[i][0] - grid[i - 1][0]
            f[i][0] = max(val, f[i - 1][0] + val)
        for i in range(1, n):
            for j in range(1, m):
                # 上面过来
                val1 = grid[i][j] - grid[i - 1][j]
                # 左边过来
                val2 = grid[i][j] - grid[i][j - 1]
                f[i][j] = max(val1, f[i - 1][j] + val1, val2, f[i][j - 1] + val2)
        return max(map(max, f))


def main():
    grid = [[9, 5, 7, 3], [8, 9, 6, 1], [6, 7, 14, 3], [2, 5, 3, 1]]
    sol = Solution()
    print(sol.maxScore(grid))


main()
