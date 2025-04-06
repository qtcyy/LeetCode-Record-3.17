#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int findShortestCycle(int n, vector<vector<int>> &edges) {
    vector<vector<int>> g(n);
    for (auto &p : edges) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }
    int dis[n];
    auto bfs = [&](int s) {
      queue<pair<int, int>> q;
      q.emplace(s, -1);
      dis[s] = 0;
      int ans = INT_MAX;
      while (!q.empty()) {
        auto [u, fa] = q.front();
        q.pop();
        for (auto &v : g[u]) {
          if (dis[v] < 0) {
            dis[v] = dis[u] + 1;
            q.emplace(v, u);
          } else if (v != fa) {
            ans = min(ans, dis[u] + dis[v] + 1);
          }
        }
      }
      return ans;
    };
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      memset(dis, -1, sizeof(dis));
      ans = min(ans, bfs(i));
    }
    return ans < INT_MAX ? ans : -1;
  }
};

signed main() {
  int n = 7;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4},
                               {4, 5}, {5, 6}, {6, 3}};
  Solution sol;
  cout << sol.findShortestCycle(n, edges) << endl;
  return 0;
}