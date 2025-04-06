#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int largestPerimeter(vector<int> &nums) {
    ranges::sort(nums, [](int &p1, int &p2) { return p1 > p2; });
    int n = nums.size();
    for (int i = 2; i < n; i++) {
      if (nums[i - 1] + nums[i] > nums[i - 2]) {
        return nums[i - 2] + nums[i - 1] + nums[i];
      }
    }
    return 0;
  }
};

signed main() {
  vector<int> nums = {2, 1, 2};
  Solution sol;
  cout << sol.largestPerimeter(nums) << endl;

  return 0;
}