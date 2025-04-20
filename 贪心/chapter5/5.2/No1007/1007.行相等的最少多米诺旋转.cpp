/*
 * @lc app=leetcode.cn id=1007 lang=cpp
 *
 * [1007] 行相等的最少多米诺旋转
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
    int n = tops.size();
    auto solve = [&](int d) -> int {
      // 上
      int sum1 = 0, sum2 = 0;
      for (int i = 0; i < n; i++) {
        if (tops[i] != d) {
          if (bottoms[i] == d)
            ++sum1;
          else
            return -1;
        }
      }
      // 下
      for (int i = 0; i < n; i++) {
        if (bottoms[i] != d) {
          if (tops[i] == d) {
            ++sum2;
          }
        }
      }
      return min(sum1, sum2);
    };

    int ans = -1;
    for (int d = 1; d <= 6; d++) {
      ans = max(ans, solve(d));
    }
    return ans;
  }
};
// @lc code=end
