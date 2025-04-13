#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool canDistribute(vector<int> &nums, vector<int> &quantity) {
    int n = quantity.size();
    unordered_map<int, int> cnt;
    for (int &x : nums)
      ++cnt[x];
    vector<int> a;
    for (auto &&[_, c] : cnt)
      a.push_back(c);
    int m = a.size();

    vector<int> sum(1 << n);
    for (int s = 1; s < 1 << n; s++)
      for (int i = 0; i < n; i++)
        if (s & (1 << i))
          sum[s] += quantity[i];
    vector<vector<bool>> f(m, vector<bool>(1 << n, false));
    for (int i = 0; i < m; i++)
      f[i][0] = true;
    for (int i = 0; i < m; i++) {
      for (int s = 0; s < 1 << n; s++) {
        if (i > 0 && f[i - 1][s]) {
          f[i][s] = true;
          continue;
        }
        for (int j = s; j; j = s & (j - 1)) {
          int pre = s ^ j;
          bool last = i == 0 ? (pre == 0) : f[i - 1][pre];
          bool need = sum[j] <= a[i];
          if (last && need) {
            f[i][s] = true;
            break;
          }
        }
      }
    }
    return f.back().back();
  }
};

signed main() {
  vector<int> nums = {1, 1, 2, 2}, quantity = {2, 2};
  Solution sol;
  cout << sol.canDistribute(nums, quantity) << endl;

  return 0;
}