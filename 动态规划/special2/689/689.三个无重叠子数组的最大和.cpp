/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
    vector<vector<int>> f(n + 10, vector<int>(4));
    for (int i = n - k + 1; i >= 1; i--)
      for (int j = 1; j < 4; j++) {
        f[i][j] =
            max(f[i + 1][j], f[i + k][j - 1] + pre[i + k - 1] - pre[i - 1]);
      }
    vector<int> ans(3);
    int idx = 0, i = 1, j = 3;
    while (j) {
      if (f[i + 1][j] > f[i + k][j - 1] + pre[i + k - 1] - pre[i - 1]) {
        ++i;
      } else {
        ans[idx++] = i - 1;
        i += k;
        --j;
      }
    }
    return ans;
  }
};
// @lc code=end
