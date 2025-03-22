#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumTime(vector<int> &hens, vector<int> &grains) {
    int left = 0, right = 2000000000;
    sort(hens.begin(), hens.end());
    sort(grains.begin(), grains.end());
    auto check = [&](const int &mid) {
      int n = hens.size(), m = grains.size(), j = 0;
      for (int i = 0; i < n && j < m; ++i) {
        int minn = hens[i], maxn = hens[i];
        while (j < m) {
          minn = min(minn, grains[j]);
          maxn = max(maxn, grains[j]);
          if (min(hens[i] - minn - minn + maxn, maxn - hens[i] - minn + maxn) <=
              mid) {
            j++;
          } else
            break;
        }
      }
      return j == m;
    };
    while (left + 1 < right) {
      int mid = (left + right) >> 1;
      if (check(mid)) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return right;
  }
};

signed main() {
  vector<int> hens = {4, 6, 109, 111, 213, 215}, grains = {5, 110, 214};
  Solution sol = Solution();
  cout << sol.minimumTime(hens, grains) << endl;

  return 0;
}