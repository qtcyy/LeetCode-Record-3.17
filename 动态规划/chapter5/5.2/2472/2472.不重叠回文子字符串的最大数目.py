#
# @lc app=leetcode.cn id=2472 lang=python3
#
# [2472] 不重叠回文子字符串的最大数目
#


# @lc code=start
class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        """
        f[i] 前i个中能选择的最大数目
        f[i]=max(f[i],f[j]+1)
        """
        n = len(s)
        f = [0] * (n + 1)
        for i in range(k, n + 1):
            f[i] = f[i - 1]
            for j in range(i - k, -1, -1):
                cur = s[j:i]
                if cur == cur[::-1]:
                    f[i] = max(f[i], f[j] + 1)
        print(f)
        return max(f)


# @lc code=end
