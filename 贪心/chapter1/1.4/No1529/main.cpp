#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int minFlips(string target) {
    bool flag = false;
    int ans = 0;
    for (auto &ch : target) {
      if ((ch == '1' && !flag) || (ch == '0' && flag)) {
        ++ans;
        flag = !flag;
      }
    }
    return ans;
  }
};

signed main() {
  string target = "10111";
  Solution sol;
  cout << sol.minFlips(target) << endl;

  return 0;
}