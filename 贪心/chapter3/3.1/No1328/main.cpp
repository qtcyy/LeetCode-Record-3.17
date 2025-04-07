#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string breakPalindrome(string palindrome) {
    int n = palindrome.length();
    if (n <= 1) {
      return "";
    }
    for (int i = 0; i * 2 < n - 1; i++) {
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;
      }
    }
    palindrome[n - 1] = 'b';
    return palindrome;
  }
};

signed main() {
  string palindrome = "abccba";
  Solution sol;
  cout << sol.breakPalindrome(palindrome) << endl;

  return 0;
}