#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int destroyTargets(vector<int> &nums, int space) {
    unordered_map<int, int> cnt;
    for (auto &x : nums) {
      ++cnt[x % space];
    }
    int mx = 0;
    for (auto &&[_, val] : cnt) {
      mx = max(mx, val);
    }
    int ans = INT_MAX;
    for (auto &x : nums) {
      if (cnt[x % space] == mx) {
        ans = min(ans, x);
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {3, 7, 8, 1, 1, 5};
  int space = 2;
  Solution sol;
  cout << sol.destroyTargets(nums, space) << endl;

  return 0;
}