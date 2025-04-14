from collections import Counter
from functools import cache


def solve(s: str) -> int:
    valid = [0] * 10
    empty = tuple(valid)
    for ch in s:
        if ch != "0":
            valid[ord(ch) - ord("0")] += 1
    valid = tuple(valid)

    @cache
    def dfs(i: int, cnt: tuple, is_limit: bool, is_num: bool) -> int:
        if i == len(s):
            return int(is_num and cnt == valid)

        res = 0
        if not is_num:
            res = dfs(i + 1, cnt, False, False)
        up = int(s[i]) if is_limit else 9
        for d in range(1 - int(is_num), up + 1):
            nxt = list(cnt)
            if d != 0:
                nxt[d] += 1
            res += dfs(i + 1, tuple(nxt), is_limit and d == up, True)
        return res

    return dfs(0, empty, True, False)


n = input()
print(solve(n))
