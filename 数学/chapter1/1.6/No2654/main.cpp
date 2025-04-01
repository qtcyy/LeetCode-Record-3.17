#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      int d = gcd(nums[i], nums[i + 1]);
      if (d == 1) {
        return n;
      }
    }
    return -1;
  }
};

class Solution2 {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    int cnt = 0, all_gcd = 0;
    for (auto &x : nums) {
      all_gcd = gcd(all_gcd, x);
      cnt += x == 1;
    }
    if (all_gcd > 1) {
      return -1;
    }
    if (cnt) {
      return n - cnt;
    }
    vector<pair<int, int>> g;
    int ans = n;
    for (int i = 0; i < n; i++) {
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
      if (g[0].first == 1) {
        ans = min(ans, i - g[0].second);
      }
    }
    return ans + n - 1;
  }
};

signed main() {
  vector<int> nums = {2, 6, 3, 4};
  Solution2 sol;
  cout << sol.minOperations(nums) << endl;

  return 0;
}