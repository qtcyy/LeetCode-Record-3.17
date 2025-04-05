#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  long long minimumRemoval(vector<int> &beans) {
    ranges::sort(beans);
    int n = beans.size();
    long long tot = reduce(beans.begin(), beans.end(), 0ll), ans = tot;
    for (int i = 0; i < n; i++) {
      ans = min(ans, tot - 1ll * beans[i] * (n - i));
    }

    return ans;
  }
};

signed main() {
  Solution sol;
  vector<int> beans = {4, 1, 6, 5};
  cout << sol.minimumRemoval(beans) << endl;

  return 0;
}