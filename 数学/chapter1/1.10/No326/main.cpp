#include <iostream>
#include <vector>
using namespace std;

vector<long long> mul = {
    1,         3,          9,          27,          81,          243,
    729,       2187,       6561,       19683,       59049,       177147,
    531441,    1594323,    4782969,    14348907,    43046721,    129140163,
    387420489, 1162261467, 3486784401, 10460353203, 31381059609, 9414317882};

class Solution {
public:
  bool isPowerOfThree(int n) {
    for (auto &p : mul) {
      if (n == p) {
        return true;
      }
    }

    return false;
  }
};

signed main() {
  Solution sol;
  cout << (sol.isPowerOfThree(27) ? "true" : "false") << endl;

  return 0;
}