from functools import cache


class Solution:
    def beautifulNumbers(self, l: int, r: int) -> int:
        low, high = str(l), str(r)
        n = len(high)
        low = "0" * (n - len(low)) + low

        @cache
        def dfs(
            i: int, s: int, m: int, limit_low: bool, limit_high: bool, is_num: bool
        ) -> int:
            if i == n:
                return 0 if s == 0 or m % s else 1
            res = 0
            if not is_num and low[i] == "0":
                res = dfs(i + 1, 0, 1, True, False, False)
            lo = int(low[i]) if limit_low else 0
            hi = int(high[i]) if limit_high else 9
            d0 = 0 if is_num else 1
            for d in range(max(lo, d0), hi + 1):
                res += dfs(
                    i + 1,
                    s + d,
                    m * d,
                    limit_low and d == lo,
                    limit_high and d == hi,
                    True,
                )
            return res

        return dfs(0, 0, 1, True, True, False)


def main():
    l = 10
    r = 20
    sol = Solution()
    print(sol.beautifulNumbers(l, r))


main()
