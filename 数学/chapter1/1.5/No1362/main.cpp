#include <climits>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> closestDivisors(int num) {
    ++num;
    pair<int, int> ans = {0, 0};
    int mn = INT_MAX;
    for (int fac = sqrt(num); fac >= 1; --fac) {
      if (num % fac == 0) {
        ans = {fac, num / fac};
        mn = min(mn, ans.second - ans.first);
        break;
      }
    }
    ++num;
    for (int fac = sqrt(num); fac >= 1; --fac) {
      if (num % fac == 0) {
        pair<int, int> cur = {fac, num / fac};
        if (mn > cur.second - cur.first) {
          ans = cur;
          break;
        } else {
          break;
        }
      }
    }
    return {ans.first, ans.second};
  }
};

signed main() {
  Solution sol;
  auto ans = sol.closestDivisors(999);
  cout << ans[0] << ' ' << ans[1] << endl;

  return 0;
}