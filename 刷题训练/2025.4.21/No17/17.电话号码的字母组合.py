#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#

# @lc code=start
from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        n = len(digits)
        if n == 0:
            return []
        dic = {
            2: "abc",
            3: "def",
            4: "ghi",
            5: "jkl",
            6: "mno",
            7: "pqrs",
            8: "tuv",
            9: "wxyz",
        }
        ans: List[str] = []
        rec: List[str] = []

        def dfs(i: int) -> None:
            if i == n:
                ans.append("".join(rec))
                return
            for ch in dic[int(digits[i])]:
                rec.append(ch)
                dfs(i + 1)
                rec.pop()

        dfs(0)
        return ans


# @lc code=end
