#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int subarrayGCD(vector<int> &nums, int k) {
    int n = nums.size();
    vector<pair<int, int>> g;
    int ans = 0, i0 = -1;
    for (int i = 0; i < n; i++) {
      if (nums[i] % k) {
        g.clear();
        i0 = i;
        continue;
      }
      g.emplace_back(nums[i], i);
      int j = 0;
      for (auto &p : g) {
        p.first = gcd(p.first, nums[i]);
        if (g[j].first == p.first) {
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
  vector<int> nums = {9, 3, 1, 2, 6, 3};
  int k = 3;
  Solution sol;
  cout << sol.subarrayGCD(nums, k) << endl;

  return 0;
}