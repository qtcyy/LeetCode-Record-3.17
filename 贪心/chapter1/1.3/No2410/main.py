from typing import List


class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        n, m = len(players), len(trainers)
        ans = 0
        i, j = 0, 0
        while i < n and j < m:
            if trainers[j] >= players[i]:
                ans += 1
                i += 1
                j += 1
            else:
                j += 1
        return ans


def main():
    players = [4, 7, 9]
    trainers = [8, 2, 5, 8]
    sol = Solution()
    print(sol.matchPlayersAndTrainers(players, trainers))


main()
