#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int halveArray(vector<int> &nums) {
    priority_queue<double> pq;
    long long sum = 0;
    int cnt = 0;
    for (auto &x : nums) {
      pq.push(x);
      sum += x;
    }
    double cal = 0, base = sum / 2.0;
    while (cal < base) {
      double val = pq.top();
      pq.pop();
      val /= 2.0;
      cal += val;
      pq.push(val);
      cnt++;
    }
    return cnt;
  }
};

signed main() {
  vector<int> nums = {1};
  Solution sol = Solution();
  cout << sol.halveArray(nums) << endl;

  return 0;
}