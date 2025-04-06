#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string smallestString(string s) {
    int n = s.length();
    int start = n - 1;
    for (int i = 0; i < n; i++) {
      if (s[i] != 'a') {
        start = i;
        break;
      }
    }
    int end = n - 1;
    for (int i = start; i < n; i++) {
      if (s[i] == 'a') {
        break;
      }
      end = i;
    }
    for (int i = start; i <= end; i++) {
      --s[i];
      if (s[i] == 96) {
        s[i] += 26;
      }
    }
    return s;
  }
};

signed main() {
  string s = "aa";
  Solution sol;
  cout << sol.smallestString(s) << endl;

  return 0;
}