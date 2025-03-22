#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumSize(vector<int> &nums, int maxOperations) {
    auto check = [&](const int &mid) {
      int sum = 0;
      for (auto &x : nums) {
        if (x <= mid)
          continue;
        sum += (x - 1) / mid;
        if (sum > maxOperations) {
          return false;
        }
      }
      return true;
    };
    int l = 0, r = ranges::max(nums) + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        cout << mid << endl;
        r = mid;
      } else {
        l = mid;
      }
    }
    return r;
  }
};

signed main() {
  vector<int> nums = {2, 4, 8, 2};
  int maxOperations = 4;
  Solution sol = Solution();
  cout << sol.minimumSize(nums, maxOperations) << endl;

  return 0;
}