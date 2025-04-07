from collections import Counter
from typing import List, Tuple


class Solution:
    def largestPalindromic(self, num: str) -> str:
        a = list(num)
        cnt = Counter(a)
        odd = -1
        rec: List[Tuple[int, str]] = []
        for s, c in cnt.items():
            if c & 1:
                if c - 1:
                    rec.append((c - 1, s))
                odd = max(odd, int(s))
            else:
                rec.append((c, s))
        rec.sort(key=lambda x: (-int(x[1]), -x[0]))

        print(rec)
        ans = ""
        for c, s in rec:
            ans += s * (c // 2)
        tmp = ans[::-1]
        print(odd)
        if odd != -1:
            ans += str(odd)
        ans += tmp

        return ans if ans[0] != "0" else str(odd) if odd != -1 else "0"


def main():
    num = "444947137"
    sol = Solution()
    print(sol.largestPalindromic(num))


main()
