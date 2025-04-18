/*
 * @lc app=leetcode.cn id=943 lang=cpp
 *
 * [943] 最短超级串
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  string shortestSuperstring(vector<string> &words) {
    int n = words.size();
    vector<vector<int>> rec(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        string s1 = words[i], s2 = words[j];
        // s1+s2
        int len1 = s1.length(), len2 = s2.length();
        int len = min(len1, len2);
        for (int k = len; k >= 1; k--) {
          if (s1.substr(len1 - k) == s2.substr(0, k)) {
            rec[i][j] = k;
            break;
          }
        }
      }
    vector<vector<int>> f(n, vector<int>(1 << n)), p(n, vector<int>(1 << n));
    for (int s = 0; s < 1 << n; s++) {
      for (int i = 0; i < n; i++) {
        if (!(s >> i & 1))
          continue;
        for (int j = 0; j < n; j++) {
          if (s >> j & 1)
            continue;
          int nxt = s | (1 << j);
          if (f[j][nxt] <= f[i][s] + rec[i][j]) {
            f[j][nxt] = f[i][s] + rec[i][j];
            p[j][nxt] = i;
          }
        }
      }
    }
    int mx = f[0].back(), idx = 0;
    for (int i = 1; i < n; i++) {
      if (mx < f[i].back()) {
        mx = f[i].back();
        idx = i;
      }
    }
    string ans = "";
    int last = -1, status = (1 << n) - 1;
    while (status) {
      if (last == -1)
        ans = words[idx];
      else
        ans = words[idx].substr(0, words[idx].length() - rec[idx][last]) + ans;
      last = idx;
      idx = p[idx][status];
      status ^= (1 << last);
    }
    return ans;
  }
};
// @lc code=end
