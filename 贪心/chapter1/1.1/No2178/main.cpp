#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<long long> maximumEvenSplit(long long finalSum) {
    if (finalSum & 1) {
      return {};
    }
    vector<long long> ans;
    long long sum = 0;
    for (int i = 2; i <= finalSum; i += 2) {
      sum += i;
      if (sum > finalSum) {
        sum -= i;
        ans.back() += finalSum - sum;
        break;
      } else {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

signed main() {
  Solution sol;
  auto ans = sol.maximumEvenSplit(28);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}