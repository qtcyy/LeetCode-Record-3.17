/*
 * @lc app=leetcode.cn id=2772 lang=cpp
 *
 * [2772] 使数组中的所有元素都等于零
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool checkArray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> diff(n + 1);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += diff[i];
      int x = sum + nums[i];
      if (x == 0)
        continue;
      if (x < 0 || i + k > n)
        return false;
      sum -= x;
      diff[i + k] += x;
    }
    return true;
  }
};
// @lc code=end
