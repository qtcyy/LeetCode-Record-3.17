#
# @lc app=leetcode.cn id=3207 lang=python3
#
# [3207] 与敌人战斗后的最大分数
#

# @lc code=start
from typing import List


class Solution:
    def maximumPoints(self, enemyEnergies: List[int], currentEnergy: int) -> int:
        enemyEnergies.sort()
        if currentEnergy < enemyEnergies[0]:
            return 0
        energy = sum(enemyEnergies) + currentEnergy - enemyEnergies[0]
        return energy // enemyEnergies[0]


# @lc code=end
