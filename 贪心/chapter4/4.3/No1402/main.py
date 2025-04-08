from typing import List


class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        n = len(satisfaction)
        satisfaction.sort()
        ans = 0
        for i in range(n):
            val = 0
            cnt = 1
            for j in range(i, n):
                val += satisfaction[j] * cnt
                cnt += 1
            ans = max(ans, val)
            if satisfaction[i] > 0:
                break
        return ans


def main():
    satisfaction = [-1, -8, 0, 5, -9]
    sol = Solution()
    print(sol.maxSatisfaction(satisfaction))


main()
