#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
  int specialPerm(vector<int> &nums) {
    int n = nums.size();
    int u = (1 << n) - 1;
    vector<vector<long long>> f(u, vector<long long>(n));
    ranges::fill(f[0], 1ll);
    for (int s = 1; s < u; s++) {
      for (int i = 0; i < n; i++) {
        if (s & (1 << i))
          continue;
        for (int j = 0; j < n; j++) {
          if (s & (1 << j) &&
              (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0))
            f[s][i] += f[s ^ (1 << j)][j];
        }
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += f[u ^ (1 << i)][i];
    }
    return ans % mod;
  }
};

signed main() {
  vector<int> nums = {1, 4, 3};
  Solution sol;
  cout << sol.specialPerm(nums) << endl;

  return 0;
}