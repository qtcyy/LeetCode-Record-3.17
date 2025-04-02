#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minDifference(vector<int> &nums) {
    if (nums.size() <= 3) {
      return 0;
    }
    ranges::sort(nums);
    int n = nums.size();
    int ans = INT_MAX;
    for (int k = 0; k <= 3; k++) {
      ans = min(ans, nums[n - k - 1] - nums[3 - k]);
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 5, 0, 10, 14};
  Solution sol;
  cout << sol.minDifference(nums) << endl;

  return 0;
}