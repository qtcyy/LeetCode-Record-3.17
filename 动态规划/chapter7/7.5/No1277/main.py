from typing import List


class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        n, m = len(matrix), len(matrix[0])
        ans = 0
        f = [[0] * m for _ in range(n)]
        for i in range(0, n):
            ans += matrix[i][0]
            f[i][0] = matrix[i][0]
        for j in range(0, m):
            ans += matrix[0][j]
            f[0][j] = matrix[0][j]
        if matrix[0][0]:
            ans -= 1
        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][j]:
                    f[i][j] = min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1
                ans += f[i][j]
        return ans


def main():
    matrix = [[0, 1, 1, 1], [1, 1, 1, 1], [0, 1, 1, 1]]
    sol = Solution()
    print(sol.countSquares(matrix))


main()
