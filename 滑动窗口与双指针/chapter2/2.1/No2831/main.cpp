#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int longestEqualSubarray(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, vector<int>> cnt;
    for (int i = 0; i < n; i++) {
      cnt[nums[i]].push_back(i);
    }
    int ans = 0;
    for (auto &&[_, pos] : cnt) {
      int m = pos.size();
      int left = 0, len = 0;
      for (int i = 0; i < m; i++) {
        while (pos[i] - pos[left] - i + left > k) {
          ++left;
        }
        len = max(len, i - left + 1);
        ans = max(ans, len);
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 3, 2, 3, 1, 3};
  int k = 3;
  Solution sol;
  cout << sol.longestEqualSubarray(nums, k) << endl;

  return 0;
}