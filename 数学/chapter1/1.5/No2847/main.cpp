#include <iostream>
using namespace std;

class Solution {
public:
  string smallestNumber(long long n) {
    if (n == 1) {
      return "1";
    } else if (n == 0) {
      return "0";
    }
    string ans;
    for (int i = 9; i >= 2; i--) {
      while (n % i == 0) {
        n /= i;
        ans.push_back(i + '0');
      }
    }
    if (n >= 2) {
      return "-1";
    }
    return string(ans.rbegin(), ans.rend());
  }
};

signed main() {
  Solution sol;
  cout << sol.smallestNumber(105) << endl;

  return 0;
}