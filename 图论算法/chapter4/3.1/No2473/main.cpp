#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<long long> minCost(int n, vector<vector<int>> &roads,
                            vector<int> &appleCost, int k) {
    vector<vector<pair<int, int>>> g(n + 1);
    for (auto &p : roads) {
      g[p[0]].emplace_back(p[1], p[2]);
      g[p[1]].emplace_back(p[0], p[2]);
    }
    auto solve = [&](int s) -> long long {
      vector<long long> dis(n + 1, LLONG_MAX);
      priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                     greater<>>
          q;
      dis[s] = 0;
      q.emplace(0, s);
      while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        if (w > dis[u]) {
          continue;
        }
        for (auto &&[v, s] : g[u]) {
          if (dis[v] > dis[u] + s) {
            dis[v] = dis[u] + s;
            q.emplace(dis[v], v);
          }
        }
      }
      long long res = LLONG_MAX;
      for (int i = 1; i <= n; i++) {
        if (dis[i] >= INT_MAX) {
          continue;
        }
        res = min(res, dis[i] + dis[i] * k + appleCost[i - 1]);
      }
      return res;
    };
    vector<long long> ans(n);
    for (int i = 1; i <= n; i++) {
      ans[i - 1] = solve(i);
    }
    return ans;
  }
};

signed main() {
  int n = 4;
  vector<vector<int>> roads = {
      {1, 2, 4}, {2, 3, 2}, {2, 4, 5}, {3, 4, 1}, {1, 3, 4}};
  vector<int> appleCost = {56, 42, 102, 301};
  int k = 2;
  Solution sol;
  auto ans = sol.minCost(n, roads, appleCost, k);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}