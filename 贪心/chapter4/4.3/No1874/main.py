from typing import List


class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        nums1.sort()
        nums2.sort(reverse=True)
        ans = 0
        for i, x in enumerate(nums1):
            ans += x * nums2[i]
        return ans


def main():
    sol = Solution()
    nums1 = [2, 1, 4, 5, 7]
    nums2 = [3, 2, 4, 8, 6]
    print(sol.minProductSum(nums1, nums2))


main()
