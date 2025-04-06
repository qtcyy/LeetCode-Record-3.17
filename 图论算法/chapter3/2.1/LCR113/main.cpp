#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> g(numCourses);
    vector<int> degree(numCourses);
    for (auto &p : prerequisites) {
      g[p[0]].push_back(p[1]);
      ++degree[p[1]];
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (!degree[i]) {
        q.push(i);
      }
    }
    vector<int> ans;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      ans.push_back(u);
      for (auto &v : g[u]) {
        if (!--degree[v]) {
          q.push(v);
        }
      }
    }
    if (ans.size() != numCourses) {
      return {};
    }

    return vector<int>(ans.rbegin(), ans.rend());
  }
};

signed main() {
  int numCourses = 4;
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  Solution sol;
  auto ans = sol.findOrder(numCourses, prerequisites);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}