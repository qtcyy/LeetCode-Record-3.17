#
# @lc app=leetcode.cn id=2484 lang=python3
#
# [2484] 统计回文子序列数目
#


# @lc code=start
class Solution:
    def countPalindromes(self, s: str) -> int:
        """
        前后缀分解，统计以s[i]结尾的序列中出现的长度为2的子序列
        """
        MOD = 10**9 + 7
        a = list(s)
        n = len(a)
        pre = [[0] * 100 for _ in range(n)]
        cnt = [0] * 10
        cnt[int(s[0])] = 1
        for i in range(1, n):
            prev = pre[i - 1].copy()
            for d in range(10):
                if cnt[d]:
                    num = d * 10 + int(s[i])
                    prev[num] += cnt[d]
            cnt[int(s[i])] += 1
            pre[i] = prev
        suf = [[0] * 100 for _ in range(n)]
        cnt = [0] * 10
        cnt[int(s[-1])] = 1
        for i in range(n - 2, -1, -1):
            suff = suf[i + 1].copy()
            for d in range(10):
                if cnt[d]:
                    num = d * 10 + int(s[i])
                    suff[num] += cnt[d]
            cnt[int(s[i])] += 1
            suf[i] = suff
        ans = 0
        for i in range(2, n - 2):
            for d in range(100):
                ans = (ans + pre[i - 1][d] * suf[i + 1][d]) % MOD
        return ans


# @lc code=end
