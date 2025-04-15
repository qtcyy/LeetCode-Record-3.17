from functools import cache


def solve(n: int) -> int:
    MOD = 10**7 + 7
    s = bin(n)[2:]
    n = len(s)

    @cache
    def dfs(i: int, cnt: int, is_limit: bool, is_num: bool) -> int:
        if i == n:
            return cnt if is_num else 1
        res = 1
        if not is_num:
            res = dfs(i + 1, cnt, False, False) % MOD
        up = int(s[i]) if is_limit else 1
        d0 = 0 if is_num else 1
        for d in range(d0, up + 1):
            res = (res * dfs(i + 1, cnt + d, is_limit and d == up, True)) % MOD
        return res

    return dfs(0, 0, True, False)


n = int(input())
print(solve(n))
