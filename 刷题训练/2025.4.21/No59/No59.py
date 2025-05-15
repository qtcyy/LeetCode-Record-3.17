from typing import List

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        vis = [[False] * n for _ in range(n)]
        ans = [[0] * n for _ in range(n)]

        def dfs(x: int, y: int, k: int, i) -> None:
            vis[x][y] = True
            ans[x][y] = i
            tx = x + dx[k]
            ty = y + dy[k]
            if tx < 0 or tx >= n or ty < 0 or ty >= n or vis[tx][ty]:
                k = (k + 1) % 4
            ans[x][y] = i
            tx = x + dx[k]
            ty = y + dy[k]
            if tx < 0 or tx >= n or ty < 0 or ty >= n or vis[tx][ty]:
                return
            dfs(tx, ty, k, i + 1)

        dfs(0, 0, 0, 1)
        return ans


def main():
    n = 3
    sol = Solution()
    print(sol.generateMatrix(n))


main()
