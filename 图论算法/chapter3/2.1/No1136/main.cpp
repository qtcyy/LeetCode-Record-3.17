#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumSemesters(int n, vector<vector<int>> &relations) {
    vector<vector<int>> g(n + 1);
    vector<int> degree(n + 1);
    for (auto &p : relations) {
      g[p[0]].push_back(p[1]);
      ++degree[p[1]];
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (!degree[i]) {
        q.push(i);
      }
    }
    int sz = 0, point = 0;
    while (!q.empty()) {
      int cur = q.size();
      ++sz;
      for (int i = 0; i < cur; i++) {
        int u = q.front();
        q.pop();
        ++point;
        for (auto &v : g[u]) {
          if (!--degree[v]) {
            q.push(v);
          }
        }
      }
    }
    return point == n ? sz : -1;
  }
};

signed main() {
  int n = 3;
  vector<vector<int>> relations = {{1, 3}, {2, 3}};
  Solution sol;
  cout << sol.minimumSemesters(n, relations) << endl;

  return 0;
}