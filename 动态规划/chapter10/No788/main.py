from functools import cache


class Solution:
    def rotatedDigits(self, n: int) -> int:
        s = str(n)
        valid = (1 << 2) | (1 << 5) | (1 << 6) | (1 << 9)
        invalid = (1 << 3) | (1 << 4) | (1 << 7)

        @cache
        def dfs(i: int, mask: int, is_limit: bool, is_num: bool) -> int:
            if i == len(s):
                if mask & valid and not mask & invalid:
                    return int(is_num)
                else:
                    return 0
            res = 0
            if not is_num:
                res = dfs(i + 1, mask, False, False)
            up = int(s[i]) if is_limit else 9
            for d in range(1 - int(is_num), up + 1):
                if invalid >> d & 1 == 0:
                    res += dfs(i + 1, mask | (1 << d), is_limit and d == up, True)
            return res

        return dfs(0, 0, True, False)


def main():
    n = 10
    sol = Solution()
    print(sol.rotatedDigits(n))


main()
