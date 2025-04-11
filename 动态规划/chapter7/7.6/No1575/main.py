from typing import List


class Solution:
    def countRoutes(
        self, locations: List[int], start: int, finish: int, fuel: int
    ) -> int:
        MOD = 10**9 + 7
        n = len(locations)
        f = [[0] * (n) for _ in range(fuel + 1)]
        f[0][start] = 1
        for ff in range(1, fuel + 1):
            for i in range(n):
                for j in range(n):
                    if i == j:
                        continue
                    dist = abs(locations[i] - locations[j])
                    if ff >= dist:
                        f[ff][i] = (f[ff][i] + f[ff - dist][j]) % MOD
        return sum(f[ff][finish] for ff in range(0, fuel + 1)) % MOD


def main():
    locations = [2, 3, 6, 8, 4]
    start = 1
    finish = 3
    fuel = 5
    sol = Solution()
    print(sol.countRoutes(locations, start, finish, fuel))


main()
