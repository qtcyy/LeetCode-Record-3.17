#
# @lc app=leetcode.cn id=1376 lang=python3
#
# [1376] 通知所有员工所需的时间
#
from typing import List


# @lc code=start
class Solution:
    def numOfMinutes(
        self, n: int, headID: int, manager: List[int], informTime: List[int]
    ) -> int:
        g = [[] for _ in range(n)]
        for i, v in enumerate(manager):
            if v == -1:
                continue
            g[v].append(i)

        ans = 0

        def dfs(u: int, time: int):
            nonlocal ans
            ans = max(ans, time)
            for v in g[u]:
                dfs(v, time + informTime[v])

        dfs(headID, informTime[headID])
        return ans


# @lc code=end
