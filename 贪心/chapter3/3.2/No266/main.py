from collections import Counter


class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        cnt = Counter(s)
        return sum(c % 2 for c in cnt.values()) <= 1


def main():
    s = "carerac"
    sol = Solution()
    print(sol.canPermutePalindrome(s))


main()
