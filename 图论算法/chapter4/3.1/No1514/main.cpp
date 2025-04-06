#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start_node,
                        int end_node) {
    vector<vector<pair<int, double>>> g(n);
    int m = edges.size();
    for (int i = 0; i < m; i++) {
      g[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
      g[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
    }
    priority_queue<pair<double, int>> q;
    q.emplace(0, start_node);
    vector<double> dis(n);
    dis[start_node] = 1;
    vector<bool> vis(n, false);
    while (!q.empty()) {
      int u = q.top().second;
      q.pop();
      if (vis[u])
        continue;
      vis[u] = 1;
      for (auto &&[v, s] : g[u]) {
        double len = dis[u] * s;
        if (len > dis[v]) {
          dis[v] = len;
          q.emplace(len, v);
        }
      }
    }
    return dis[end_node];
  }
};

signed main() {
  int n = 3;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
  vector<double> succProb = {0.5, 0.5, 0.2};
  int start = 0, end = 2;
  Solution sol;
  cout << sol.maxProbability(n, edges, succProb, start, end) << endl;

  return 0;
}