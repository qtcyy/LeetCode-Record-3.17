#
# @lc app=leetcode.cn id=3068 lang=python3
#
# [3068] 最大节点价值之和
#

# @lc code=start
from typing import List


class Solution2:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        g = [[] for _ in nums]
        for x, y in edges:
            g[x].append(y)
            g[y].append(x)
        inf = 2**31

        def dfs(x: int, fa: int) -> tuple:
            f0, f1 = 0, -inf  # f[x][0] 和 f[x][1]
            for y in g[x]:
                if y != fa:
                    r0, r1 = dfs(y, x)
                    f0, f1 = max(f0 + r0, f1 + r1), max(f1 + r0, f0 + r1)
            return max(f0 + nums[x], f1 + (nums[x] ^ k)), max(
                f1 + nums[x], f0 + (nums[x] ^ k)
            )

        return dfs(0, -1)[0]


class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        n = len(nums)
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        inf = 2**31

        def dfs(u: int, fa: int) -> tuple:
            undo, do = 0, -inf
            for v in g[u]:
                if v == fa:
                    continue
                s_undo, s_do = dfs(v, u)
                undo, do = max(s_undo + undo, s_do + do), max(s_undo + do, s_do + undo)
            return max(undo + nums[u], do + (nums[u] ^ k)), max(
                do + nums[u], undo + (nums[u] ^ k)
            )

        return dfs(0, -1)[0]


# @lc code=end
