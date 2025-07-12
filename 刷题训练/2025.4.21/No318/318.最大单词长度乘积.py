#
# @lc app=leetcode.cn id=318 lang=python3
#
# [318] 最大单词长度乘积
#

# @lc code=start
from typing import List


class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n = len(words)
        lens = []
        cnt = []
        for word in words:
            cnt_s = [0] * 26
            lens.append(len(word))
            for s in word:
                cnt_s[ord(s) - 97] += 1
            cnt.append(cnt_s)
        ans = 0
        for i in range(n - 1):
            for j in range(i + 1, n):
                flag = True
                for t in range(26):
                    if cnt[i][t] and cnt[j][t]:
                        flag = False
                        break
                if not flag:
                    continue
                ans = max(ans, lens[i] * lens[j])
        return ans


# @lc code=end
