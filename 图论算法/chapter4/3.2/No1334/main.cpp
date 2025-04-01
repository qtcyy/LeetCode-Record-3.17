#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
    vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));
    for (int i = 0; i < n; i++)
      g[i][i] = 0;
    for (auto &p : edges) {
      g[p[0]][p[1]] = g[p[1]][p[0]] = p[2];
    }
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (g[i][j] > g[i][k] + g[k][j]) {
            g[i][j] = g[i][k] + g[k][j];
          }

    int mn = n + 1, ans = -1;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        if (g[i][j] <= distanceThreshold)
          ++cnt;
      }
      if (cnt <= mn) {
        mn = cnt;
        ans = i;
      }
    }
    return ans;
  }
};

signed main() {
  int n = 4;
  vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
  int distanceThreshold = 4;
  Solution sol;
  cout << sol.findTheCity(n, edges, distanceThreshold) << endl;

  return 0;
}