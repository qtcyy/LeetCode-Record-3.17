from typing import List


class Solution:
    def pondSizes(self, land: List[List[int]]) -> List[int]:
        de = [[0, 1], [1, 0], [0, -1], [-1, 0], [1, 1], [1, -1], [-1, 1], [-1, -1]]
        n, m = len(land), len(land[0])

        area = 0

        def dfs(x, y):
            land[x][y] = 1
            nonlocal area
            for d in de:
                tx, ty = x + d[0], y + d[1]
                if tx < 0 or tx >= n or ty < 0 or ty >= m:
                    continue
                if land[tx][ty] == 0:
                    area += 1
                    dfs(tx, ty)

        res = []
        for i in range(n):
            for j in range(m):
                if land[i][j] == 0:
                    area = 1
                    dfs(i, j)
                    res.append(area)
        return sorted(res)


def main():
    land = [[0, 2, 1, 0], [0, 1, 0, 1], [1, 1, 0, 1], [0, 1, 0, 1]]
    sol = Solution()
    print(sol.pondSizes(land))


main()
