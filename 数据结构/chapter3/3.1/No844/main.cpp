#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    stack<char> s1, s2;
    for (auto &ch : s) {
      if (ch == '#' && !s1.empty()) {
        s1.pop();
      } else if (ch != '#') {
        s1.push(ch);
      }
    }
    for (auto &ch : t) {
      if (ch == '#' && !s2.empty()) {
        s2.pop();
      } else if (ch != '#') {
        s2.push(ch);
      }
    }
    cout << s1.size() << ' ' << s2.size() << endl;
    if (s1.size() != s2.size()) {
      return false;
    }
    while (!s1.empty()) {
      if (s1.top() != s2.top()) {
        return false;
      }
      s1.pop();
      s2.pop();
    }
    return true;
  }
};

signed main() {
  string s = "a##c", t = "#a#c";
  Solution sol = Solution();
  cout << sol.backspaceCompare(s, t) << endl;

  return 0;
}