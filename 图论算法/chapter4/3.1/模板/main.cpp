#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Graph {
private:
  vector<vector<pair<int, int>>> g;

public:
  void dijkstra(int n, int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    vector<int> dis(n, INT_MAX);
    vector<bool> vis(n, false);
    q.emplace(0, s);
    dis[s] = 0;
    while (!q.empty()) {
      int u = q.top().second;
      q.pop();
      if (vis[u]) {
        continue;
      }
      vis[u] = 1;
      for (auto &&[v, s] : g[u]) {
        if (dis[v] > dis[u] + s) {
          dis[v] = dis[u] + s;
          q.emplace(dis[v], v);
        }
      }
    }
  }

  void solution2(int n, int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    vector<int> dis(n, INT_MAX);
    vector<bool> vis(n, false);
    q.emplace(0, s);
    dis[s] = 0;
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
  }
};