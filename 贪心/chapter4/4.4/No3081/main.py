from collections import Counter
from heapq import heapify, heapreplace
from string import ascii_lowercase


class Solution:
    def minimizeStringValue(self, s: str) -> str:
        cnt = Counter(s)
        h = [(cnt[c], c) for c in ascii_lowercase]
        heapify(h)

        t = []
        for _ in range(s.count("?")):
            f, c = h[0]
            t.append(c)
            heapreplace(h, (f + 1, c))
        t.sort()
        p = list(s)
        j = 0
        for i in range(len(p)):
            if p[i] == "?":
                p[i] = t[j]
                j += 1
        return "".join(p)


def main():
    s = "a?a?"
    sol = Solution()
    print(sol.minimizeStringValue(s))


main()
