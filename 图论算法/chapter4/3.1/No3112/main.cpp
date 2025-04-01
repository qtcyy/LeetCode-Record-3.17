#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> minimumTime(int n, vector<vector<int>> &edges,
                          vector<int> &disappear) {
    vector<vector<pair<int, int>>> g(n);
    for (auto &p : edges) {
      g[p[0]].emplace_back(p[1], p[2]);
      g[p[1]].emplace_back(p[0], p[2]);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    vector<int> dis(n, -1);
    dis[0] = 0;
    q.emplace(0, 0);
    vector<bool> vis(n, false);
    while (!q.empty()) {
      int u = q.top().second;
      q.pop();
      if (vis[u])
        continue;
      vis[u] = 1;
      for (auto &&[v, s] : g[u]) {
        if (vis[v])
          continue;
        int len = dis[u] + s;
        if (disappear[v] > len && (dis[v] == -1 || len < dis[v])) {
          dis[v] = len;
          q.emplace(len, v);
        }
      }
    }
    return dis;
  }
};

signed main() {
  int n = 3;
  vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 1}, {0, 2, 4}};
  vector<int> disappear = {1, 1, 5};
  Solution sol;
  auto ans = sol.minimumTime(n, edges, disappear);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}