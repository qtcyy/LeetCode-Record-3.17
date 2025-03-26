#include <iostream>
using namespace std;

class Solution {
public:
  string strWithout3a3b(int a, int b) {
    string ans;
    while (a || b) {
      if (a > b) {
        if (a > 1) {
          a -= 2;
          ans += "aa";
          if (b > 0) {
            b--;
            ans += 'b';
          }
        } else {
          a--;
          ans += 'a';
        }
      } else if (a < b) {
        if (b > 1) {
          b -= 2;
          ans += "bb";
          if (a > 0) {
            a--;
            ans += 'a';
          }
        } else {
          b--;
          ans += 'b';
        }
      } else {
        ans += "ab";
        a--;
        b--;
      }
    }

    return ans;
  }
};

signed main() {
  int a = 4, b = 4;
  Solution sol = Solution();
  cout << sol.strWithout3a3b(a, b) << endl;

  return 0;
}