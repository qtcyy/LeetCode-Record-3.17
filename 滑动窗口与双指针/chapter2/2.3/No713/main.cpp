#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int n = nums.size();
    int left = 0, ans = 0, s = 1;
    if (k <= *min_element(nums.begin(), nums.end())) {
      return 0;
    }
    for (int i = 0; i < n; i++) {
      s *= nums[i];
      while (s >= k) {
        s /= nums[left++];
      }
      ans += i - left + 1;
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 2, 3};
  int k = 0;
  Solution sol;
  cout << sol.numSubarrayProductLessThanK(nums, k) << endl;

  return 0;
}