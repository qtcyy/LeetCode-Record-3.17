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
  int electricCarPlan(vector<vector<int>> &paths, int cnt, int start, int end,
                      vector<int> &charge) {
    using TPL = tuple<int, int, int>;
    int n = charge.size();
    vector<vector<pair<int, int>>> g(n);
    for (auto &p : paths) {
      g[p[0]].emplace_back(p[1], p[2]);
      g[p[1]].emplace_back(p[0], p[2]);
    }
    priority_queue<TPL, vector<TPL>, greater<>> q; // {w,u,power}
    vector<vector<int>> dis(n, vector<int>(cnt + 1, INT_MAX));
    dis[start][0] = 0;
    q.emplace(0, start, 0);
    while (!q.empty()) {
      auto [w, u, power] = q.top();
      q.pop();
      if (w > dis[u][power]) {
        continue;
      }
      // 充电
      if (power < cnt) {
        if (w + charge[u] < dis[u][power + 1]) {
          dis[u][power + 1] = w + charge[u];
          q.emplace(w + charge[u], u, power + 1);
        }
      }
      // 不充电
      for (auto &&[v, s] : g[u]) {
        int rest = power - s;
        int newCost = w + s;
        if (rest >= 0 && newCost < dis[v][rest]) {
          dis[v][rest] = newCost;
          q.emplace(newCost, v, rest);
        }
      }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= cnt; i++) {
      ans = min(ans, dis[end][i]);
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> paths = {
      {1, 3, 3}, {3, 2, 1}, {2, 1, 3}, {0, 1, 4}, {3, 0, 5}};
  int cnt = 6, start = 1, end = 0;
  vector<int> charge = {2, 10, 4, 1};
  Solution sol;
  cout << sol.electricCarPlan(paths, cnt, start, end, charge) << endl;

  return 0;
}