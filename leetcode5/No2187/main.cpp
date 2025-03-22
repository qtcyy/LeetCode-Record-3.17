#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long minimumTime(vector<int> &time, int totalTrips) {
    int n = time.size();
    auto check = [&](const long long &mid) {
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += mid / time[i];
      }
      return sum >= totalTrips;
    };
    auto [min_t, max_t] = ranges::minmax(time);
    int avg = (totalTrips - 1) / time.size() + 1;

    long long l = (long long)min_t * avg - 1,
              r = min((long long)max_t * avg, (long long)min_t * totalTrips);
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};

signed main() {
  vector<int> time = {1, 2, 3};
  int totalTrips = 5;
  Solution sol = Solution();
  cout << sol.minimumTime(time, totalTrips) << endl;

  return 0;
}