#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int removeAlmostEqualCharacters(string word) {
    int n = word.length();
    if (n <= 1) {
      return 0;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (abs(word[i] - word[i + 1]) <= 1) {
        ++ans;
        word[i + 1] = ' ';
      }
    }

    return ans;
  }
};

signed main() {
  string word = "abddez";
  Solution sol;
  cout << sol.removeAlmostEqualCharacters(word) << endl;

  return 0;
}