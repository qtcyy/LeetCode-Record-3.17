#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges) {
    vector<vector<int>> g(n + 1);
    for (auto &p : edges) {
      --p[0];
      --p[1];
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }
    vector<int> ans(n - 1);

    for (int s = 3; s < 1 << n; s++) {
      if ((s & (s - 1)) == 0)
        continue;
      int d = 0, vis = 0;
      function<int(int)> dfs = [&](int u) -> int {
        vis |= 1 << u;
        int mx = 0;
        for (int &v : g[u]) {
          if (!(vis >> v & 1) && s >> v & 1) {
            int len = dfs(v) + 1;
            d = max(d, mx + len);
            mx = max(mx, len);
          }
        }
        return mx;
      };
      dfs(__builtin_ctz(s));
      if (vis == s) {
        ++ans[d - 1];
      }
    }
    return ans;
  }
};

signed main() {
  int n = 4;
  vector<vector<int>> edges = {{1, 2}, {2, 3}, {2, 4}};
  Solution sol;
  auto ans = sol.countSubgraphsForEachDiameter(n, edges);
  for (auto &x : ans)
    cout << x << ' ';
  cout << endl;

  return 0;
}