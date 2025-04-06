#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int validSubarraySplit(vector<int> &nums) {
    int n = nums.size();
    vector<int> f(n + 1, INT_MAX / 2);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        if (gcd(nums[i - 1], nums[j - 1]) > 1)
          f[i] = min(f[i], f[j - 1] + 1);
      }
    }
    return f[n] >= INT_MAX / 2 ? -1 : f[n];
  }
};

signed main() {
  vector<int> nums = {2, 6, 3, 4, 3};
  Solution sol;
  cout << sol.validSubarraySplit(nums) << endl;

  return 0;
}