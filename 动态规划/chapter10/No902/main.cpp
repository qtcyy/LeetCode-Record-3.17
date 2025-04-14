#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int atMostNGivenDigitSet(vector<string> &digits, int n) {
    string s = to_string(n);
    int m = s.length();
    vector<int> f(m, -1);

    function<int(int, bool, bool)> dfs = [&](int i, bool isLimit,
                                             bool isNum) -> int {
      if (i == m)
        return isNum;
      if (!isLimit && isNum && f[i] >= 0) {
        return f[i];
      }
      int res = 0;
      if (!isNum) {
        res = dfs(i + 1, false, false);
      }
      char up = isLimit ? s[i] : '9';
      for (auto &d : digits) {
        if (d[0] > up)
          break;
        res += dfs(i + 1, isLimit && d[0] == up, true);
      }
      if (!isLimit && isNum) {
        f[i] = res;
      }
      return res;
    };

    return dfs(0, true, false);
  }
};

signed main() {
  vector<string> digits = {"1", "4", "9"};
  int n = 1000000000;
  Solution sol;
  cout << sol.atMostNGivenDigitSet(digits, n) << endl;

  return 0;
}