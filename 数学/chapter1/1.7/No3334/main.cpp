#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxScore(vector<int> &nums) {
    int n = nums.size();
    vector<long long> suf_gcd(n + 1), suf_lcm(n + 1);
    suf_lcm.back() = 1;
    for (int i = n - 1; i >= 0; i--) {
      suf_gcd[i] = gcd(suf_gcd[i + 1], nums[i]);
      suf_lcm[i] = lcm(suf_lcm[i + 1], nums[i]);
    }
    long long ans = suf_gcd[0] * suf_lcm[0];
    long long pre_lcm = 1, pre_gcd = 0;
    for (int i = 0; i < n; i++) {
      ans =
          max(ans, gcd(pre_gcd, suf_gcd[i + 1]) * lcm(pre_lcm, suf_lcm[i + 1]));
      pre_lcm = lcm(pre_lcm, nums[i]);
      pre_gcd = gcd(pre_gcd, nums[i]);
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {2, 4, 8, 16};
  Solution sol;
  cout << sol.maxScore(nums) << endl;

  return 0;
}