#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size();
    ranges::sort(nums);
    int ans = 0, mn = INF;
    for (int i = 2; i < n; i++) {
      int left = 0, right = i - 1;
      int k = target - nums[i];
      while (left < right) {
        int val = nums[left] + nums[right];
        if (abs(target - (val + nums[i])) < mn) {
          mn = abs(target - (val + nums[i]));
          ans = val + nums[i];
        }
        if (val <= k) {
          ++left;
        } else {
          --right;
        }
      }
    }
    return ans;
  }
};

signed main() {
  Solution sol;
  vector<int> nums = {0, 1, 2};
  int target = 1;
  cout << sol.threeSumClosest(nums, target) << endl;

  return 0;
}