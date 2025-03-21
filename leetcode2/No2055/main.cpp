#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
    int n = s.length();
    vector<int> pre_pos(n), suf_pos(n);
    int left = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '|') {
        left = i;
      }
      pre_pos[i] = left;
    }
    int right = n;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '|') {
        right = i;
      }
      suf_pos[i] = right;
    }
    vector<int> pre_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre_sum[i + 1] = pre_sum[i] + (s[i] == '*');
    }
    vector<int> res;
    for (auto &q : queries) {
      int l = suf_pos[q[0]], r = pre_pos[q[1]];
      if (l <= r) {
        res.push_back(pre_sum[r + 1] - pre_sum[l]);
      } else {
        res.push_back(0);
      }
    }
    return res;
  }
};

signed main() {
  string s = "**|**|***|";
  vector<vector<int>> queries = {{2, 5}, {5, 9}};
  Solution sol = Solution();
  vector<int> ans = sol.platesBetweenCandles(s, queries);
  for (auto &num : ans) {
    cout << num << ' ';
  }

  return 0;
}