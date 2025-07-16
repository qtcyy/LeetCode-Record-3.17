#
# @lc app=leetcode.cn id=37 lang=python3
#
# [37] 解数独
#

# @lc code=start
from typing import List


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        def get_loc(x, y) -> int:
            return x // 3 * 3 + y % 3

        def dfs(x, y) -> None:
            if board[x][y] != ".":
                if x == 8 and y == 8:
                    exit(0)
                if y == 8:
                    dfs(x + 1, 0)
                else:
                    dfs(x, y + 1)
            else:
                for k in range(1, 10):
                    if not row[x][k] and not col[y][k] and not area[get_loc(x, y)][k]:
                        row[x][k] = True
                        col[y][k] = True
                        area[get_loc(x, y)][k] = True
                        board[x][y] = str(k)
                        if x == 8 and y == 8:
                            exit(0)
                        if y == 8:
                            dfs(x + 1, 0)
                        else:
                            dfs(x, y + 1)
                        board[x][y] = "."
                        row[x][k] = False
                        col[y][k] = False
                        area[get_loc(x, y)][k] = False

        row = [[False] * 10 for _ in range(9)]
        col = [[False] * 10 for _ in range(9)]
        area = [[False] * 10 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    num = int(board[i][j])
                    row[i][num] = True
                    col[j][num] = True
                    area[get_loc(i, j)][num] = True
        dfs(0, 0)


# @lc code=end
