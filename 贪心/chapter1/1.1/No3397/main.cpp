#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxDistinctElements(vector<int> &nums, int k) {
    ranges::sort(nums);
    int pre = INT_MIN, ans = 0;
    for (auto &x : nums) {
      x = clamp(pre + 1, x - k, x + k);
      if (x > pre) {
        ++ans;
        pre = x;
      }
    }
    return ans;
  }
};

signed main() {
  Solution sol;
  vector<int> nums = {1, 2, 2, 3, 3, 4};
  int k = 2;
  cout << sol.maxDistinctElements(nums, k);
  return 0;
}