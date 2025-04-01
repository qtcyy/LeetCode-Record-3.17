#include <iostream>
using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    int ans = 0;
    for (int i = 5; i <= n; i += 5) {
      for (int x = i; x % 5 == 0; x /= 5) {
        ++ans;
      }
    }

    return ans;
  }
};

signed main() {
  Solution sol;
  cout << sol.trailingZeroes(5) << endl;

  return 0;
}