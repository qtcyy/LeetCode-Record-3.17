#include <iostream>
using namespace std;

class Solution {
public:
  int minSwaps(string s) {
    int cnt = 0;
    for (char &ch : s) {
      if (ch == '[' || cnt == 0) {
        cnt++;
      } else {
        cnt--;
      }
    }
    return cnt >> 1;
  }
};

signed main() {
  string s = "]]][[[";
  Solution sol = Solution();
  cout << sol.minSwaps(s) << endl;

  return 0;
}