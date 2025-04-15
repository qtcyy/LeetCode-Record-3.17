from functools import cache
from typing import List


class Solution:
    def countSteppingNumbers(self, low, high) -> List[int]:
        low, high = str(low), str(high)
        n = len(high)
        low = "0" * (n - len(low)) + low
        res: List[int] = []

        @cache
        def dfs(i: int, num: int, limit_low: bool, limit_high: bool, is_num: bool):
            if i == n:
                res.append(num)
                return
            if not is_num and low[i] == "0":
                dfs(i + 1, num, True, False, False)
            lo = int(low[i]) if limit_low else 0
            hi = int(high[i]) if limit_high else 9
            d0 = 0 if is_num else 1
            for d in range(max(lo, d0), hi + 1):
                last = num % 10
                if is_num:
                    if abs(d - last) == 1:
                        dfs(
                            i + 1,
                            num * 10 + d,
                            limit_low and d == lo,
                            limit_high and d == hi,
                            True,
                        )
                else:
                    dfs(i + 1, d, limit_low and d == lo, limit_high and d == hi, True)

        dfs(0, 0, True, True, False)
        res.sort()
        return res


def main():
    low = 10
    high = 15
    sol = Solution()
    print(sol.countSteppingNumbers(low, high))


main()
