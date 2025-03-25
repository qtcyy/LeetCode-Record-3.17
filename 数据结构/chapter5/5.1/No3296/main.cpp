#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
    priority_queue<tuple<long long, long long, int>,
                   vector<tuple<long long, long long, int>>, greater<>>
        pq;
    for (auto &t : workerTimes) {
      pq.emplace(t, t, t);
    }

    long long ans = 0;
    while (mountainHeight--) {
      auto [now, delta, base] = pq.top();
      pq.pop();
      ans = now;
      pq.emplace(now + delta + base, delta + base, base);
    }

    return ans;
  }
};

signed main() {
  int mountainHeight = 10;
  vector<int> workerTimes = {3, 2, 2, 4};
  Solution sol = Solution();
  cout << sol.minNumberOfSeconds(mountainHeight, workerTimes) << endl;

  return 0;
}