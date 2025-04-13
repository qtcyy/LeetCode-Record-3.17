#include <bit>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
    int n = workers.size(), m = bikes.size();
    vector<int> f(1 << m, INT_MAX);
    f[0] = 0;
    int res = INT_MAX;
    for (int s = 1; s < 1 << m; s++) {
      int i = popcount((unsigned)s) - 1;
      if (i >= n)
        continue;
      for (int j = 0; j < m; j++) {
        if (!(s & (1 << j)))
          continue;
        int dist =
            abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        f[s] = min(f[s], f[s ^ (1 << j)] + dist);
      }
      if (i == n - 1) {
        res = min(res, f[s]);
      }
    }
    return res;
  }
};

signed main() {
  vector<vector<int>> workers = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}},
                      bikes = {
                          {0, 999}, {1, 999}, {2, 999}, {3, 999}, {4, 999}};

  Solution sol;
  cout << sol.assignBikes(workers, bikes) << endl;

  return 0;
}