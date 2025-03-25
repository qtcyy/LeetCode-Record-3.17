#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int shortestSubarray(vector<int> &nums, int k) {
    int n = nums.size();
    deque<int> deq;
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
    for (int i = 0; i <= n; i++) {
      cout << pre[i] << ' ';
    }
    cout << endl;
    int left = 0, ans = n + 1;
    for (int i = 0; i < n; i++) {
      while (!deq.empty() && pre[deq.back()] > pre[i]) {
        deq.pop_back();
      }
      deq.push_back(i);
      while (!deq.empty() && pre[i + 1] - pre[deq.front()] >= k && left <= i) {
        if (pre[left] == pre[deq.front()]) {
          deq.pop_front();
        }
        left++;
      }
      if (pre[i + 1] - pre[max(left - 1, 0)] >= k) {
        cout << i << ' ' << left << endl;
        ans = min(ans, i - left + 2);
      }
    }
    return ans == n + 1 ? -1 : ans;
  }
};

signed main() {
  vector<int> nums = {1};
  int k = 1;
  Solution sol = Solution();
  cout << sol.shortestSubarray(nums, k) << endl;

  return 0;
}