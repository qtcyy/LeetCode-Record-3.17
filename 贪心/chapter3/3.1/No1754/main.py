class Solution:
    def largestMerge(self, word1: str, word2: str) -> str:
        res = ""
        i, j = 0, 0
        n, m = len(word1), len(word2)
        while i < n and j < m:
            if word1[i:] > word2[j:]:
                res += word1[i]
                i += 1
            else:
                res += word2[j]
                j += 1
        return res + word1[i:] + word2[j:]


def main():
    sol = Solution()
    word1 = "cabaa"
    word2 = "bcaaa"
    print(sol.largestMerge(word1, word2))


main()
