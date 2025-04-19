/*
 * @lc app=leetcode.cn id=2012 lang=cpp
 *
 * [2012] 数组美丽值求和
 */
#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int sumOfBeauties(vector<int> &nums) {
    int n = nums.size();
    vector<int> preMax(n + 1), sufMin(n + 1, INT_MAX);
    for (int i = 0; i < n; i++)
      preMax[i + 1] = max(preMax[i], nums[i]);
    for (int i = n - 1; i >= 0; i--)
      sufMin[i] = min(sufMin[i + 1], nums[i]);
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      if (preMax[i] < nums[i] && nums[i] < sufMin[i + 1]) {
        ans += 2;
      } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
        ++ans;
    }
    return ans;
  }
};
// @lc code=end
