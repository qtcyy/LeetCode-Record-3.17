#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int smallestValue(int n) {
    auto calc = [](int n) {
      int res = 0;
      for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
          while (n % i == 0) {
            n /= i;
            res += i;
          }
        }
      }
      if (n != 1) {
        res += n;
      }
      return res;
    };
    while (true) {
      int x = calc(n);
      if (x == n) {
        return x;
      }
      n = x;
    }
  }
};

signed main() {
  Solution sol = Solution();
  int n = 15;
  cout << sol.smallestValue(n) << endl;

  return 0;
}