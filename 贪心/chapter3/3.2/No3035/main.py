from collections import Counter
from typing import List


class Solution:
    def maxPalindromesAfterOperations(self, words: List[str]) -> int:
        n = len(words)
        vis = [False] * n
        for i in range(n - 1):
            for j in range(i + 1, n):
                tmp = list(words[i] + words[j])
                cnt = Counter(tmp)
                odd = 0
                for c in cnt.values():
                    odd += c % 2
                if odd <= 1:
                    vis[i], vis[j] = True, True
        for i in range(n):
            if words[i] == words[i][::-1]:
                vis[i] = True
        ans = 0
        for i in range(n):
            ans += vis[i]
        return ans


class Solution2:
    def maxPalindromesAfterOperations(self, words: List[str]) -> int:
        tot = ans = 0
        cnt = Counter()
        for w in words:
            cnt += Counter(w)
            tot += len(w)
        tot -= sum(c % 2 for c in cnt.values())
        words.sort(key=len)
        for w in words:
            tot -= len(w) // 2 * 2
            if tot < 0:
                break
            ans += 1
        return ans


def main():
    words = ["abc", "ab"]
    sol = Solution2()
    print(sol.maxPalindromesAfterOperations(words))


main()
