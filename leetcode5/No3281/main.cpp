#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxPossibleScore(vector<int> &start, int d) {
    sort(start.begin(), start.end());
    int n = start.size();
    auto check = [&](const int &mid) {
      long long x = LLONG_MIN;
      for (int &s : start) {
        x = max(x + mid, 1ll * s);
        if (x > s + d) {
          return false;
        }
      }
      return true;
    };
    int l = 0, r = (start.back() + d - start[0]) / (n - 1) + 1;
    while (l + 1 < r) {
      int mid = l + (r - l) / 2;
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
  vector<int> start = {2, 6, 13, 13};
  int d = 5;
  Solution sol = Solution();
  cout << sol.maxPossibleScore(start, d) << endl;

  return 0;
}