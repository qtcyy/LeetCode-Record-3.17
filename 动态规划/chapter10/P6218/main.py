from functools import cache


def solve(low, high) -> int:
    low, high = bin(low)[2:], bin(high)[2:]
    n = len(high)
    low = "0" * (n - len(low)) + low

    @cache
    def dfs(
        i: int, cnt0: int, cnt1: int, limit_low: bool, limit_high: bool, is_num: bool
    ) -> int:
        if i == n:
            return 1 if cnt0 >= cnt1 and is_num else 0
        res = 0
        if not is_num and low[i] == "0":
            res = dfs(i + 1, cnt0, cnt1, True, False, False)
        lo = int(low[i]) if limit_low else 0
        hi = int(high[i]) if limit_high else 1
        d0 = 0 if is_num else 1
        for d in range(max(d0, lo), hi + 1):
            res += dfs(
                i + 1,
                cnt0 + (d == 0),
                cnt1 + (d == 1),
                limit_low and d == lo,
                limit_high and d == hi,
                True,
            )
        return res

    return dfs(0, 0, 0, True, True, False)


l, r = map(int, input().split())
print(solve(l, r))
