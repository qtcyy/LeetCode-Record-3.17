#
# @lc app=leetcode.cn id=3365 lang=python3
#
# [3365] 重排子字符串以形成目标字符串
#


# @lc code=start
from collections import defaultdict


class Solution:
    def isPossibleToRearrange(self, s: str, t: str, k: int) -> bool:
        n = len(s)
        div = n // k
        cnt1, cnt2 = defaultdict(int), defaultdict(int)
        for i in range(0, n, div):
            cnt1[s[i : i + div]] += 1
            cnt2[t[i : i + div]] += 1
        for sub in cnt1.keys():
            if cnt1[sub] != cnt2[sub]:
                return False
        return True


# @lc code=end
