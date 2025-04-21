#
# @lc app=leetcode.cn id=3144 lang=python3
#
# [3144] 分割字符频率相等的最少子字符串
#


# @lc code=start
from collections import defaultdict


class Solution:
    def minimumSubstringsInPartition(self, s: str) -> int:
        n = len(s)
        inf = 2**31
        f = [inf] * (n + 1)
        f[0] = 0
        for i in range(1, n + 1):
            cnt = defaultdict(int)
            for j in range(i - 1, -1, -1):
                cnt[s[j]] += 1
                val = cnt[s[j]]
                flag = True
                for v in cnt.values():
                    if v != val:
                        flag = False
                        break
                if flag:
                    f[i] = min(f[i], f[j] + 1)
        return f[-1]


# @lc code=end
