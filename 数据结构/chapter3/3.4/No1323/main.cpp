#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int maxDepth(string s) {
    string st;
    int ans = 0;
    for (auto &ch : s) {
      if (st.size() && ch == ')' && st.back() == '(') {
        st.pop_back();
      } else if (ch == '(') {
        st.push_back(ch);
      }
      ans = max(ans, (int)st.size());
    }
    return ans;
  }
};

signed main() {
  string s = "(1+(2*3)+((8)/4))+1";
  Solution sol = Solution();
  cout << sol.maxDepth(s) << endl;

  return 0;
}