#include <iostream>
using namespace std;

class Solution {
public:
  int minOperations(int n) {
    string s;
    while (n) {
      if (n & 1) {
        s.push_back('1');
      } else {
        s.push_back('0');
      }
      n >>= 1;
    }
    int ans = 0, cnt = 0;
    s.push_back(0);
    for (char &ch : s) {
      if (ch == '1') {
        ++cnt;
      } else {
        if (cnt > 1) {
          ch = '1';
          ++ans;
          cnt = 1;
        } else if (cnt == 1) {
          ++ans;
          cnt = 0;
        }
      }
    }

    return ans + cnt;
  }
};

signed main() {
  int n = 54;
  Solution sol;
  cout << sol.minOperations(n) << endl;

  return 0;
}