from collections import defaultdict
from functools import cache


class Solution:
    def countLargestGroup(self, n: int) -> int:
        s = str(n)
        rec = defaultdict(int)

        @cache
        def dfs(i: int, cnt: int, is_limit: bool, is_num: bool) -> None:
            if i == len(s):
                if is_num:
                    rec[cnt] += 1
                return
            if not is_num:
                dfs(i + 1, cnt, False, False)
            up = int(s[i]) if is_limit else 9
            for d in range(1 - int(is_num), up + 1):
                dfs(i + 1, cnt + d, is_limit and d == up, True)

        dfs(0, 0, True, False)
        mx = max(rec.values())
        print(rec)
        return sum(1 if x == mx else 0 for x in rec.values())


def main():
    n = 13
    sol = Solution()
    print(sol.countLargestGroup(n))


main()
