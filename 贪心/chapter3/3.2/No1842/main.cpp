#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string nextPalindrome(string num) {
    int n = num.size();
    if (n <= 1)
      return "";

    string half = num.substr(0, n / 2);
    string res = "";

    if (next_permutation(half.begin(), half.end())) {
      res = half;

      if (n % 2 == 1)
        res += num[n / 2];

      reverse(half.begin(), half.end());
      res += half;
      return res;
    }

    return "";
  }
};

class Solution2 {
public:
  string nextPalindrome(string num) {
    int n = num.size();
    if (n <= 1) {
      return "";
    }

    string half = num.substr(0, n / 2);
    string res = "";

    if (next_permutation(half.begin(), half.end())) {
      res = half;
      if (n & 1) {
        res += num[n / 2];
      }
      reverse(half.begin(), half.end());
      res += half;
      return res;
    }
    return res;
  }
};

signed main() {
  string num = "45544554";
  Solution2 sol;
  cout << sol.nextPalindrome(num) << endl;

  return 0;
}