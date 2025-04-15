from functools import cache


def solve(low: str, high: str) -> int:
    n = len(high)
    low = "0" * (n - len(low)) + low
    empty = tuple([0] * 10)

    @cache
    def dfs(i: int, cnt: tuple, limit_low: bool, limit_high: bool, is_num: bool) -> int:
        if i == n:
            return 1 if max(cnt) * 2 >= sum(cnt) and is_num else 0
        res = 0
        if not is_num and low[i] == "0":
            res = dfs(i + 1, cnt, True, False, False)
        lo = int(low[i]) if limit_low else 0
        hi = int(high[i]) if limit_high else 9
        d0 = 0 if is_num else 1
        for d in range(max(d0, lo), hi + 1):
            nxt = list(cnt)
            nxt[d] += 1
            res += dfs(
                i + 1,
                tuple(nxt),
                limit_low and d == lo,
                limit_high and d == hi,
                True,
            )
        return res

    return dfs(0, empty, True, True, False)


l, r = map(str, input().split())
print(solve(l, r))
