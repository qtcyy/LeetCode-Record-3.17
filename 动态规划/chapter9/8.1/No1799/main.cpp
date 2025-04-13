#include <bit>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int maxScore(vector<int> &nums) {
    int n = nums.size();
    vector<int> f(1 << (n), 0);
    for (int s = 1; s < 1 << (n); s++) {
      int i = popcount((unsigned)s) / 2;
      for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (s & (1 << j) && s & (1 << k)) {
            f[s] = max(f[s],
                       f[s ^ (1 << j) ^ (1 << k)] + gcd(nums[j], nums[k]) * i);
          }
        }
      }
    }
    return f.back();
  }
};

signed main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  Solution sol;
  cout << sol.maxScore(nums) << endl;

  return 0;
}