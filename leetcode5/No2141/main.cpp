#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxRunTime(int n, vector<int> &batteries) {
    long long tot = reduce(batteries.begin(), batteries.end(), 0L);
    long long l = 0, r = tot / n + 1;
    while (l + 1 < r) {
      long long mid = l + (r - l) / 2;
      long long sum = 0;
      for (auto &b : batteries) {
        sum += min(1ll * b, mid);
      }
      if (mid * n <= sum) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

signed main() {
  int n = 2;
  vector<int> batteries = {3, 3, 3};
  Solution sol = Solution();
  cout << sol.maxRunTime(n, batteries) << endl;

  return 0;
}