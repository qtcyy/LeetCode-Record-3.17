#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts,
                    long long budget) {
    int n = chargeTimes.size();
    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + runningCosts[i - 1];
    }
    deque<int> deq;
    int left = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      while (!deq.empty() && chargeTimes[deq.back()] < chargeTimes[i]) {
        deq.pop_back();
      }
      deq.push_back(i);
      while (!deq.empty() && chargeTimes[deq.front()] +
                                     (i - left + 1) * (pre[i + 1] - pre[left]) >
                                 budget) {
        if (chargeTimes[left] == chargeTimes[deq.front()]) {
          deq.pop_front();
        }
        left++;
      }
      ans = max(ans, i - left + 1);
    }
    return ans;
  }
};

signed main() {
  vector<int> chargeTimes = {3, 6, 1, 3, 4}, runningCosts = {2, 1, 3, 4, 5};
  int budget = 25;
  Solution sol = Solution();
  cout << sol.maximumRobots(chargeTimes, runningCosts, budget) << endl;

  return 0;
}