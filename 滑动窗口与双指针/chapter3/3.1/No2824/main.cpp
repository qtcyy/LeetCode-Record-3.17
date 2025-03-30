#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int countPairs(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1, ans = 0;
    ranges::sort(nums);
    while (left < right) {
      if (nums[left] + nums[right] < target) {
        ans += right - left;
        ++left;
      } else {
        --right;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {-6, 2, 5, -2, -7, -1, 3};
  int target = -2;
  Solution sol;
  cout << sol.countPairs(nums, target) << endl;

  return 0;
}