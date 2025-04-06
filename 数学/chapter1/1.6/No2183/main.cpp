#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  long long countPairs(vector<int> &nums, int k) {
    vector<int> div;
    for (int d = 1; d * d <= k; ++d) {
      if (k % d == 0) {
        div.push_back(d);
        if (d * d < k) {
          div.push_back(k / d);
        }
      }
    }
    long long ans = 0;
    unordered_map<int, int> cnt;
    for (auto &x : nums) {
      ans += cnt[k / gcd(x, k)];
      for (auto &d : div) {
        if (x % d == 0) {
          ++cnt[d];
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  int k = 2;
  Solution sol;
  cout << sol.countPairs(nums, k) << endl;

  return 0;
}