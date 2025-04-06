from collections import Counter
from typing import List


class Solution:
    def maximizeGreatness(self, nums: List[int]) -> int:
        """
        1111122222
        """
        cnt = Counter(nums)
        lens = max(cnt.values())
        return len(nums) - lens


def main():
    nums = [1, 3, 5, 2, 1, 3, 1]
    sol = Solution()
    print(sol.maximizeGreatness(nums))


main()
