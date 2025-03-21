#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long long ans = 0;
    for (int j = 0; j < n; ++j) {
      auto r = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]);
      auto l = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]);
      ans += r - l;
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {0, 1, 7, 4, 4, 5};
  int lower = 3, upper = 6;
  Solution sol = Solution();
  cout << sol.countFairPairs(nums, lower, upper) << endl;

  return 0;
}