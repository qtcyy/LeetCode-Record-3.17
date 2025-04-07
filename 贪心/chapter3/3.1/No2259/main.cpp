#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string removeDigit(string number, char digit) {
    int n = number.size();
    for (int i = 0; i + 1 < n; i++) {
      if (number[i] == digit && number[i + 1] > digit) {
        number.erase(number.begin() + i);
        return number;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (number[i] == digit) {
        number.erase(number.begin() + i);
        return number;
      }
    }
    return number;
  }
};

signed main() {
  string number = "1231";
  char digit = '1';
  Solution sol;
  cout << sol.removeDigit(number, digit) << endl;

  return 0;
}