#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    vector<int> st;
    for (char &ch : s) {
      if (ch == 'c' && st.size() >= 2 && st[st.size() - 1] == 'b' &&
          st[st.size() - 2] == 'a') {
        st.pop_back();
        st.pop_back();
      } else {
        st.push_back(ch);
      }
    }
    return st.size() == 0;
  }
};

signed main() {
  string s = "abcabcababcc";
  Solution sol = Solution();
  cout << sol.isValid(s) << endl;

  return 0;
}