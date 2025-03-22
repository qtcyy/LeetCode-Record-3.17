#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long repairCars(vector<int> &ranks, int cars) {
    int minn = *min_element(ranks.begin(), ranks.end());
    long long left = 0, right = 1LL * minn * cars * cars;
    while (left + 1 < right) {
      long long mid = (left + right) >> 1, s = 0;
      for (int r : ranks) {
        s += sqrt(mid / r);
      }
      if (s >= cars) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return right;
  }
};

signed main() {
  vector<int> ranks = {4, 2, 3, 1};
  int cars = 10;
  Solution sol = Solution();
  cout << sol.repairCars(ranks, cars) << endl;

  return 0;
}