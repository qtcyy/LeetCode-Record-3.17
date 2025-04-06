from typing import List


class Solution:
    def maxFreeTime(
        self, eventTime: int, startTime: List[int], endTime: List[int]
    ) -> int:
        n = len(startTime)
        lRoom, rRoom = [0] * n, [0] * n
        lRoom[0] = startTime[0]
        for i in range(1, n):
            lRoom[i] = max(lRoom[i - 1], startTime[i] - endTime[i - 1])
        rRoom[n - 1] = eventTime - endTime[n - 1]
        for i in range(n - 2, -1, -1):
            rRoom[i] = max(rRoom[i + 1], startTime[i + 1] - endTime[i])
        ans = 0
        for i in range(n):
            ltime = 0 if i == 0 else endTime[i - 1]
            rtime = eventTime if i == n - 1 else startTime[i + 1]
            room_len = endTime[i] - startTime[i]
            ans = max(ans, rtime - ltime - room_len)
            if i > 0 and lRoom[i - 1] >= room_len:
                ans = max(ans, rtime - ltime)
            if i < n - 1 and rRoom[i + 1] >= room_len:
                ans = max(ans, rtime - ltime)
        return ans


def main():
    eventTime = 10
    startTime = [0, 3, 7, 9]
    endTime = [1, 4, 8, 10]
    sol = Solution()
    print(sol.maxFreeTime(eventTime, startTime, endTime))


main()
