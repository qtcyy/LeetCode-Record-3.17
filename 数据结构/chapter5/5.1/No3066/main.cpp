#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (auto &x : nums) {
      pq.push(x);
    }
    int sum = 0;
    while (pq.top() < k) {
      long long x = pq.top();
      pq.pop();
      long long y = pq.top();
      pq.pop();
      pq.push(x * 2 + y);
      ++sum;
    }
    return sum;
  }
};

signed main() {
  vector<int> nums = {1, 1, 2, 4, 9};
  int k = 20;
  Solution sol = Solution();
  cout << sol.minOperations(nums, k) << endl;

  return 0;
}