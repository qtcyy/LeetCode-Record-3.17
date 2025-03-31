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
  int minCost(int maxTime, vector<vector<int>> &edges,
              vector<int> &passingFees) {
    using TPL = tuple<int, int, int>;
    int n = passingFees.size();
    vector<vector<pair<int, int>>> g(n);
    for (auto &p : edges) {
      g[p[0]].emplace_back(p[1], p[2]);
      g[p[1]].emplace_back(p[0], p[1]);
    }
    vector<vector<int>> dis(n, vector<int>(maxTime + 1, INT_MAX));
    priority_queue<TPL, vector<TPL>, greater<>> q;
    dis[0][0] = passingFees[0];
    q.emplace(passingFees[0], 0, 0); // {w,u,time}
    while (!q.empty()) {
      auto [w, u, time] = q.top();
      q.pop();
      if (w > dis[u][time]) {
        continue;
      }
      for (auto &&[v, s] : g[u]) {
        int newTime = time + s;
        int newFee = w + passingFees[v];
        if (newTime <= maxTime && dis[v][newTime] > newFee) {
          dis[v][newTime] = newFee;
          q.emplace(newFee, v, newTime);
        }
      }
    }
    int ans = INT_MAX;
    for (int time = 0; time <= maxTime; time++) {
      ans = min(ans, dis[n - 1][time]);
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

signed main() {
  int maxTime = 30;
  vector<vector<int>> edges = {{0, 1, 10}, {1, 2, 10}, {2, 5, 10},
                               {0, 3, 1},  {3, 4, 10}, {4, 5, 15}};
  vector<int> passingFees = {5, 1, 2, 20, 20, 3};
  Solution sol;
  cout << sol.minCost(maxTime, edges, passingFees) << endl;
}