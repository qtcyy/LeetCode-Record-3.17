#include <iostream>
#include <numeric>
#include <string>
using namespace std;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) {
      return "";
    }
    return str2.substr(0, gcd((int)str1.length(), (int)str2.length()));
  }
};

signed main() {
  string str1 = "ABABAB", str2 = "ABAB";
  Solution sol;
  cout << sol.gcdOfStrings(str1, str2) << endl;

  return 0;
}