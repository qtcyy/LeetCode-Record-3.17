#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    if (n < 4) {
    }
  }
};

signed main() {
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  int target = 0;
  Solution sol;
  vector<vector<int>> ans = sol.fourSum(nums, target);
  for (auto &row : ans) {
    for (auto &x : row) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}