class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        inf = 2**31
        f = [[inf] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            f[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    f[i][j] = min(f[i + 1][j], f[i][j - 1])
                else:
                    for k in range(i, j):
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j])
        return f[0][-1]


def main():
    s = "aaabbb"
    sol = Solution()
    print(sol.strangePrinter(s))


main()
