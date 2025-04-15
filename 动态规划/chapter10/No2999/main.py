from functools import cache


class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        low, high = str(start), str(finish)
        n = len(high)
        diff = n - len(s)
        low = "0" * (n - len(low)) + low

        @cache
        def dfs(i: int, limit_low: bool, limit_high: bool) -> int:
            if i == n:
                return 1
            res = 0
            lo = int(low[i]) if limit_low else 0
            hi = int(high[i]) if limit_high else 9
            if i < diff:
                for d in range(lo, min(hi, limit) + 1):
                    res += dfs(i + 1, limit_low and d == lo, limit_high and d == hi)
            else:
                x = int(s[i - diff])
                if lo <= x <= min(hi, limit):
                    res = dfs(i + 1, limit_low and x == lo, limit_high and x == hi)
            return res

        return dfs(0, True, True)


def main():
    start = 15
    finish = 215
    limit = 6
    s = "10"
    sol = Solution()
    print(sol.numberOfPowerfulInt(start, finish, limit, s))


main()
