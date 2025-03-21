#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    int n = nums.size();
    if (n < 3) {
      return false;
    }
    int left_min = nums[0];
    multiset<int> right_all;
    for (int k = 2; k < n; k++) {
      right_all.insert(nums[k]);
    }
    for (int j = 1; j < n - 1; j++) {
      if (left_min < nums[j]) {
        auto it = right_all.upper_bound(left_min);
        if (it != right_all.end() && *it < nums[j]) {
          return true;
        }
      }
      left_min = min(left_min, nums[j]);
      right_all.erase(right_all.find(nums[j + 1]));
    }
    return false;
  }
};

signed main() {
  vector<int> nums = {3, 1, 4, 2};
  Solution sol = Solution();
  cout << sol.find132pattern(nums) << endl;

  return 0;
}