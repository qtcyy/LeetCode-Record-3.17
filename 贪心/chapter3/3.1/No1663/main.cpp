#include <iostream>
using namespace std;

class Solution {
public:
  string getSmallestString(int n, int k) {
    // x+(n-x)*26>=k
    // -25+26n>=k => x<=(26n-k)/25
    int a = (26 * n - k) / 25;
    int b = n - a, val = k - a;
    int rest = val - (b - 1) * 26;
    string res;
    cout << val << ' ' << rest << endl;
    for (int i = 0; i < a; i++) {
      res.push_back('a');
    }
    if (res.size() == n) {
      return res;
    }
    res.push_back('a' + rest - 1);
    for (int i = 0; i < b - 1; i++) {
      res.push_back('z');
    }
    return res;
  }
};

signed main() {
  int n = 5, k = 73;
  Solution sol;
  cout << sol.getSmallestString(n, k) << endl;

  return 0;
}