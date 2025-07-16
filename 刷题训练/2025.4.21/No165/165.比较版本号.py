#
# @lc app=leetcode.cn id=165 lang=python3
#
# [165] 比较版本号
#


# @lc code=start
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = list(version1.split("."))
        v2 = list(version2.split("."))
        n, m = len(v1), len(v2)
        if n < m:
            for i in range(n):
                if int(v1[i]) == int(v2[i]):
                    continue
                if int(v1[i]) < int(v2[i]):
                    return -1
                else:
                    return 1
            for i in range(n, m):
                if int(v2[i]) != 0:
                    return -1
            return 0
        elif n > m:
            for i in range(m):
                if int(v1[i]) == int(v2[i]):
                    continue
                if int(v1[i]) < int(v2[i]):
                    return -1
                else:
                    return 1
            for i in range(m, n):
                if int(v1[i]) != 0:
                    return 1
            return 0
        else:
            for i in range(n):
                if int(v1[i]) == int(v2[i]):
                    continue
                if int(v1[i]) < int(v2[i]):
                    return -1
                else:
                    return 1
            return 0


# @lc code=end
