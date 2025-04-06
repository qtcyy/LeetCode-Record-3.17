#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string getSmallestString(string s) {
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
      if ((s[i] % 2) == (s[i + 1] % 2) && s[i] > s[i + 1]) {
        swap(s[i], s[i + 1]);
        break;
      }
    }
    return s;
  }
};

signed main() {
  string s = "45320";
  Solution sol;
  cout << sol.getSmallestString(s) << endl;

  return 0;
}