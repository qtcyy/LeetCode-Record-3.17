#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumIncrements(vector<int> &nums, vector<int> &target) {
    // f{i}{j} 前 i 个元素操作几次能满足集合j
    // 状态：改/不改
    // 不改 f{i}{j}=f{i-1}{j}
    // 改   f{i}{j}=min(f{i}{j},f{i-1}{j^s}+nums{i}- lcms{s})

    using ll = long long;
    int m = nums.size(), n = target.size();
    vector<long long> lcms(1 << n);
    lcms[0] = 1;
    for (int s = 1; s < 1 << n; s++)
      for (int j = 0; j < n; j++)
        if (s & (1 << j))
          lcms[s] = lcm(lcms[s ^ (1 << j)], target[j]);
    vector<vector<ll>> f(m + 1, vector<ll>(1 << n));
    for (int i = 0; i < 1 << n; i++)
      f[0][i] = LLONG_MAX >> 1;
    f[0][0] = 0;
    for (int i = 0; i < m; i++) {
      for (int s = 1; s < 1 << n; s++) {
        f[i + 1][s] = f[i][s];
        for (int j = s; j; j = s & (j - 1)) {
          ll l = lcms[j];
          f[i + 1][s] = min(f[i + 1][s], f[i][s ^ j] + (l - nums[i] % l) % l);
        }
      }
    }
    return f.back().back();
  }
};

signed main() {
  vector<int> nums = {8, 4}, target = {10, 5};
  Solution sol;
  cout << sol.minimumIncrements(nums, target) << endl;

  return 0;
}