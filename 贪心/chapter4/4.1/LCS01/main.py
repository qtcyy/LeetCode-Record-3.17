from math import ceil, log


class Solution:
    def leastMinutes(self, n: int) -> int:
        return ceil(log(n) / log(2)) + 1


class Solution2:
    def leastMinutes(self, n: int) -> int:
        """
        DP做法
        f[i]表示完成i个下载的最低时间
        """
        f = [0] * (n + 1)
        f[0] = 1
        for i in range(1, n + 1):
            f[i] = f[(i + 1) // 2] + 1
        return f[n]


def main():
    n = 4
    sol = Solution2()
    print(sol.leastMinutes(n))


main()
