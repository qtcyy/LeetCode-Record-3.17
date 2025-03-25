#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  string removeOuterParentheses(string s) {}
};

signed main() {
  string s = "(()())(())(()(()))";
  Solution sol = Solution();
  cout << sol.removeOuterParentheses(s) << endl;

  return 0;
}