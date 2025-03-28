#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
    int ans = 0, left = 0;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      ++cnt[nums[i]];
      while (cnt.size() != i - left + 1) {
        if (!--cnt[nums[left]]) {
          cnt.erase(nums[left]);
        }
        ++left;
      }
      ans = max(ans, pre[i + 1] - pre[left]);
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};
  Solution sol;
  cout << sol.maximumUniqueSubarray(nums) << endl;

  return 0;
}