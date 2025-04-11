class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        """
        f[i][j] 剩余i步，位置在j
        状态：原地 向左 向右
        f[i][j]=sum{f[i+1][j],f[i+1][j+1],f[i+1][j-1]}
        """
        MOD = 10**9 + 7
        mx = min(steps // 2, arrLen - 1)
        f = [[0] * (mx + 1) for _ in range(steps + 1)]
        f[steps][0] = 1
        for i in range(steps - 1, -1, -1):
            for j in range(mx + 1):
                f[i][j] = (f[i][j] + f[i + 1][j]) % MOD
                if j - 1 >= 0:
                    f[i][j] = (f[i][j] + f[i + 1][j - 1]) % MOD
                if j + 1 <= mx:
                    f[i][j] = (f[i][j] + f[i + 1][j + 1]) % MOD
        return f[0][0]


def main():
    steps = 3
    arrLen = 2
    sol = Solution()
    print(sol.numWays(steps, arrLen))


main()
