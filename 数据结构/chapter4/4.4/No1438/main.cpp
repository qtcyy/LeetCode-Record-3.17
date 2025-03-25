#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {}
};

signed main() {
  vector<int> nums = {8, 2, 4, 7};
  int limit = 4;
  Solution sol = Solution();
  cout << sol.longestSubarray(nums, limit) << endl;

  return 0;
}