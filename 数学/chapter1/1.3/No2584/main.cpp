#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int findValidSplit(vector<int> &nums) {
    unordered_map<int, int> left;
    int n = nums.size();
    vector<int> right(n, 0);
    auto f = [&](int d, int i) {
      auto l = left.find(d);
      if (l == left.end()) {
        left[d] = i;
      } else {
        right[l->second] = i;
      }
    };

    for (int i = 0; i < n; i++) {
      int x = nums[i];
      for (int d = 2; d * d <= x; ++d) {
        if (x % d == 0) {
          f(d, i);
          for (x /= d; x % d == 0; x /= d)
            ;
        }
      }
      if (x > 1) {
        f(x, i);
      }
    }

    for (int l = 0, maxn = 0; l < n; ++l) {
      if (l > maxn) {
        return maxn;
      }
      maxn = max(maxn, right[l]);
    }
    return -1;
  }
};

signed main() {
  vector<int> nums = {4, 7, 8, 15, 3, 5};
  Solution sol;
  cout << sol.findValidSplit(nums) << endl;

  return 0;
}