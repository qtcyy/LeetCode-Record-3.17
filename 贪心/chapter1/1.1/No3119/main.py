class Solution:
    def maxPotholes(self, road: str, budget: int) -> int:
        segments = road.split(".")
        cnt = []
        for seg in segments:
            val = seg.count("x")
            if val > 0:
                cnt.append(val)
        cnt.sort(reverse=True)
        print(cnt)
        ans = 0
        for x in cnt:
            if x + 1 > budget:
                ans += budget - 1
                budget = 0
                break
            else:
                ans += x
                budget -= x + 1

            if budget < 0:
                break

        return ans


def main():
    road = "x.x.xxx...x"
    budget = 14
    sol = Solution()
    print(sol.maxPotholes(road, budget))


main()
