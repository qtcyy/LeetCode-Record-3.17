from collections import Counter


class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        right = len(s)
        cnt = Counter(s)
        left = 0
        for x in cnt.values():
            if x & 1:
                left += 1
        left = max(1, left)

        return left <= k and k <= right


def main():
    s = "annabelle"
    k = 2
    sol = Solution()
    print(sol.canConstruct(s, k))


main()
