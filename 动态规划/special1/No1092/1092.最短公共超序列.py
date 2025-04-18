#
# @lc app=leetcode.cn id=1092 lang=python3
#
# [1092] 最短公共超序列
#


# @lc code=start
class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        n, m = len(str1), len(str2)
        f = [[0] * (m + 1) for _ in range(n + 1)]
        f[0] = range(m + 1)
        s1, s2 = list(str1), list(str2)
        for i in range(1, n + 1):
            f[i][0] = i
        for i in range(n):
            for j in range(m):
                if s1[i] == s2[j]:
                    f[i + 1][j + 1] = f[i][j] + 1
                else:
                    f[i + 1][j + 1] = min(f[i][j + 1], f[i + 1][j]) + 1

        ans = []
        i, j = n - 1, m - 1
        while i >= 0 and j >= 0:
            if s1[i] == s2[j]:
                ans.append(s1[i])
                i -= 1
                j -= 1
            elif f[i + 1][j + 1] == f[i][j + 1] + 1:
                ans.append(s1[i])
                i -= 1
            else:
                ans.append(s2[j])
                j -= 1
        return str1[: i + 1] + str2[: j + 1] + "".join(reversed(ans))


# @lc code=end
