#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    ranges::sort(nums);
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] < 0) {
        nums[i] = -nums[i];
      } else {
        break;
      }
      if (--k == 0) {
        return reduce(nums.begin(), nums.end());
      }
    }
    ranges::sort(nums);
    if (k & 1) {
      nums[0] = -nums[0];
    }
    return reduce(nums.begin(), nums.end());
  }
};

signed main() {
  Solution sol;
  vector<int> nums = {3, -1, 0, 2};
  int k = 3;
  cout << sol.largestSumAfterKNegations(nums, k) << endl;

  return 0;
}