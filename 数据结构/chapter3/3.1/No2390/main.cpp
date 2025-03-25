#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  string removeStars(string s) {
    stack<char> st;
    for (char &ch : s) {
      if (ch == '*') {
        if (!st.empty()) {
          st.pop();
        }
      } else {
        st.push(ch);
      }
    }
    string ans = "";
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

signed main() {
  string s = "leet**cod*e";
  Solution sol = Solution();
  cout << sol.removeStars(s) << endl;

  return 0;
}