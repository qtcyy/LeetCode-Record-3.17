#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int magicTower(vector<int> &nums) {
    if (accumulate(nums.begin(), nums.end(), 0ll) < 0) {
      return -1;
    }
    priority_queue<int> pq;
    long long hp = 1, ans = 0;
    for (auto &x : nums) {
      if (x < 0) {
        pq.push(-x);
      }
      hp += x;
      if (hp < 1) {
        hp += pq.top();
        pq.pop();
        ++ans;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {100, 100, 100, -250, -60, -140, -50, -50, 100, 150};
  Solution sol = Solution();
  cout << sol.magicTower(nums) << endl;
  return 0;
}