#
# @lc app=leetcode.cn id=2718 lang=python3
#
# [2718] 查询后矩阵的和
#

# @lc code=start
from typing import List


class Solution:
    def matrixSumQueries(self, n: int, queries: List[List[int]]) -> int:
        row, col = set(), set()
        ans = 0
        for type, i, val in queries[::-1]:
            if type:
                if i not in col:
                    ans += val * (n - len(row))
                    col.add(i)
            else:
                if i not in row:
                    ans += val * (n - len(col))
                    row.add(i)
        return ans


# @lc code=end
