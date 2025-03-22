#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimizeArrayValue(vector<int> &nums) {
    int n = nums.size();
    auto check = [n](const long long &mid, vector<int> nums) {
      long long extra = 0;
      for (int i = n - 1; i > 0; i--) {
        extra = max(nums[i] + extra - mid, 0LL);
      }
      return nums[0] + extra <= mid;
    };
    long long l = -1, r = ranges::max(nums);
    while (l + 1 < r) {
      long long mid = l + (r - l) / 2;
      if (check(mid, nums)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return r;
  }
};

signed main() {
  vector<int> nums = {6, 9, 3, 8, 14};
  Solution sol = Solution();
  cout << sol.minimizeArrayValue(nums) << endl;

  return 0;
}