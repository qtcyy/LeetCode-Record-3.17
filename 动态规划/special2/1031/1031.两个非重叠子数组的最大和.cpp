/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    int n = nums.size();
    vector<int> preSum(n + 1);
    vector<int> preMax1(n + 1), preMax2(n + 1), sufMax1(n + 1), sufMax2(n + 1);
    for (int i = 0; i < n; i++) {
      preSum[i + 1] = preSum[i] + nums[i];
    }
    for (int i = 0; i <= n; i++) {
      if (i >= firstLen) {
        preMax1[i] = max(preMax1[i - 1], preSum[i] - preSum[i - firstLen]);
      }
      if (i >= secondLen) {
        preMax2[i] = max(preMax2[i - 1], preSum[i] - preSum[i - secondLen]);
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (n - i >= firstLen) {
        sufMax1[i] = max(sufMax1[i + 1], preSum[i + firstLen] - preSum[i]);
      }
      if (n - i >= secondLen) {
        sufMax2[i] = max(sufMax2[i + 1], preSum[i + secondLen] - preSum[i]);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (i >= firstLen && n - i >= secondLen) {
        ans = max(ans, preMax1[i] + sufMax2[i]);
      }
      if (i >= secondLen && n - i >= firstLen) {
        ans = max(ans, preMax2[i] + sufMax1[i]);
      }
    }
    return ans;
  }
};
// @lc code=end
