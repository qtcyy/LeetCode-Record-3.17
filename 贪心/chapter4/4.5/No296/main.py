from typing import List


class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        px, py = [], []
        n, m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    px.append(i)
                    py.append(j)

        n, m = len(px), len(py)
        py.sort()
        base_x, base_y = px[n // 2], py[m // 2]
        ans = 0
        for i in range(n):
            ans += abs(base_x - px[i])
        for i in range(m):
            ans += abs(base_y - py[i])
        return ans


def main():
    grid = [[1, 0, 0, 0, 1], [0, 0, 0, 0, 0], [0, 0, 1, 0, 0]]
    sol = Solution()
    print(sol.minTotalDistance(grid=grid))


main()
