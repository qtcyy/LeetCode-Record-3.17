#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {
    int n = routes.size();
    unordered_map<int, vector<int>> g;
    for (int i = 0; i < n; i++) {
      for (auto &x : routes[i]) {
        g[x].push_back(i);
      }
    }
    if (!g.contains(source) || !g.contains(target)) {
      return source == target ? 0 : -1;
    }
    unordered_map<int, int> dis;
    queue<int> q;
    q.push(source);
    dis[source] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      int dist = dis[u];
      for (auto &i : g[u]) {
        for (auto &v : routes[i]) {
          if (!dis.contains(v)) {
            dis[v] = dist + 1;
            q.push(v);
          }
        }
        routes[i].clear();
      }
    }
    return dis.contains(target) ? dis[target] : -1;
  }
};

signed main() {
  vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
  int source = 1, target = 6;
  Solution sol;
  cout << sol.numBusesToDestination(routes, source, target) << endl;

  return 0;
}