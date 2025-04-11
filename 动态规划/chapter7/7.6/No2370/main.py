class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        """
        f[i][k] 以k结尾的最长
        convert:
        f[i]=max(f[last])+1
        """
        n = len(s)
        f = [1] * (n)
        last = [-1] * 26
        for i, s in enumerate(s):
            x = ord(s) - 97
            for j in range(26):
                pos = abs(j - x)
                if pos <= k and last[j] != -1:
                    f[i] = max(f[i], f[last[j]] + 1)

            last[x] = i
        return max(f)


def main():
    s = "acfgbd"
    k = 2
    sol = Solution()
    print(sol.longestIdealString(s, k))


main()
