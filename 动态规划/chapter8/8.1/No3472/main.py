class Solution:
    def longestPalindromicSubsequence(self, s: str, k: int) -> int:
        n = len(s)
        a = list(map(ord, s))
        for i in range(n):
            a[i] -= 97
        f = [[[0] * (k + 1) for _ in range(n)] for __ in range(n)]
        for kk in range(k + 1):
            for i in range(n - 1, -1, -1):
                f[i][i][kk] = 1
                for j in range(i + 1, n):
                    d = abs(a[i] - a[j])
                    op = min(d, 26 - d)
                    if op == 0:
                        f[i][j][kk] = f[i + 1][j - 1][kk] + 2
                    elif op <= kk:
                        f[i][j][kk] = max(
                            f[i + 1][j - 1][kk - op] + 2,
                            f[i + 1][j][kk],
                            f[i][j - 1][kk],
                        )
                    else:
                        f[i][j][kk] = max(f[i + 1][j][kk], f[i][j - 1][kk])
        return f[0][n - 1][k]


def main():
    s = "aaazzz"
    k = 4
    sol = Solution()
    print(sol.longestPalindromicSubsequence(s, k))


main()
