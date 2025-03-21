#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    vector<int> idx(60, 0);
    int ans = 0;
    for (auto &num : time) {
      num %= 60;
      if (num == 0) {
        ans += idx[0];
      } else {
        ans += idx[60 - num];
      }
      idx[num]++;
    }

    return ans;
  }
};

signed main() {
  vector<int> time = {30, 20, 150, 100, 40};
  Solution sol = Solution();
  cout << sol.numPairsDivisibleBy60(time) << endl;

  return 0;
}