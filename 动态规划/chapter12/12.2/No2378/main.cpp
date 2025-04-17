#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxScore(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<vector<int>> g(n);
    vector<int> point(n);
    for (int i = 1; i < n; i++) {
      g[edges[i][0]].push_back(i);
      point[i] = edges[i][1];
    }

    vector<vector<int>> f(n, vector<int>(2));
    function<void(int)> dfs = [&](int u) {
      // mx1 不连 mx2 连
      int mx1 = 0, mx2 = 0;
      for (auto &v : g[u]) {
        dfs(v);
        mx1 = max(mx1, max(f[v][0], f[v][1]));
        mx2 = max(mx2, f[v][0] + point[v]);
      }
      cout << u << ' ' << mx1 << ' ' << mx2 << endl;
      f[u][0] = mx1;
      f[u][1] = mx2;
    };
    dfs(0);
    return ranges::max(f[0]);
  }
};

signed main() {
  vector<vector<int>> edges = {{-1, -1}, {0, 5}, {0, 10}, {2, 6}, {2, 4}};
  Solution sol;
  cout << sol.maxScore(edges) << endl;

  return 0;
}