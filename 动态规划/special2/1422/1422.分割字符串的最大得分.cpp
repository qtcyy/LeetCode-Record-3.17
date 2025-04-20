/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxScore(string s) {
    int n = s.length();
    vector<int> pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        pre[i + 1] = pre[i] + 1;
      } else {
        pre[i + 1] = pre[i];
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '1') {
        suf[i] = suf[i + 1] + 1;
      } else {
        suf[i] = suf[i + 1];
      }
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      cout << pre[i + 1] << ' ' << suf[i + 1] << endl;
      ans = max(ans, pre[i + 1] + suf[i + 1]);
    }
    return ans;
  }
};
// @lc code=end
