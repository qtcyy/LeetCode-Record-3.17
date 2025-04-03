from typing import List


class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        seats.sort()
        students.sort()
        ans = 0
        for i, x in enumerate(students):
            ans += abs(x - seats[i])
        return ans


def main():
    seats = [4, 1, 5, 9]
    students = [1, 3, 2, 6]
    sol = Solution()
    print(sol.minMovesToSeat(seats, students))


main()
