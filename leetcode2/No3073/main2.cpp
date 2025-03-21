#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumTripletValue(vector<int> &nums) {
    int n = nums.size();
    multiset<int> left_all;
    left_all.insert(nums[0]);
    vector<int> suf_max(n, 0);
    suf_max[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suf_max[i] = max(suf_max[i + 1], nums[i]);
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      auto left = left_all.lower_bound(nums[i]);
      left--;
      cout << *left << endl;
      if (left != left_all.end() && *left < nums[i] &&
          nums[i] < suf_max[i + 1]) {
        ans = max(ans, *left - nums[i] + suf_max[i + 1]);
      }
      left_all.insert(nums[i]);
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {7, 24, 7, 29};
  Solution sol = Solution();
  cout << sol.maximumTripletValue(nums) << endl;

  return 0;
}