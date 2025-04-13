class Solution:
    def countPalindromicSubsequences(self, s: str) -> int:
        n = len(s)
        f = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            f[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1] + 2
                else:
                    f[i][j] = max(f[i + 1][j], f[i][j - 1])
        res = 0
        for i in range(n):
            for j in range(i + 1, n):
                res += f[i][j]
        return res


def main():
    s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
    sol = Solution()
    print(sol.countPalindromicSubsequences(s))


main()
