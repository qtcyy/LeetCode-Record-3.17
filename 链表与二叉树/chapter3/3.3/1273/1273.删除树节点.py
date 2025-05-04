#
# @lc app=leetcode.cn id=1273 lang=python3
#
# [1273] 删除树节点
#

# @lc code=start
from typing import List


class Solution:
    def deleteTreeNodes(self, nodes: int, parent: List[int], value: List[int]) -> int:
        fa = [[] for _ in range(nodes)]
        root = 0
        for i in range(nodes):
            if parent[i] == -1:
                root = i
                continue
            fa[parent[i]].append(i)

        cnt = 0

        def dfs(u: int) -> tuple:
            sz, val = 1, value[u]
            for v in fa[u]:
                tp = dfs(v)
                sz += tp[0]
                val += tp[1]
            if not val:
                nonlocal cnt
                cnt += sz
                return 0, 0
            return sz, val

        dfs(root)
        return nodes - cnt


# @lc code=end
