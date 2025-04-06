#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  long long numberOfWeeks(vector<int> &milestones) {
    long long sum = reduce(milestones.begin(), milestones.end(), 0LL);
    long long mx = ranges::max(milestones);
    if (mx >= sum - mx) {
      return (sum - mx) * 2 + 1;
    } else {
      return sum;
    }
  }
};

signed main() {
  vector<int> milestones = {5, 2, 1};
  Solution sol;
  cout << sol.numberOfWeeks(milestones) << endl;

  return 0;
}