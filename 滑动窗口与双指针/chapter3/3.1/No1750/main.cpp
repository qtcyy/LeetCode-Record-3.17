#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int minimumLength(string s) {
    int n = s.length();
    int left = 0, right = n - 1;
    while (left < right && s[left] == s[right]) {
      char c = s[left];
      while (left <= right && s[left] == c) {
        ++left;
      }
      while (left <= right && s[right] == c) {
        --right;
      }
    }
    return right - left + 1;
  }
};

signed main() {
  string s = "aabccabba";
  Solution sol;
  cout << sol.minimumLength(s) << endl;

  return 0;
}