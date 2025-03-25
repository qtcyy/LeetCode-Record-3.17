#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxKelements(vector<int> &nums, int k) {
    priority_queue<int> pq;
    for (auto &x : nums) {
      pq.push(x);
    }
    long long ans = 0;
    while (k--) {
      int val = pq.top();
      ans += val;
      pq.pop();
      pq.push(ceil(1.0 * val / 3));
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 10, 3, 3, 3};
  int k = 3;
  Solution sol = Solution();
  cout << sol.maxKelements(nums, k) << endl;

  return 0;
}