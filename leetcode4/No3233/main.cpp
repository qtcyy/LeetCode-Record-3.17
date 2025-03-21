#include <cmath>
#include <iostream>
using namespace std;
const int MX = 31622;
int pi[MX + 1];

auto init = [] {
  for (int i = 2; i <= MX; i++) {
    if (!pi[i]) {
      pi[i] = pi[i - 1] + 1;
      for (int j = i * i; j <= MX; j += i) {
        pi[j] = -1;
      }
    } else {
      pi[i] = pi[i - 1];
    }
  }
  return 0;
}();

class Solution {
public:
  int nonSpecialCount(int l, int r) {
    return r - l + 1 - (pi[(int)sqrt(r)] - pi[(int)sqrt(l - 1)]);
  }
};

signed main() {
  Solution sol = Solution();
  cout << sol.nonSpecialCount(5, 7) << endl;

  return 0;
}