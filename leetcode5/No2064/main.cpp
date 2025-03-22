#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimizedMaximum(int n, vector<int> &quantities) {
    auto check = [&](const int &mid) {
      int sum = 0;
      for (auto &x : quantities) {
        sum += x / mid + (x % mid != 0);
      }
      return sum <= n;
    };
    int l = 1, r = ranges::max(quantities);
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return r;
  }
};

signed main() {
  int n = 7;
  vector<int> quantities = {15, 10, 10};
  Solution sol = Solution();
  cout << sol.minimizedMaximum(n, quantities) << endl;

  return 0;
}