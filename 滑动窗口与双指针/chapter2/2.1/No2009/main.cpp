#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    ranges::sort(nums);
    int m = unique(nums.begin(), nums.end()) - nums.begin();
    int ans = 0, left = 0;
    for (int i = 0; i < m; i++) {
      while (nums[left] < nums[i] - n + 1) {
        ++left;
      }
      ans = max(ans, i - left + 1);
    }

    return n - ans;
  }
};

signed main() {
  vector<int> nums = {1, 2, 3, 5, 6};
  Solution sol;
  cout << sol.minOperations(nums) << endl;

  return 0;
}