#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  string removeDuplicates(string s, int k) {
    stack<pair<char, int>> st;
    for (auto &ch : s) {
      if (!st.empty()) {
        if (ch == st.top().first) {
          auto pr = st.top();
          st.pop();
          pr.second++;
          if (pr.second != k) {
            st.push(pr);
          }
        } else {
          st.push(make_pair(ch, 1));
        }
      } else {
        st.push(make_pair(ch, 1));
      }
    }
    string ans = "";
    while (!st.empty()) {
      auto pr = st.top();
      st.pop();
      for (int i = 0; i < pr.second; i++) {
        ans += pr.first;
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

signed main() {
  string s = "pbbcggttciiippooaais";
  int k = 2;
  Solution sol = Solution();
  cout << sol.removeDuplicates(s, k) << endl;

  return 0;
}