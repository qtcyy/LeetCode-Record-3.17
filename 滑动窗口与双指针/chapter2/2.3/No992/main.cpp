#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    int n = nums.size();
    auto slide = [&](const int &target) -> int {
      int left = 0, ans = 0;
      unordered_map<int, int> cnt;
      for (int i = 0; i < n; i++) {
        ++cnt[nums[i]];
        while (cnt.size() >= target) {
          if (!--cnt[nums[left]]) {
            cnt.erase(nums[left]);
          }
          ++left;
        }
        ans += left;
      }

      return ans;
    };

    return slide(k) - slide(k + 1);
  }
};

signed main() {
  vector<int> nums = {1, 2, 1, 2, 3};
  int k = 2;
  Solution sol;
  cout << sol.subarraysWithKDistinct(nums, k) << endl;

  return 0;
}