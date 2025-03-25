#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {}
};

signed main() {
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  Solution sol = Solution();
  vector<int> ans = sol.maxSlidingWindow(nums, k);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}