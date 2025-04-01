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
  int shortestPathWithHops(int n, vector<vector<int>> &edges, int s, int d,
                           int k) {
    vector<vector<pair<int, int>>> g(n);
    for (auto &p : edges) {
      g[p[0]].emplace_back(p[1], p[2]);
      g[p[1]].emplace_back(p[0], p[2]);
    }
    vector<vector<int>> dis(n, vector<int>(k + 1, INT_MAX));
    priority_queue<TPL, vector<TPL>, greater<>> q; //{w,u,cnt}
    dis[s][0] = 0;
    q.emplace(s, 0, 0);
    while (!q.empty()) {
      auto [w, u, cnt] = q.top();
      q.pop();
      if (w > dis[u][cnt]) {
        continue;
      }
      if (cnt < k && dis[u][cnt + 1] > w) {
        dis[u][cnt + 1] = w;
        q.emplace(w, u, cnt + 1);
      }
      for (auto &&[v, s] : g[u]) {
        if (dis[v][cnt] > w + s) {
          dis[v][cnt] = w + s;
          q.emplace(w + s, v, cnt);
        }
        if (cnt < k && dis[v][cnt + 1] > w) {
          dis[v][cnt + 1] = w;
          q.emplace(w, v, cnt + 1);
        }
      }
    }
    return dis[d][k];
  }
};

signed main() {
  int n = 7;
  vector<vector<int>> edges = {{3, 1, 9}, {3, 2, 4}, {4, 0, 9}, {0, 5, 6},
                               {3, 6, 2}, {6, 0, 4}, {1, 2, 4}};
  int s = 4, d = 1, k = 2;
  Solution sol;
  cout << sol.shortestPathWithHops(n, edges, s, d, k) << endl;

  return 0;
}