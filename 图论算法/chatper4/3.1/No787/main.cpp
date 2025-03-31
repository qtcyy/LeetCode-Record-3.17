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
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    using TPL = tuple<int, int, int>;
    vector<vector<pair<int, int>>> g(n);
    for (auto &p : flights) {
      g[p[0]].emplace_back(p[1], p[2]);
      //   g[p[1]].emplace_back(p[0], p[2]);
    }
    priority_queue<TPL, vector<TPL>, greater<>> q; // {w,u,time}
    vector<vector<int>> dis(n, vector<int>(k + 2, INT_MAX));
    dis[src][0] = 0;
    q.emplace(0, src, 0);
    k++;
    while (!q.empty()) {
      auto [w, u, time] = q.top();
      q.pop();
      if (w > dis[u][time]) {
        continue;
      }
      for (auto &&[v, s] : g[u]) {
        int newTime = time + 1;
        int newLen = w + s;
        if (newTime <= k && newLen < dis[v][newTime]) {
          dis[v][newTime] = newLen;
          q.emplace(newLen, v, newTime);
        }
      }
    }
    int ans = INT_MAX;
    for (int time = 0; time <= k; time++) {
      ans = min(ans, dis[dst][time]);
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

signed main() {
  int n = 4;
  vector<vector<int>> flights = {
      {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
  int src = 0, dst = 3, k = 1;
  Solution sol;
  cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;

  return 0;
}