/*
 * @lc app=leetcode.cn id=2270 lang=cpp
 *
 * [2270] 分割数组的方案数
 */
#include <vector>
using namespace std;
// @lc code=start
typedef long long ll;
class Solution {
public:
  int waysToSplitArray(vector<int> &nums) {
    int n = nums.size();
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
      pre[i + 1] = pre[i] + nums[i];
    ll tot = pre.back(), ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (pre[i + 1] >= tot - pre[i + 1])
        ++ans;
    }
    return ans;
  }
};
// @lc code=end
