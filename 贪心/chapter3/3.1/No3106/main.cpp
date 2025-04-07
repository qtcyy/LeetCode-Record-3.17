#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string getSmallestString(string s, int k) {
    for (auto &ch : s) {
      int dist = min(ch - 'a', 'z' - ch + 1);
      if (k - dist >= 0) {
        ch = 'a';
        k -= dist;
      } else {
        ch -= k;
        k = 0;
        break;
      }
    }
    return s;
  }
};

signed main() {
  string s = "xaxcd";
  int k = 4;
  Solution sol;
  cout << sol.getSmallestString(s, k) << endl;

  return 0;
}