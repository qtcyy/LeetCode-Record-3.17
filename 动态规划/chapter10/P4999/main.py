from functools import cache


def solve(low: str, high: str) -> int:
    MOD = 10**9 + 7
    n = len(high)
    low = "0" * (n - len(low)) + low

    @cache
    def dfs(i: int, cnt: int, limit_low: bool, limit_high: bool) -> int:
        if i == n:
            return cnt
        res = 0
        lo = int(low[i]) if limit_low else 0
        hi = int(high[i]) if limit_high else 9
        for d in range(lo, hi + 1):
            res = (
                res + dfs(i + 1, cnt + d, limit_low and d == lo, limit_high and d == hi)
            ) % MOD
        return res

    return dfs(0, 0, True, True)


def main():
    t = int(input())
    for _ in range(t):
        low, high = map(str, input().split())
        print(solve(low, high))


main()
