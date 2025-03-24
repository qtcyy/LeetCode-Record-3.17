#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minLength(string s) {
    stack<char> st;
    for (auto &ch : s) {
      if ((ch == 'B' || ch == 'D') && !st.empty()) {
        if (ch == 'B' && st.top() == 'A') {
          st.pop();
          continue;
        }
        if (ch == 'D' && st.top() == 'C') {
          st.pop();
          continue;
        }
      }
      st.push(ch);
    }

    return st.size();
  }
};

signed main() {
  string s = "ABFCACDB";
  Solution sol = Solution();
  cout << sol.minLength(s) << endl;

  return 0;
}