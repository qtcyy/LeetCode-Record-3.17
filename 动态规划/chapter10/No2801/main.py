from functools import cache


class Solution:
    def countSteppingNumbers(self, low: str, high: str) -> int:
        MOD = 10**9 + 7
        n = len(high)
        low = "0" * (n - len(low)) + low

        @cache
        def dfs(
            i: int, last: int, limit_low: bool, limit_high: bool, is_num: bool
        ) -> int:
            if i == n:
                return 1
            res = 0
            if not is_num and low[i] == "0":
                res = dfs(i + 1, 0, True, False, False)
            lo = int(low[i]) if limit_low else 0
            hi = int(high[i]) if limit_high else 9
            d0 = 0 if is_num else 1
            for d in range(max(lo, d0), hi + 1):
                if is_num:
                    if abs(d - last) == 1:
                        res = (
                            res
                            + dfs(
                                i + 1,
                                d,
                                limit_low and d == lo,
                                limit_high and d == hi,
                                True,
                            )
                        ) % MOD
                else:
                    res = (
                        res
                        + dfs(
                            i + 1,
                            d,
                            limit_low and d == lo,
                            limit_high and d == hi,
                            True,
                        )
                    ) % MOD
            return res

        return dfs(0, 0, True, True, False)


def main():
    low = "90"
    high = "101"
    sol = Solution()
    print(sol.countSteppingNumbers(low, high))


main()
