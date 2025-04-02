#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxScore(vector<int> &nums) {
    long long pre = 0;
    int ans = 0;
    ranges::sort(nums, [](int &a, int &b) { return a > b; });
    for (auto &x : nums) {
      pre += x;
      if (pre > 0) {
        ++ans;
      } else {
        break;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {2, -1, 0, 1, -3, 3, -3};
  Solution sol;
  cout << sol.maxScore(nums) << endl;

  return 0;
}