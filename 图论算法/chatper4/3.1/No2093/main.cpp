#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using TPL = tuple<int, int, int>;

class Solution {
public:
  int minimumCost(int n, vector<vector<int>> &highways, int discounts) {
    vector<vector<pair<int, int>>> g(n);
    for (auto &p : highways) {
      g[p[0]].emplace_back(p[1], p[2]);
      g[p[1]].emplace_back(p[0], p[2]);
    }
    priority_queue<TPL, vector<TPL>, greater<TPL>> q; // {w,u,remain}
    q.emplace(0, 0, 0);
    vector<bool> vis(n, false);
    vector<vector<int>> dis(n, vector<int>(discounts + 1, INT_MAX));
    dis[0][0] = 0;
    while (!q.empty()) {
      auto [w, u, remain] = q.top();
      q.pop();
      if (vis[u])
        continue;
      if (remain < discounts && dis[u][remain + 1] > w) {
        dis[u][remain + 1] = w;
        q.emplace(w, u, remain + 1);
      }
      vis[u] = 1;
      for (auto &&[v, s] : g[u]) {
        if (vis[v])
          continue;
        if (dis[v][remain] > dis[u][remain] + s) {
          dis[v][remain] = dis[u][remain] + s;
          q.emplace(dis[v][remain], v, remain);
        }
        if (remain < discounts && dis[v][remain + 1] > dis[u][remain] + s / 2) {
          dis[v][remain + 1] = dis[u][remain] + s / 2;
          q.emplace(dis[u][remain + 1] + s / 2, v, remain + 1);
        }
      }
    }
    return dis[n - 1][discounts] == INT_MAX ? -1 : dis[n - 1][discounts];
  }
};

signed main() {
  int n = 5;
  vector<vector<int>> highways = {
      {0, 1, 4}, {2, 1, 3}, {1, 4, 11}, {3, 2, 3}, {3, 4, 2}};
  int discounts = 1;
  Solution sol;
  cout << sol.minimumCost(n, highways, discounts) << endl;

  return 0;
}