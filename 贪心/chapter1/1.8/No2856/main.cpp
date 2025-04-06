#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minLengthAfterRemovals(vector<int> &nums) {
    int n = nums.size();
    int base = nums[n / 2];
    int max_cnt =
        ranges::upper_bound(nums, base) - ranges::lower_bound(nums, base);
    return max(max_cnt * 2 - n, n % 2);
  }
};

signed main() {
  vector<int> nums = {2, 3, 4, 4, 4};
  Solution sol;
  cout << sol.minLengthAfterRemovals(nums) << endl;

  return 0;
}