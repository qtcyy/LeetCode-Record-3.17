#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string makeGood(string s) {
    stack<char> st;
    for (char &ch : s) {
      if (!st.empty() && abs(ch - st.top()) == 32) {
        st.pop();
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
  string s = "leEeetcode";
  Solution sol = Solution();
  cout << sol.makeGood(s) << endl;

  return 0;
}