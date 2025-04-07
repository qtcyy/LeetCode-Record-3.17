from collections import Counter
from typing import List


class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        cnt = Counter()
        ans = 0
        for word in words:
            rev = word[::-1]
            if cnt[rev] >= 1:
                ans += 2
                cnt[rev] -= 1
            else:
                cnt[word] += 1

        for key, value in cnt.items():
            rev = key[::-1]
            if rev == key and value >= 1:
                ans += 1
                break

        return ans * 2


def main():
    words = ["cc", "ll", "xx"]
    sol = Solution()
    print(sol.longestPalindrome(words))


main()
