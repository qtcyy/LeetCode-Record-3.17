from functools import cache


class Solution:
    def count(self, num1: str, num2: str, min_sum: int, max_sum: int) -> int:
        MOD = 10**9 + 7
        n = len(num2)
        num1 = "0" * (n - len(num1)) + num1

        @cache
        def dfs(i: int, cnt: int, limit_low: bool, limit_high: bool) -> int:
            if i == n:
                return int(min_sum <= cnt <= max_sum)
            res = 0
            lo = int(num1[i]) if limit_low else 0
            hi = int(num2[i]) if limit_high else 9
            for d in range(lo, hi + 1):
                if cnt + d <= max_sum:
                    res = (
                        res
                        + dfs(
                            i + 1,
                            cnt + d,
                            limit_low and d == lo,
                            limit_high and d == hi,
                        )
                    ) % MOD
            return res

        return dfs(0, 0, True, True)


def main():
    num1 = "1"
    num2 = "12"
    min_num = 1
    max_num = 8
    sol = Solution()
    print(sol.count(num1, num2, min_num, max_num))


main()
