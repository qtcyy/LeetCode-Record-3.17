#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumTripletValue(vector<int> &nums) {
    int n = nums.size();
    multiset<int> right_all;
    for (int i = 2; i < n; i++) {
      right_all.insert(nums[i]);
    }
    vector<int> pre_max(n, 0);
    pre_max[0] = nums[0];
    for (int i = 1; i < n; i++) {
      pre_max[i] = max(pre_max[i - 1], nums[i]);
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      if (pre_max[i - 1] >= nums[i]) {
        continue;
      }
      int base = max(pre_max[i - 1], nums[i]);
      auto it = right_all.upper_bound(base);
      if (it != right_all.end() && *it > nums[i]) {
        ans = max(ans, pre_max[i - 1] - nums[i] + *it);
      }
      right_all.erase(right_all.find(nums[i + 1]));
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 5, 3, 6};
  Solution sol = Solution();
  cout << sol.maximumTripletValue(nums) << endl;

  return 0;
}