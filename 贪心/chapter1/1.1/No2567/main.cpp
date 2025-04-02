#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimizeSum(vector<int> &nums) {
    ranges::sort(nums);
    int n = nums.size();
    return min(
        {nums[n - 2] - nums[0], nums[n - 1] - nums[2], nums[n - 2] - nums[1]});
  }
};

signed main() {
  Solution sol;
  vector<int> nums = {1, 4, 7, 8, 5};
  cout << sol.minimizeSum(nums) << endl;

  return 0;
}