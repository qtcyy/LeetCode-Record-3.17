#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumRemovals(string s, string p, vector<int> &removable) {
    int n = s.length(), m = p.length();
    auto check = [&](const int &mid) -> bool {
      vector<bool> vis(n, false);
      for (int i = 0; i < mid; i++)
        vis[removable[i]] = 1;
      int i = 0, j = 0;
      while (i < n && j < m) {
        if (vis[i]) {
          ++i;
          continue;
        }
        if (s[i] == p[j]) {
          ++j;
        }
        ++i;
      }
      return j == m;
    };
    int l = -1, r = removable.size() + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

signed main() {
  string s = "abcacb", p = "ab";
  vector<int> removable = {3, 1, 0};
  Solution sol;
  cout << sol.maximumRemovals(s, p, removable) << endl;

  return 0;
}