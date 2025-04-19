/*
 * @lc app=leetcode.cn id=3229 lang=cpp
 *
 * [3229] 使数组等于目标数组所需的最少操作次数
 */
#include <vector>
using namespace std;
// @lc code=start
typedef long long ll;
class Solution {
public:
  long long minimumOperations(vector<int> &nums, vector<int> &target) {
    int n = nums.size();
    vector<ll> arr(n), diff(n + 1);
    for (int i = 0; i < n; i++)
      arr[i] = target[i] - nums[i];
    diff[0] = arr[0];
    for (int i = 1; i < n; i++)
      diff[i] = arr[i] - arr[i - 1];
    diff.back() = -arr.back();
    ll a = 0, b = 0;
    for (auto &x : diff) {
      if (x > 0)
        a += x;
      else if (x < 0)
        b -= x;
    }
    return max(a, b);
  }
};
// @lc code=end
