#
# @lc app=leetcode.cn id=36 lang=python3
#
# [36] 有效的数独
#

# @lc code=start
from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def check_row() -> bool:
            for i in range(9):
                rec = [False] * 10
                for j in range(9):
                    if board[i][j] != ".":
                        if rec[int(board[i][j])]:
                            return False
                        rec[int(board[i][j])] = True
            return True

        def check_col() -> bool:
            for j in range(9):
                rec = [False] * 10
                for i in range(9):
                    if board[i][j] != ".":
                        if rec[int(board[i][j])]:
                            return False
                        rec[int(board[i][j])] = True
            return True

        def check_unit() -> bool:
            for k in range(9):
                row = k // 3 * 3
                col = k % 3 * 3
                rec = [False] * 10
                for i in range(row, row + 3):
                    for j in range(col, col + 3):
                        if board[i][j] != ".":
                            if rec[int(board[i][j])]:
                                return False
                            rec[int(board[i][j])] = True
            return True

        if check_row() and check_col() and check_unit():
            return True
        return False


# @lc code=end
