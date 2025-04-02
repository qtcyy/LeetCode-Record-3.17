#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumCost(vector<int> &nums) {
    sort(nums.begin() + 1, nums.end());
    return nums[0] + nums[1] + nums[2];
  }
};

signed main() {
  vector<int> nums = {1, 2, 3, 12};
  Solution sol;
  cout << sol.minimumCost(nums) << endl;

  return 0;
}