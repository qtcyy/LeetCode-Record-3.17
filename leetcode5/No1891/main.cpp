#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int maxLength(vector<int> &ribbons, int k) {
    long long tot = reduce(ribbons.begin(), ribbons.end(), 0L);
    if (tot < k) {
      return 0;
    }
    auto check = [&](const long long &mid) {
      int sum = 0;
      for (auto &x : ribbons) {
        sum += x / mid;
      }
      return sum >= k;
    };
    long long l = 1, r = tot;
    while (l + 1 < r) {
      long long mid = l + (r - l) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

signed main() {
  vector<int> ribbons = {9, 7, 5};
  int k = 3;
  Solution sol = Solution();
  cout << sol.maxLength(ribbons, k) << endl;

  return 0;
}