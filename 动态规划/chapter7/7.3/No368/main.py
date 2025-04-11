from typing import List


class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        from_ = [-1] * n
        f = [0] * n
        end_i = 0
        for i, x in enumerate(nums):
            for j in range(i):
                if x % nums[i] == 0 and f[j] > f[i]:
                    f[i] = f[j]
                    from_[i] = j
            f[i] += 1
            if f[i] > f[end_i]:
                end_i = i

        res = []
        i = end_i
        while i >= 0:
            res.append(nums[i])
            i = from_[i]
        return res


def main():
    nums = [1, 2, 4, 8]
    sol = Solution()
    print(sol.largestDivisibleSubset(nums))


main()
