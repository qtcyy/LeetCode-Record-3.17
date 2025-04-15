from functools import cache


class Solution:
    def findMaximumNumber(self, k: int, x: int) -> int:
        def check(mid: int) -> bool:
            m = mid.bit_length()

            @cache
            def dfs(i: int, cnt: int, is_limit: bool) -> int:
                if i == 0:
                    return cnt
                up = mid >> (i - 1) & 1 if is_limit else 1
                res = 0
                for d in range(up + 1):
                    res += dfs(
                        i - 1, cnt + (d == 1 and i % x == 0), is_limit and d == up
                    )
                return res

            return dfs(m, 0, True) <= k

        l, r = -1, ((k + 1) << x) + 1
        while l + 1 < r:
            mid = (l + r) >> 1
            if check(mid):
                l = mid
            else:
                r = mid

        return l


def main():
    k = 7
    x = 2
    sol = Solution()
    print(sol.findMaximumNumber(k, x))


main()
