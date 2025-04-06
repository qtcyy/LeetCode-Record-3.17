#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxSum(vector<vector<int>> &grid, vector<int> &limits, int k) {
    vector<int> arr;
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      auto &row = grid[i];
      ranges::sort(row, [](int &a, int &b) { return a > b; });
      for (int j = 0; j < limits[i]; j++) {
        arr.push_back(row[j]);
      }
    }
    ranges::sort(arr, [](int &a, int &b) { return a > b; });
    return reduce(arr.begin(), arr.begin() + k, 0ll);
  }
};

signed main() {
  vector<vector<int>> grid = {{5, 3, 7}, {8, 2, 6}};
  vector<int> limits = {2, 2};
  int k = 3;
  Solution sol;
  cout << sol.maxSum(grid, limits, k) << endl;

  return 0;
}