#include <cctype>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    string p;
    for (char &ch : s) {
      if (isalpha(ch)) {
        if (ch >= 'A' && ch <= 'Z') {
          ch += 32;
        }
        p.push_back(ch);
      } else if (isalnum(ch)) {
        p.push_back(ch);
      }
    }
    cout << p << endl;
    int right = p.size() - 1;
    int left = 0;
    while (left < right) {
      if (p[left] != p[right]) {
        return false;
      }
      ++left;
      --right;
    }
    return true;
  }
};

signed main() {
  string s = "0P";
  Solution sol;
  cout << sol.isPalindrome(s) << endl;

  return 0;
}