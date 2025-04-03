from typing import List


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        n = len(people)
        people.sort()
        i, j = 0, n - 1
        ans = 0
        while i < j:
            if people[i] + people[j] > limit:
                ans += 1
                j -= 1
            else:
                ans += 1
                i += 1
                j -= 1
        if i == j:
            ans += 1
        return ans


def main():
    sol = Solution()
    people = [3, 2, 2, 1]
    limit = 3
    print(sol.numRescueBoats(people, limit))


if __name__ == "__main__":
    main()
