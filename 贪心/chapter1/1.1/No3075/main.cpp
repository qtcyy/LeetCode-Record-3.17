#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long maximumHappinessSum(vector<int> &happiness, int k) {
    long long ans = 0;
    ranges::sort(happiness, [](int &p1, int &p2) { return p1 > p2; });
    for (int i = 0; i < k; i++) {
      if (happiness[i] - i <= 0) {
        break;
      }
      ans += happiness[i] - i;
    }
    return ans;
  }
};

signed main() {
  vector<int> happiness = {1, 2, 3};
  int k = 2;
  Solution sol;
  cout << sol.maximumHappinessSum(happiness, k) << endl;

  return 0;
}