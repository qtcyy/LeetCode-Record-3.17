#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string shortestSuperstring(vector<string> &words) {
    int n = words.size();
    vector<vector<int>> f(n, vector<int>(1 << n, INT_MAX / 2));
    vector<vector<int>> st(n, vector<int>(n));
    // pre
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        int len1 = words[i].length(), len2 = words[j].length();
        for (int p = min(len1, len2); p >= 1; p--) {
          string s1 = words[i].substr(len1 - p);
          string s2 = words[j].substr(0, p);
          if (s1 == s2) {
            st[i][j] = len2 - p;
            break;
          }
        }
      }
    for (int i = 0; i < n; i++)
      f[i][1 << i] = words[i].length();
    for (int s = 1; s < 1 << n; s++) {
      for (int i = 0; i < n; i++) {
        if (!(s >> i & 1))
          continue;
        int sub = s ^ (1 << i);
        for (int j = 0; j < n; j++) {
          if (j != i && sub >> j & 1) {
            if (f[j][sub] != INT_MAX / 2)
              f[i][s] = min(f[i][s], f[j][sub] + st[j][i]);
          }
        }
      }
    }
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
      res = min(res, f[i].back());
    cout << res << endl;
    return "";
  }
};

signed main() {
  vector<string> words = {"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
  Solution sol;
  cout << sol.shortestSuperstring(words) << endl;

  return 0;
}