#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string makeSmallestPalindrome(string s) {
    int n = s.length();
    int l = 0, r = n - 1;
    while (l < r) {
      if (s[l] != s[r]) {
        if (s[l] > s[r]) {
          s[l] = s[r];
        } else {
          s[r] = s[l];
        }
      }
      l++;
      r--;
    }
    return s;
  }
};

signed main() {
  string s = "egcfe";
  Solution sol;
  cout << sol.makeSmallestPalindrome(s) << endl;

  return 0;
}