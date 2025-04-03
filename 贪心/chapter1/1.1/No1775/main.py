from typing import List


class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        """
        val = 11
        [0,1,2,3,4,5]
        [5,5,4,4,4,4]
        """
        all1, all2 = sum(nums1), sum(nums2)
        n, m = len(nums1), len(nums2)
        if all1 == all2:
            return 0
        elif all2 > all1:
            nums1, nums2 = nums2, nums1
            n, m = m, n
            all1, all2 = all2, all1
        delta = all1 - all2
        arr1, arr2 = [0] * n, [0] * m
        for i in range(n):
            arr1[i] = nums1[i] - 1
        for i in range(m):
            arr2[i] = 6 - nums2[i]
        arr1.sort(reverse=True)
        arr2.sort(reverse=True)
        i, j = 0, 0
        ans = 0
        if n < m:
            n, m = m, n
            arr1, arr2 = arr2, arr2
        while i < n:
            if delta > max(arr1[i], arr2[j]):
                if delta > arr1[i] + arr2[i]:
                    delta -= arr1[i] + arr2[j]
                else:
                    delta = 0
                    ans += 1
                    break
                arr1[i] = arr2[j] = 0
                ans += 2
            else:
                delta = 0
                ans += 1
                break
            i += 1
            if j < m - 1:
                j += 1
        if delta != 0:
            return -1
        else:
            return ans


def main():
    nums1 = [1, 2, 3, 4, 5, 6]
    nums2 = [1, 1, 2, 2, 2, 2]
    sol = Solution()
    print(sol.minOperations(nums1, nums2))


main()
