#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, long long>>> g(n);
    for (auto &p : roads) {
      g[p[0]].emplace_back(p[1], p[2]);
      g[p[1]].emplace_back(p[0], p[2]);
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<>>
        q;
    vector<bool> vis(n);
    vector<long long> cnt(n);
    vector<long long> dis(n, LLONG_MAX);
    dis[0] = 0;
    cnt[0] = 1;
    q.emplace(0, 0);
    while (!q.empty()) {
      int u = q.top().second;
      q.pop();
      if (vis[u])
        continue;
      vis[u] = 1;
      for (auto &&[v, s] : g[u]) {
        long long len = s + dis[u];
        if (dis[v] > len) {
          cnt[v] = cnt[u];
          dis[v] = len;
          q.emplace(len, v);
        } else if (dis[v] == len) {
          cnt[v] = (cnt[v] + cnt[u]) % mod;
        }
      }
    }
    return cnt[n - 1];
  }
};

signed main() {
  int n = 7;
  vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3},
                               {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1},
                               {0, 4, 5}, {4, 6, 2}};
  Solution sol;
  cout << sol.countPaths(n, roads) << endl;
}