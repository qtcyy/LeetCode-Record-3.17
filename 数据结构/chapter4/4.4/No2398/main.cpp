#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts,
                    long long budget) {}
};

signed main() {
  vector<int> chargeTimes = {3, 6, 1, 3, 4}, runningCosts = {2, 1, 3, 4, 5};
  int budget = 25;
  Solution sol = Solution();
  cout << sol.maximumRobots(chargeTimes, runningCosts, budget) << endl;

  return 0;
}