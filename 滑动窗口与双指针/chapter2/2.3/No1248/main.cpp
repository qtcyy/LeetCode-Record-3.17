#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    auto slide = [&](const int &target) {
      int cnt = 0;
      int left = 0, ans = 0;
      for (int i = 0; i < n; i++) {
        cnt += nums[i] & 1;
        while (cnt >= target) {
          cnt -= nums[left++] & 1;
        }
        ans += left;
      }

      return ans;
    };

    return slide(k) - slide(k + 1);
  }
};

signed main() {
  vector<int> nums = {1, 1, 2, 1, 1};
  int k = 3;
  Solution sol;
  cout << sol.numberOfSubarrays(nums, k) << endl;

  return 0;
}