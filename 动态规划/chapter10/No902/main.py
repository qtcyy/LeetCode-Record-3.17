from functools import cache
from typing import List


class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        s = str(n)

        @cache
        def dfs(i: int, is_limit: bool, is_num: bool) -> int:
            if i == len(s):
                return int(is_num)
            res = 0
            if not is_num:
                res = dfs(i + 1, False, False)
            up = int(s[i]) if is_limit else 9
            for x in digits:
                x = int(x)
                if x > up:
                    break
                res += dfs(i + 1, is_limit and x == up, True)

            return res

        return dfs(0, True, False)


def main():
    digits = ["1", "4", "9"]
    n = 1000000000
    sol = Solution()
    print(sol.atMostNGivenDigitSet(digits, n))


main()
