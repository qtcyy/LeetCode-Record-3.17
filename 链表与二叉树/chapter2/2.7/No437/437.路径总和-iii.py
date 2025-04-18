#
# @lc app=leetcode.cn id=437 lang=python3
#
# [437] 路径总和 III
#
from collections import defaultdict
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lc code=start
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        s = defaultdict(int)
        ans = 0
        s[0] = 1

        def dfs(node: Optional[TreeNode], val: int):
            nonlocal ans
            if node is None:
                return
            cur = val + node.val
            ans += s[cur - targetSum]
            s[cur] += 1
            dfs(node.left, cur)
            dfs(node.right, cur)
            s[cur] -= 1

        dfs(root, 0)
        return ans


# @lc code=end
