from functools import cache


def solve(n: int, k: int) -> int:
    m = n.bit_length() - 1

    @cache
    def dfs(i: int, cnt: int, is_limit: bool) -> int:
        if i < 0:
            return int(cnt == k)
        up = n >> i & 1 if is_limit else 1
        res = dfs(i - 1, cnt, is_limit and up == 0)
        if up == 1:
            res += dfs(i - 1, cnt + 1, is_limit and up == 1)

        return res

    return dfs(m, 0, True)


n, k = map(int, input().split())

print(solve(n, k))
