#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
    vector<int> degree(n);
    for (auto &p : edges) {
      ++degree[p[1]];
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (!degree[i]) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

signed main() {
  int n = 6;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
  Solution sol;
  vector<int> ans = sol.findSmallestSetOfVertices(n, edges);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}