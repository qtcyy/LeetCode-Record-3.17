from typing import List


class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=len)
        f = {}
        for x in words:
            res = 0
            for i in range(len(x)):
                res = max(res, f.get(x[:i] + x[i + 1 :], 0))
            f[x] = res + 1
        return max(f.values())


def main():
    words = ["a", "b", "ba", "bca", "bda", "bdca"]
    sol = Solution()
    print(sol.longestStrChain(words))


main()
