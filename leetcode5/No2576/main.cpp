#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxNumOfMarkedIndices(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    auto check = [&](const int &mid) {
      for (int i = 0; i < mid; i++) {
        if (nums[i] << 1 > nums[n - mid + i]) {
          return false;
        }
      }
      return true;
    };
    int l = 0, r = (n >> 1) + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l * 2;
  }
};

signed main() {
  vector<int> nums = {57, 40, 57, 51, 90, 51, 68, 100, 24, 39, 11, 85,
                      2,  22, 67, 29, 74, 82, 10, 96,  14, 35, 25, 76,
                      26, 54, 29, 44, 63, 49, 73, 50,  95, 89, 43, 62,
                      24, 88, 88, 36, 6,  16, 14, 2,   42, 42, 60, 25,
                      4,  58, 23, 22, 27, 26, 3,  79,  64, 20, 92};
  Solution sol = Solution();
  cout << sol.maxNumOfMarkedIndices(nums) << endl;

  return 0;
}