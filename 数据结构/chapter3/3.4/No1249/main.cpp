#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  string minRemoveToMakeValid(string s) {
    stack<char> st;
    stack<int> stk;
    string res;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      char ch = s[i];
      if (ch == ')' && st.empty()) {
        stk.push(i);
        continue;
      }
      if (ch == ')' && !st.empty()) {
        st.pop();
        stk.pop();
      } else if (ch == '(') {
        st.push(ch);
        stk.push(i);
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (!stk.empty()) {
        int top = stk.top();
        if (top == i) {
          stk.pop();
          continue;
        }
      }
      res.push_back(s[i]);
    }
    reverse(res.begin(), res.end());

    return res;
  }
};

signed main() {
  string s = "))((";
  Solution sol = Solution();
  cout << sol.minRemoveToMakeValid(s) << endl;

  return 0;
}