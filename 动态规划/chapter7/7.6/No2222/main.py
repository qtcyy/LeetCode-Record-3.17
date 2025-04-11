from collections import Counter


class Solution:
    def numberOfWays(self, s: str) -> int:
        tot = Counter(s)
        print(tot)
        tot_zero = tot["0"]
        ans = 0
        c0 = 0
        for i, ch in enumerate(s):
            if ch == "1":
                ans += c0 * (tot_zero - c0)
            else:
                c1 = i - c0
                ans += c1 * (len(s) - tot_zero - c1)
                c0 += 1
        return ans
