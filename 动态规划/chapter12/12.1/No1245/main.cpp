#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int treeDiameter(vector<vector<int>> &edges) {
    int n = edges.size(), ans = 0;
    vector<vector<int>> g(n + 1);
    for (auto &p : edges) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }
    function<int(int, int)> dfs = [&](int u, int fa) {
      int mx = 0;
      for (int &v : g[u]) {
        if (v == fa)
          continue;
        int len = dfs(v, u) + 1;
        ans = max(ans, mx + len);
        mx = max(mx, len);
      }
      return mx;
    };
    dfs(0, -1);
    return ans;
  }
};

signed main() {
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 4}, {4, 5}};
  Solution sol;
  cout << sol.treeDiameter(edges) << endl;

  return 0;
}