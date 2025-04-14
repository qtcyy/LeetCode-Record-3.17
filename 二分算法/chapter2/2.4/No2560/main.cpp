#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int minCapability(vector<int> &nums, int k) {
    int n = nums.size();
    auto [mn, mx] = ranges::minmax(nums);
    int l = mn - 1, r = mx + 1;
    auto check = [&](const int &mid) -> bool {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (nums[i] <= mid) {
          ++cnt;
          ++i;
        }
      }
      return cnt >= k;
    };

    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return r;
  }
};

signed main() {
  vector<int> nums = {2, 7, 9, 3, 1};
  int k = 2;
  Solution sol;
  cout << sol.minCapability(nums, k) << endl;

  return 0;
}