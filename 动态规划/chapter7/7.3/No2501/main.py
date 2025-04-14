from collections import defaultdict
from typing import DefaultDict, List


class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        n = len(nums)
        f = [1] * n
        st: DefaultDict[int, List[int]] = defaultdict()
        st[nums[0]] = [0]
        for i in range(1, n):
            val = nums[i] ** 2
            if val in st:
                for pos in st[val]:
                    f[i] = max(f[i], f[pos] + 1)
            if nums[i] in st:
                st[nums[i]].append(i)
            else:
                st[nums[i]] = [i]
        ans = max(f)
        return -1 if ans == 1 else ans


def main():
    nums = [4, 3, 6, 16, 8, 2]
    sol = Solution()
    print(sol.longestSquareStreak(nums))


main()
