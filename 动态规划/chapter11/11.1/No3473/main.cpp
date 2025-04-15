#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSum(vector<int> &nums, int k, int m) {
    int n = nums.size();
    vector<vector<int>> f(k + 1, vector<int>(n + 1));
    vector<int> pre(n + 1);
    partial_sum(nums.begin(), nums.end(), pre.begin() + 1);
    for (int i = 1; i <= k; i++) {
      f[i][i * m - 1] = INT_MIN;
      int mx = INT_MIN;
      for (int j = m * i; j <= n - (k - i) * m; j++) {
        mx = max(mx, f[i - 1][j - m] - pre[j - m]);
        f[i][j] = max(f[i - 1][j], mx + pre[j]);
      }
    }
    return f[k][n];
  }
};

signed main() {
  vector<int> nums = {1, 2, -1, 3, 3, 4};
  int k = 2, m = 2;
  Solution sol;
  cout << sol.maxSum(nums, k, m) << endl;

  return 0;
}