#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long largestPerimeter(vector<int> &nums) {
    ranges::sort(nums, [](int &a, int &b) { return a > b; });
    int n = nums.size();
    vector<long long> pre(n + 1);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
    for (int i = 0; i < n - 2; i++) {
      if (nums[i] < pre.back() - pre[i + 1]) {
        return nums[i] + pre.back() - pre[i + 1];
      }
    }
    return -1;
  }
};

signed main() {
  vector<int> nums = {1, 12, 1, 2, 5, 50, 3};
  Solution sol;
  cout << sol.largestPerimeter(nums) << endl;

  return 0;
}