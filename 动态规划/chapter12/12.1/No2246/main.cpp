#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int longestPath(vector<int> &parent, string s) {
    int n = parent.size(), ans = 0;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      g[parent[i]].push_back(i);
    }
    function<int(int, int)> dfs = [&](int u, int fa) -> int {
      int mx = 0;
      for (auto &v : g[u]) {
        if (v == fa)
          continue;
        int val = dfs(v, u) + 1;
        if (s[u] != s[v]) {
          ans = max(ans, val + mx);
          mx = max(mx, val);
        }
      }
      return mx;
    };
    dfs(0, -1);
    return ans + 1;
  }
};

signed main() {
  vector<int> parent = {-1, 0, 0, 1, 1, 2};
  string s = "abacbe";
  Solution sol;
  cout << sol.longestPath(parent, s) << endl;

  return 0;
}