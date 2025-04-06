#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string maxValue(string n, int x) {
    char y = char(x + '0');
    int i = 0;
    if (n[0] != '-') {
      for (; i < n.length() && n[i] >= y; i++)
        ;
    } else {
      for (i = 1; i < n.length() && n[i] <= y; i++)
        ;
    }
    return n.substr(0, i) + y + n.substr(i, n.length() - i);
  }
};

signed main() {
  string n = "99";
  int x = 9;
  Solution sol;
  cout << sol.maxValue(n, x) << endl;

  return 0;
}