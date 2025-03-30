#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
  bool judgeSquareSum(int c) {
    int k = sqrt(c);
    long long left = 0, right = k;
    while (left < right) {
      long long val = left * left + right * right;
      if (val == c) {
        return true;
      } else if (val < c) {
        ++left;
      } else {
        --right;
      }
    }
    return false;
  }
};

signed main() {
  int c = 5;
  Solution sol;
  cout << sol.judgeSquareSum(c) << endl;

  return 0;
}