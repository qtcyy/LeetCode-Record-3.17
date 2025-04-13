class Solution:
    def waysToDistribute(self, n: int, k: int) -> int:
        """
        f[i][j] i个袋子，j颗糖果
        f[i][j] f[i][j+1]
        放前面的袋子
        f[i][j+1]=i*f[i][j]
        单独放一个袋子
        f[i][j+1]=f[i-1][j]
        """
        MOD = 10**9 + 7
        f = [[0] * (n + 1) for _ in range(k + 1)]
        for i in range(1, k + 1):
            f[i][i] = 1
            for j in range(i + 1, n + 1):
                f[i][j] = (f[i][j - 1] * i + f[i - 1][j - 1]) % MOD
        return f[-1][-1]


def main():
    n = 20
    k = 5
    sol = Solution()
    print(sol.waysToDistribute(n, k))


main()
