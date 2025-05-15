from typing import List

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n, m = len(matrix), len(matrix[0])
        vis = [[False] * m for _ in range(n)]
        ans = []

        def dfs(x: int, y: int, k: int) -> None:
            vis[x][y] = True
            ans.append(matrix[x][y])
            tx = x + dx[k]
            ty = y + dy[k]
            if tx < 0 or tx >= n or ty < 0 or ty >= m or vis[tx][ty]:
                k = (k + 1) % 4
            tx = x + dx[k]
            ty = y + dy[k]
            if tx < 0 or tx >= n or ty < 0 or ty >= m or vis[tx][ty]:
                return
            dfs(tx, ty, k)

        dfs(0, 0, 0)
        return ans


def main():
    matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
    sol = Solution()
    print(sol.spiralOrder(matrix))


main()
