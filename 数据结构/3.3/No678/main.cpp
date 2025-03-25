#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  bool checkValidString(string s) {
    stack<int> leftStack;
    stack<int> asteriskStack;
    int n = s.size();

    for (int i = 0; i < n; i++) {
      char c = s[i];
      if (c == '(') {
        leftStack.push(i);
      } else if (c == '*') {
        asteriskStack.push(i);
      } else {
        if (!leftStack.empty()) {
          leftStack.pop();
        } else if (!asteriskStack.empty()) {
          asteriskStack.pop();
        } else {
          return false;
        }
      }
    }

    while (!leftStack.empty() && !asteriskStack.empty()) {
      int leftIndex = leftStack.top();
      leftStack.pop();
      int asteriskIndex = asteriskStack.top();
      asteriskStack.pop();
      if (leftIndex > asteriskIndex) {
        return false;
      }
    }

    return leftStack.empty();
  }
};

signed main() {
  string s = "(*))";
  Solution sol = Solution();
  cout << sol.checkValidString(s) << endl;

  return 0;
}