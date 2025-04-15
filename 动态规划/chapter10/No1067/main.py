from functools import cache


class Solution:
    def digitsCount(self, d: int, low, high) -> int:
        low, high = str(low), str(high)
        n = len(high)
        low = "0" * (n - len(low)) + low

        @cache
        def dfs(
            i: int, cnt: int, limit_low: bool, limit_high: bool, is_num: bool
        ) -> int:
            if i == n:
                return cnt if is_num else 0
            res = 0
            if not is_num and low[i] == "0":
                res = dfs(i + 1, cnt, True, False, False)
            lo = int(low[i]) if limit_low else 0
            hi = int(high[i]) if limit_high else 9

            d0 = 1 - int(is_num)
            for x in range(max(lo, d0), hi + 1):
                res += dfs(
                    i + 1,
                    cnt + (x == d),
                    limit_low and x == lo,
                    limit_high and x == hi,
                    True,
                )
            return res

        return dfs(0, 0, True, True, False)


def main():
    d = 3
    low = 100
    high = 250
    sol = Solution()
    print(sol.digitsCount(d, low, high))


main()
