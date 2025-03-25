#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minAddToMakeValid(string s) {
    vector<int> res;
    for (auto &ch : s) {
      if (ch == ')' && res.size()) {
        if (res.back() == '(') {
          res.pop_back();
        } else {
          res.push_back(ch);
        }
      } else {
        res.push_back(ch);
      }
    }
    return res.size();
  }
};

signed main() {
  string s = "()))((";
  Solution sol = Solution();
  cout << sol.minAddToMakeValid(s) << endl;

  return 0;
}