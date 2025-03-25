#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxResult(vector<int> &nums, int k) {}
};

signed main() {
  vector<int> nums = {1, -1, -2, 4, -7, 3};
  int k = 2;
  Solution sol = Solution();
  cout << sol.maxResult(nums, k) << endl;

  return 0;
}