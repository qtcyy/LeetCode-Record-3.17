from functools import cache


class Solution:
    def numberOfBeautifulIntegers(self, low, high, k: int) -> int:
        low, high = str(low), str(high)
        n = len(high)
        low = "0" * (n - len(low)) + low

        @cache
        def dfs(
            i: int,
            length: int,
            cur: int,
            limit_low: bool,
            limit_high: bool,
            is_num: bool,
        ) -> int:
            if i == n:
                return 1 if is_num and length == 0 and cur == 0 else 0
            res = 0
            if not is_num and low[i] == "0":
                res = dfs(i + 1, length, cur, True, False, False)
            lo = int(low[i]) if limit_low else 0
            hi = int(high[i]) if limit_high else 9
            d0 = 0 if is_num else 1
            for d in range(max(lo, d0), hi + 1):
                res += dfs(
                    i + 1,
                    length + d % 2 * 2 - 1,
                    (cur * 10 + d) % k,
                    limit_low and d == lo,
                    limit_high and d == hi,
                    True,
                )
            return res

        return dfs(0, 0, 0, True, True, False)


def main():
    low = 10
    high = 20
    k = 3
    sol = Solution()
    print(sol.numberOfBeautifulIntegers(low, high, k))


main()
