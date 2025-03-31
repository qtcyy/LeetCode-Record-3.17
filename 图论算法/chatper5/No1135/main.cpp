#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> f;

  int find(int x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]);
  }

public:
  int minimumCost(int n, vector<vector<int>> &connections) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    ranges::sort(connections,
                 [](const auto &p1, const auto &p2) { return p1[2] < p2[2]; });
    int ans = 0, sum = 0;
    for (auto &con : connections) {
      int x = find(con[0]), y = find(con[1]);
      if (x != y) {
        f[x] = y;
        ans += con[2];
        if (++sum == n - 1) {
          break;
        }
      }
    }
    if (sum != n - 1) {
      return -1;
    }
    return ans;
  }
};

signed main() {
  int n = 3;
  vector<vector<int>> conections = {{1, 2, 5}, {1, 3, 6}, {2, 3, 1}};
  Solution sol;
  cout << sol.minimumCost(n, conections) << endl;

  return 0;
}