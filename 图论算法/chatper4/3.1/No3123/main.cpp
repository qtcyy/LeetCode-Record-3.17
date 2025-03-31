#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<bool> findAnswer(int n, vector<vector<int>> &edges) {
    vector<vector<tuple<int, int, int>>> g(n);
    for (int i = 0; i < edges.size(); i++) {
      vector<int> &p = edges[i];
      g[p[0]].emplace_back(p[1], p[2], i);
      g[p[1]].emplace_back(p[0], p[2], i);
    }
    vector<int> dis(n, INT_MAX);
    vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 0);
    dis[0] = 0;
    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      if (vis[u]) {
        continue;
      }
      vis[u] = 1;
      for (auto &&[v, s, _] : g[u]) {
        if (vis[v])
          continue;
        int len = s + dis[u];
        if (dis[v] > len) {
          dis[v] = len;
          pq.emplace(len, v);
        }
      }
    }
    vector<bool> ans(edges.size());
    if (dis[n - 1] == INT_MAX) {
      cout << "inf\n";
      return ans;
    }

    vis.clear();
    vis.resize(n);
    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      for (auto &&[v, s, i] : g[u]) {
        if (dis[v] + s != dis[u])
          continue;
        ans[i] = 1;
        if (!vis[v]) {
          dfs(v);
        }
      }
    };
    dfs(n - 1);

    return ans;
  }
};

signed main() {
  int n = 6;
  vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 1}, {1, 3, 2}, {1, 4, 3},
                               {1, 5, 1}, {2, 3, 1}, {3, 5, 3}, {4, 5, 2}};
  Solution sol;
  auto ans = sol.findAnswer(n, edges);
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}