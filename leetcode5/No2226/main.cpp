#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumCandies(vector<int> &candies, long long k) {
    int n = candies.size();
    auto check = [&](const int &mid) {
      long long sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += candies[i] / mid;
      }
      return sum >= k;
    };
    int l = 0;
    int r = *max_element(candies.begin(), candies.end()) + 10;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

signed main() {
  vector<int> candies = {5, 8, 6};
  int k = 3;
  Solution sol = Solution();
  cout << sol.maximumCandies(candies, k) << endl;

  return 0;
}