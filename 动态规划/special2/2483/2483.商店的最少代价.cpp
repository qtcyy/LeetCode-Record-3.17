/*
 * @lc app=leetcode.cn id=2483 lang=cpp
 *
 * [2483] 商店的最少代价
 */
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int bestClosingTime(string customers) {
    int n = customers.size();
    vector<int> pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) {
      if (customers[i] == 'N')
        pre[i + 1] = pre[i] + 1;
      else
        pre[i + 1] = pre[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      if (customers[i] == 'Y')
        suf[i] = suf[i + 1] + 1;
      else
        suf[i] = suf[i + 1];
    }
    int mn = INT_MAX, ans = 0;
    for (int i = 0; i <= n; i++) {
      int val = pre[i] + suf[i];
      if (mn > val) {
        mn = val;
        ans = i;
      }
    }
    return ans;
  }
};
// @lc code=end
