#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int minimumPartition(string s, int k) {
    int ans = 0;
    long long sum = 0;
    for (auto &ch : s) {
      int cur = ch - '0';
      if (cur > k) {
        return -1;
      }
      sum = sum * 10 + cur;
      if (sum > k) {
        sum = cur;
        ++ans;
      }
    }
    return ans + 1;
  }
};

signed main() {
  string s = "165462";
  int k = 60;
  Solution sol;
  cout << sol.minimumPartition(s, k) << endl;

  return 0;
}