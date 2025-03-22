#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int maximizeSweetness(vector<int> &sweetness, int k) {
    int tot = reduce(sweetness.begin(), sweetness.end(), 0);
    auto check = [&](const int &mid) {
      int sum = 0, cnt = 0;
      for (auto &x : sweetness) {
        sum += x;
        if (sum >= mid) {
          sum = 0;
          ++cnt;
        }
      }
      return cnt >= k + 1;
    };
    int l = 0, r = tot + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
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
  vector<int> sweetness = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int K = 5;
  Solution sol = Solution();
  cout << sol.maximizeSweetness(sweetness, K) << endl;

  return 0;
}