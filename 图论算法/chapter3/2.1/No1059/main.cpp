#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  bool leadsToDestination(int n, vector<vector<int>> &edges, int source,
                          int destination) {
    vector<int> degree(n);
    vector<vector<int>> g(n);
    for (auto &p : edges) {
      g[p[1]].push_back(p[0]);
      ++degree[p[0]];
    }
    if (degree[destination] > 0)
      return false;
    if (degree[source] == 0) {
      return source == destination;
    }
    queue<int> q;
    q.push(destination);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &v : g[u]) {
        if (!--degree[v]) {
          q.push(v);
        }
      }
    }
    return degree[source] == 0;
  }
};

signed main() {
  int n = 4, source = 0, destination = 3;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
  Solution sol;
  cout << sol.leadsToDestination(n, edges, source, destination) << endl;

  return 0;
}