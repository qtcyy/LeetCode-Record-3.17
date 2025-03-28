#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumBeauty(vector<int> &nums, int k) {
    int n = nums.size();
    int left = 0, ans = 0;
    k *= 2;
    ranges::sort(nums);
    for (int i = 0; i < n; i++) {
      while (nums[i] - nums[left] > k) {
        ++left;
      }
      ans = max(ans, i - left + 1);
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {4, 6, 1, 2};
  int k = 2;
  Solution sol;
  cout << sol.maximumBeauty(nums, k) << endl;

  return 0;
}