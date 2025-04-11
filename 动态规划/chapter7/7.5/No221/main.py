from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n, m = len(matrix), len(matrix[0])
        f = [[0] * m for _ in range(n)]
        for i in range(m):
            if matrix[0][i] == "1":
                f[0][i] = 1
        for i in range(n):
            if matrix[i][0] == "1":
                f[i][0] = 1
        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][j] == "1":
                    f[i][j] = min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1
        res = max(map(max, f))
        return res * res


def main():
    matrix = [
        ["1", "0", "1", "0", "0"],
        ["1", "0", "1", "1", "1"],
        ["1", "1", "1", "1", "1"],
        ["1", "0", "0", "1", "0"],
    ]
    sol = Solution()
    print(sol.maximalSquare(matrix))


main()
