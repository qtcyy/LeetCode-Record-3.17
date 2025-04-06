#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> simplifiedFractions(int n) {}
};

signed main() {
  Solution sol;
  auto ans = sol.simplifiedFractions(4);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}