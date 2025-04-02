#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> minSubsequence(vector<int> &nums) {
    ranges::sort(nums, [](int &p1, int &p2) { return p1 > p2; });
    int all = reduce(nums.begin(), nums.end(), 0);
    int n = nums.size(), sum = 0, pos = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      if (2 * sum > all) {
        pos = i;
        break;
      }
    }
    cout << pos << endl;
    return vector<int>(nums.begin(), nums.begin() + pos + 1);
  }
};

signed main() {
  vector<int> nums = {4, 4, 7, 6, 7};
  Solution sol;
  auto ans = sol.minSubsequence(nums);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}