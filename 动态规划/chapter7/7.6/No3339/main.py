class Solution:
    def countOfArrays(self, n: int, m: int, k: int) -> int:
        MOD = 10**9 + 7
        even_c, odd_c = m // 2, (m + 1) // 2
        f = [[[0] * 2 for _ in range(k + 1)] for __ in range(n + 1)]
        f[1][0][0] = even_c
        f[1][0][1] = odd_c
        for i in range(1, n):
            for j in range(k + 1):
                prev_even = f[i][j - 1][0] if j > 0 else 0
                f[i + 1][j][0] = (prev_even + f[i][j][1]) * even_c % MOD
                f[i + 1][j][1] = (f[i][j][0] + f[i][j][1]) * odd_c % MOD
        return (f[n][k][0] + f[n][k][1]) % MOD


def main():
    n = 7
    m = 7
    k = 5
    sol = Solution()
    print(sol.countOfArrays(n, m, k))


main()
