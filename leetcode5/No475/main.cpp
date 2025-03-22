#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(heaters.begin(), heaters.end());
    auto check = [&](const int &mid) {
      for (auto &x : houses) {
        auto it = lower_bound(heaters.begin(), heaters.end(), x);
        // cout << *it << ' ';
        if (it == heaters.begin()) {
          if (abs(x - *it) > mid) {
            return false;
          }
        } else if (it == heaters.end()) {
          --it;
          if (abs(x - *it) > mid) {
            return false;
          }
        } else {
          if (abs(x - *it) > mid && abs(x - *(it - 1)) > mid) {
            return false;
          }
        }
      }
      return true;
    };
    int l = 0, r = max(*max_element(houses.begin(), houses.end()),
                       *max_element(heaters.begin(), heaters.end()));
    while (l < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};

signed main() {
  vector<int> houses = {1, 5}, heaters = {10};
  Solution sol = Solution();
  cout << sol.findRadius(houses, heaters) << endl;

  return 0;
}