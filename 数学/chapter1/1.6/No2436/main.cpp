#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumSplits(vector<int> &nums) {
    int val = 0, ans = 1;
    for (auto &x : nums) {
      val = gcd(val, x);
      if (val == 1) {
        ++ans;
        val = x;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {12, 6, 3, 14, 8};
  Solution sol;
  cout << sol.minimumSplits(nums) << endl;

  return 0;
}