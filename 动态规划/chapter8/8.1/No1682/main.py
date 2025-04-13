class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        f = [[[0] * 26 for _ in range(n)] for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    c = ord(s[i]) - 97
                    for k in range(26):
                        if c != k:
                            f[i][j][c] = max(f[i][j][c], f[i + 1][j - 1][k] + 2)
                            f[i][j][k] = max(f[i + 1][j][k], f[i][j - 1][k])
                else:
                    for k in range(26):
                        f[i][j][k] = max(f[i + 1][j][k], f[i][j - 1][k])

        return max(f[0][n - 1])


def main():
    s = "dcbccacdb"
    sol = Solution()
    print(sol.longestPalindromeSubseq(s))


main()
