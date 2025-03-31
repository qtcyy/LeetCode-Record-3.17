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
  Solution() : f(10005) { iota(f.begin(), f.end(), 0); }
  int minCostToSupplyWater(int n, vector<int> &wells,
                           vector<vector<int>> &pipes) {
    for (int i = 1; i <= n; i++) {
      pipes.push_back({0, i, wells[i - 1]});
    }
    ranges::sort(pipes,
                 [](const auto &p1, const auto &p2) { return p1[2] < p2[2]; });
    int ans = 0;
    for (auto &p : pipes) {
      int x = find(p[0]), y = find(p[1]);
      if (x != y) {
        f[x] = y;
        ans += p[2];
      }
    }
    return ans;
  }
};

signed main() {
  int n = 3;
  vector<int> wells = {1, 2, 2};
  vector<vector<int>> pipes = {{1, 2, 1}, {2, 3, 1}};
  Solution sol;
  cout << sol.minCostToSupplyWater(n, wells, pipes) << endl;

  return 0;
}