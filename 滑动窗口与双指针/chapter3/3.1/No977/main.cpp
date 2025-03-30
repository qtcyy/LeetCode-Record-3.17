#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    vector<int> ans;
    while (left < right) {
      int x = nums[left] * nums[left], y = nums[right] * nums[right];
      if (x <= y) {
        ans.push_back(y);
        --right;
      } else {
        ans.push_back(x);
        ++left;
      }
    }
    if (left == right) {
      ans.push_back(nums[left] * nums[left]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

signed main() {
  vector<int> nums = {-7, -3, 2, 3, 11};
  Solution sol;
  vector<int> ans = sol.sortedSquares(nums);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}