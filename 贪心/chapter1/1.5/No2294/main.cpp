#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int partitionArray(vector<int> &nums, int k) {
    ranges::sort(nums);
    int pre = nums[0], ans = 1;
    for (auto &x : nums) {
      if (x - pre > k) {
        pre = x;
        ++ans;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {3, 6, 1, 2, 5};
  int k = 2;
  Solution sol;
  cout << sol.partitionArray(nums, k) << endl;

  return 0;
}