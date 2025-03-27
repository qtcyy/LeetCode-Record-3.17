#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> distinctNumbers(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> cnt;
    vector<int> ans;
    for (int i = 0; i <= n; i++) {
      if (i < k) {
        ++cnt[nums[i]];
      } else {
        ans.push_back((int)cnt.size());
        if (i == n) {
          break;
        }
        ++cnt[nums[i]];
        if (!--cnt[nums[i - k]]) {
          cnt.erase(nums[i - k]);
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 2, 3, 2, 2, 1, 3};
  int k = 3;
  Solution sol;
  vector<int> ans = sol.distinctNumbers(nums, k);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}