#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
  int smallestFactorization(int num) {
    if (num < 2) {
      return num;
    }
    int ans = 0, mul = 1;
    for (int i = 9; i >= 2; i--) {
      while (num % i == 0) {
        num /= i;
        ans = mul * i + ans;
        mul *= 10;
      }
    }
    if (ans > INT_MAX) {
      return 0;
    } else if (ans < 2) {
      return 1;
    }
    if (num < 2 && ans <= INT_MAX) {
      return ans;
    } else {
      return 0;
    }
  }
};

signed main() {
  Solution sol;
  cout << sol.smallestFactorization(48) << endl;

  return 0;
}