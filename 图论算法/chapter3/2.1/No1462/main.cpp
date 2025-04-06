#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    queue<int> q;
    vector<int> degree(numCourses);
    vector<vector<int>> g(numCourses);
    for (auto &p : prerequisites) {
      ++degree[p[1]];
      g[p[0]].push_back(p[1]);
    }
    for (int i = 0; i < numCourses; i++) {
      if (!degree[i]) {
        q.push(i);
      }
    }
    vector<vector<bool>> pre(numCourses, vector<bool>(numCourses, false));
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &v : g[u]) {
        pre[u][v] = 1;
        for (int i = 0; i < numCourses; i++) {
          pre[i][v] = pre[i][v] | pre[i][u];
        }
        if (!--degree[v]) {
          q.push(v);
        }
      }
    }
    vector<bool> res;
    for (auto &q : queries) {
      res.push_back(pre[q[0]][q[1]]);
    }
    return res;
  }
};

signed main() {
  int numCourses = 3;
  vector<vector<int>> prerequisites = {{1, 2}, {1, 0}, {2, 0}},
                      queries = {{1, 0}, {1, 2}};
  Solution sol;
  auto ans = sol.checkIfPrerequisite(numCourses, prerequisites, queries);
  for (auto x : ans) {
    cout << (x ? "true" : "false") << ' ';
  }
  cout << endl;

  return 0;
}