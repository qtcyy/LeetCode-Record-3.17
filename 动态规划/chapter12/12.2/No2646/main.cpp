#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price,
                        vector<vector<int>> &trips) {
    vector<vector<int>> g(n);
    vector<int> cnt(n);
    for (auto &p : edges) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }

    for (auto &t : trips) {
      int end = t[1];
      function<bool(int, int)> dfs = [&](int u, int fa) {
        if (u == end) {
          ++cnt[u];
          return true;
        }
        for (auto &v : g[u]) {
          if (v != fa && dfs(v, u)) {
            ++cnt[u];
            return true;
          }
        }
        return false;
      };
      dfs(t[0], -1);
    }
    vector<vector<int>> f(n, vector<int>(2));

    function<void(int, int)> dfs = [&](int u, int fa) {
      f[u][0] = price[u] * cnt[u];
      f[u][1] = f[u][0] / 2;
      for (auto &v : g[u]) {
        if (v == fa)
          continue;
        dfs(v, u);
        f[u][0] += min(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
      }
    };
    dfs(0, -1);
    return ranges::min(f[0]);
  }
};

signed main() {
  int n = 4;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}},
                      trips = {{0, 3}, {2, 1}, {2, 3}};
  ;
  vector<int> price = {2, 2, 10, 6};
  Solution sol;
  cout << sol.minimumTotalPrice(n, edges, price, trips) << endl;

  return 0;
}