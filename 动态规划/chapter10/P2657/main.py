from functools import cache


def solve(a: int, b: int):
    low, high = str(a), str(b)
    n = len(high)
    low = "0" * (n - len(low)) + low

    @cache
    def dfs(i: int, last: int, limit_low: bool, limit_high: bool, is_num: bool) -> int:
        if i == n:
            return 1 if is_num else 0
        res = 0
        if not is_num and low[i] == "0":
            res = dfs(i + 1, 0, True, False, False)
        lo = int(low[i]) if limit_low else 0
        hi = int(high[i]) if limit_high else 9
        d0 = 0 if is_num else 1
        for d in range(max(lo, d0), hi + 1):
            if is_num:
                if abs(d - last) >= 2:
                    res += dfs(
                        i + 1, d, limit_low and d == lo, limit_high and d == hi, True
                    )
            else:
                res += dfs(
                    i + 1, d, limit_low and d == lo, limit_high and d == hi, True
                )
        return res

    return dfs(0, 0, True, True, False)


a, b = map(int, input().split())
print(solve(a, b))
