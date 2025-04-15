#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int numSquarefulPerms(vector<int> &nums) {
    int n = nums.size();
    vector<vector<bool>> st(n, vector<bool>(n, false));
    for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++) {
        int sum = nums[i] + nums[j];
        int sq = sqrt(sum);
        if (sq * sq == sum) {
          st[i][j] = st[j][i] = 1;
        }
      }
    vector<vector<int>> f(n, vector<int>(1 << n));
    for (int i = 0; i < n; i++)
      f[i][1 << i] = 1;
    for (int s = 1; s < 1 << n; s++) {
      for (int i = 0; i < n; i++) {
        if (!(s >> i & 1))
          continue;
        int sub = s ^ (1 << i);
        for (int k = 0; k < n; k++) {
          if (k == i || !(sub >> k & 1) || !st[i][k])
            continue;
          f[i][s] += f[k][sub];
        }
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
      res += f[i].back();
    unordered_map<int, int> mp;
    for (int &x : nums)
      ++mp[x];
    auto fact = [](int x) -> int {
      int mul = 1;
      for (int i = 2; i <= x; i++) {
        mul *= i;
      }
      return mul;
    };
    int repeat = 1;
    for (auto &&[x, c] : mp) {
      repeat *= fact(c);
    }
    return res / repeat;
  }
};

signed main() {
  vector<int> nums = {1, 17, 8};
  Solution sol;
  cout << sol.numSquarefulPerms(nums) << endl;

  return 0;
}