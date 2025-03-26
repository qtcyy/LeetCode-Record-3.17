#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {}
};

signed main() {
  vector<string> strs = {"flower", "flow", "flight"};
  Solution sol = Solution();
  cout << sol.longestCommonPrefix(strs) << endl;

  return 0;
}