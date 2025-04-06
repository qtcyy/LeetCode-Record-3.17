from typing import List


class Solution:
    def maxNumberOfApples(self, weight: List[int]) -> int:
        weight.sort()
        ans, cnt = 0, 0
        for x in weight:
            cnt += x
            if cnt > 5000:
                break
            ans += 1
        return ans


def main():
    weight = [900, 950, 800, 1000, 700, 800]
    sol = Solution()
    print(sol.maxNumberOfApples(weight))


main()
