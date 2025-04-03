#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfBeams(vector<string> &bank) {
    int prev = 0, ans = 0;
    for (auto &row : bank) {
      // count
      int cnt = 0;
      for (auto &ch : row) {
        if (ch == '1')
          ++cnt;
      }
      if (cnt == 0)
        continue;
      if (prev) {
        ans += cnt * prev;
      }
      prev = cnt;
    }
    return ans;
  }
};

signed main() {
  vector<string> bank = {"011001", "000000", "010100", "001000"};
  Solution sol;
  cout << sol.numberOfBeams(bank) << endl;

  return 0;
}