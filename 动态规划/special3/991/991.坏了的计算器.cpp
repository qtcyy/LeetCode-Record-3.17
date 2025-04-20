/*
 * @lc app=leetcode.cn id=991 lang=cpp
 *
 * [991] 坏了的计算器
 */

// @lc code=start
class Solution {
public:
  int brokenCalc(int X, int Y) {
    int ans = 0;
    while (Y > X) {
      ans++;
      if (Y % 2 == 1)
        Y++;
      else
        Y /= 2;
    }

    return ans + X - Y;
  }
};
// @lc code=end
