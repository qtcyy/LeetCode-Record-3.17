/*
 * @lc app=leetcode.cn id=2256 lang=cpp
 *
 * [2256] 最小平均差
 */
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
typedef long long ll;
class Solution {
public:
  int minimumAverageDifference(vector<int> &nums) {
    int n = nums.size();
    vector<ll> pre(n + 1, 0), suf(n + 1, 0);
    for (int i = 0; i < n; i++)
      pre[i + 1] = pre[i] + nums[i];
    for (int i = n - 1; i >= 0; i--)
      suf[i] = suf[i + 1] + nums[i];
    ll mn = LLONG_MAX;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ll x = pre[i + 1] / (i + 1),
         y = i == n - 1 ? 0 : suf[i + 1] / (n - i - 1);
      if (abs(x - y) < mn) {
        mn = abs(x - y);
        ans = i;
      }
    }
    return ans;
  }
};
// @lc code=end
