#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int triangleNumber(vector<int> &nums) {
    int n = nums.size();
    ranges::sort(nums);
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
      int left = i + 1;
      for (int j = i + 2; j < n; j++) {
        if (nums[i] + nums[left] <= nums[j]) {
          ++left;
        }
        ans += j - left;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {2, 2, 3, 4};
  Solution sol;
  cout << sol.triangleNumber(nums) << endl;

  return 0;
}