from typing import List


class Solution:
    def countPyramids(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        ans = 0

        def solve():
            nonlocal ans
            f = [[0] * m for _ in range(n)]
            for j in range(m):
                f[n - 1][j] = grid[n - 1][j]
            for i in range(n - 2, -1, -1):
                f[i][0], f[i][m - 1] = grid[i][0], grid[i][m - 1]
                for j in range(1, m - 1):
                    if grid[i][j]:
                        f[i][j] = min(f[i + 1][j - 1], f[i + 1][j], f[i + 1][j + 1]) + 1
                        ans += f[i][j] - 1

        solve()
        for i in range(n // 2):
            for j in range(m):
                grid[i][j], grid[n - i - 1][j] = grid[n - i - 1][j], grid[i][j]
        solve()

        return ans


def main():
    sol = Solution()
    grid = [[1, 1, 1, 1, 0], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [0, 1, 0, 0, 1]]
    print(sol.countPyramids(grid))


main()
