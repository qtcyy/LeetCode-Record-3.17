#include <iostream>
using namespace std;

class Solution {
public:
  bool isThree(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        if (n / i != i) {
          sum += 2;
        } else {
          ++sum;
        }
      }
    }
    return sum == 3;
  }
};

signed main() {
  int n = 4;
  Solution sol;
  cout << (sol.isThree(n) ? "true" : "false") << endl;
  return 0;
}