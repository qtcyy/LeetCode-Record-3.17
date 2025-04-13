#include <bit>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long minimumTime(vector<int> &power) {
    int n = power.size();
    vector<long long> f(1 << n, LLONG_MAX);
    f[0] = 0;
    for (int s = 1; s < 1 << n; s++) {
      int i = popcount((unsigned)s);
      for (int j = 0; j < n; j++) {
        if (s & (1 << j)) {
          long long day = ceil(1.0 * power[j] / (i));
          f[s] = min(f[s], f[s ^ (1 << j)] + day);
        }
      }
    }
    return f.back();
  }
};

signed main() {
  vector<int> power = {1, 2, 4, 9};
  Solution sol;
  cout << sol.minimumTime(power) << endl;

  return 0;
}