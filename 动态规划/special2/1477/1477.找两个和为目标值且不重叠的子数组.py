#
# @lc app=leetcode.cn id=1477 lang=python3
#
# [1477] 找两个和为目标值且不重叠的子数组
#
from collections import defaultdict
from typing import List


# @lc code=start
class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)
        rec = defaultdict(int)
        sm = 0
        inf = 2**31
        pre_min = [inf] * (n + 1)
        suf_min = [inf] * (n + 1)
        for i, x in enumerate(arr):
            rec[sm] = i
            sm += x
            if sm - target in rec:
                pre_min[i + 1] = min(pre_min[i], i - rec[sm - target] + 1)
            else:
                pre_min[i + 1] = pre_min[i]
        sm = 0
        rec = defaultdict(int)
        for i in range(n - 1, -1, -1):
            rec[sm] = i
            sm += arr[i]
            if sm - target in rec:
                suf_min[i] = min(suf_min[i + 1], rec[sm - target] - i + 1)
            else:
                suf_min[i] = suf_min[i + 1]

        ans = inf
        for i in range(n):
            if pre_min[i] != inf and suf_min[i] != inf:
                ans = min(ans, pre_min[i] + suf_min[i])
        return -1 if ans == inf else ans


# @lc code=end
