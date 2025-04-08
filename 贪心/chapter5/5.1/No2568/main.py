from typing import List


class Solution:
    def minImpossibleOR(self, nums: List[int]) -> int:
        cnt = [False] * 32
        if 1 not in nums:
            return 1

        def divide(x: int):
            pos = 0
            while x:
                if x & 1:
                    cnt[pos] = True
                pos += 1
                x >>= 1

        for x in nums:
            divide(x)

        pos = 0
        for i in range(32):
            if not cnt[i]:
                pos = i
                break
        return 2**pos


class Solution2:
    def minImpossibleOR(self, nums: List[int]) -> int:
        st = set(nums)
        for i in range(32):
            val = 2**i
            if val not in st:
                return val
        return 1


def main():
    sol = Solution2()
    nums = [2, 1]
    print(sol.minImpossibleOR(nums))


main()
