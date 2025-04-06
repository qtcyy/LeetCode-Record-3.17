#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int subarrayLCM(vector<int> &nums, int k) {
    int n = nums.size();
    vector<pair<int, int>> g;
    int ans = 0, i0 = -1;
    for (int i = 0; i < n; i++) {
      if (k % nums[i]) {
        g.clear();
        i0 = i;
        continue;
      }
      g.emplace_back(nums[i], i);
      int j = 0;
      for (auto &p : g) {
        p.first = lcm(p.first, nums[i]);
        if (p.first == g[j].first) {
          g[j].second = p.second;
        } else {
          g[++j] = std::move(p);
        }
      }
      g.resize(j + 1);
      if (g[0].first == k) {
        ans += g[0].second - i0;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {3, 6, 2, 7, 1};
  int k = 6;
  Solution sol;
  cout << sol.subarrayLCM(nums, k) << endl;

  return 0;
}