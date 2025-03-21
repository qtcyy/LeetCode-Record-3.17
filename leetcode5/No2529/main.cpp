#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumCount(vector<int> &nums) {
    auto it = lower_bound(nums.begin(), nums.end(), 0);
    int cnt = it - nums.begin();
    it = upper_bound(nums.begin(), nums.end(), 0);
    return max(int(nums.end() - it), cnt);
  }
};

signed main() {
  vector<int> nums = {-3, -2, -1, 0, 0, 1, 2};
  Solution sol = Solution();
  cout << sol.maximumCount(nums) << endl;

  return 0;
}