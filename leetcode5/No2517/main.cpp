#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumTastiness(vector<int> &price, int k) {
    sort(price.begin(), price.end());
    int n = price.size();
    auto check = [&](const int &mid) {
      int last = price[0], sum = 1;
      for (int i = 1; i < n; ++i) {
        if (price[i] - last >= mid) {
          last = price[i];
          ++sum;
        }
      }
      return sum >= k;
    };
    int l = -1, r = price.back() + 1;
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
  vector<int> price = {13, 5, 1, 8, 21, 2};
  int k = 3;
  Solution sol = Solution();
  cout << sol.maximumTastiness(price, k) << endl;

  return 0;
}