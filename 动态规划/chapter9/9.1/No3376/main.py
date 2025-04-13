from typing import List


class Std:
    def findMinimumTime(self, strength: List[int], k: int) -> int:
        n = len(strength)
        f = [0] * (1 << n)
        for i in range(1, 1 << n):
            x = 1 + k * (n - i.bit_count())
            f[i] = (
                min(
                    f[i ^ (1 << j)] + (s - 1) // x
                    for j, s in enumerate(strength)
                    if i >> j & 1
                )
                + 1
            )
        return f[-1]


class Solution:
    def findMinimumTime(self, strength: List[int], k: int) -> int:
        n = len(strength)
        f = [0] * (1 << n)
        for s in range(1, 1 << n):
            i = s.bit_count()
            x = 1 + k * (n - i)
            f[s] = (
                min(
                    f[s ^ (1 << j)] + (st - 1) // x
                    for j, st in enumerate(strength)
                    if s >> j & 1
                )
                + 1
            )

        print(f)
        return f[-1]


def main():
    strength = [2, 5, 4]
    K = 2
    sol = Solution()
    print(sol.findMinimumTime(strength, K))


main()
