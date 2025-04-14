from typing import List


class Solution:
    def minimumMoves(self, arr: List[int]) -> int:
        """
        f[i][j]区间[i:j+1]的最少次数
        f[i][i]=1
        s[i]=s[j]: f[i+1][j-1]
        s[i]!=s[j]: min(f[i][k],f[k+1][j])
        """
        n = len(arr)
        inf = 2**30
        f = [[inf] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            f[i][i] = 1
            for j in range(i + 1, n):
                if arr[i] == arr[j]:
                    f[i][j] = 1 if i + 1 == j else f[i + 1][j - 1]
                else:
                    for k in range(i, j):
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j])
        return f[0][-1]


def main():
    arr = [1, 3, 4, 1, 5]
    sol = Solution()
    print(sol.minimumMoves(arr))


main()
