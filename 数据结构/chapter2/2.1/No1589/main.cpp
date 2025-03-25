#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests) {
    int n = nums.size();
    vector<int> arr(n + 1, 0);
    for (auto &pos : requests) {
      arr[pos[0]]++;
      arr[pos[1] + 1]--;
    }
    for (int i = 1; i <= n; i++) {
      arr[i] += arr[i - 1];
    }
    priority_queue<int> q(nums.begin(), nums.end());
    ranges::sort(arr, [](const int &p1, const int &p2) { return p1 > p2; });
    const int mod = 1e9 + 7;
    long long ans = 0;
    for (auto &x : arr) {
      ans += 1ll * q.top() * x;
      q.pop();
      ans %= mod;
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  vector<vector<int>> requests = {{1, 3}, {0, 1}};
  Solution sol = Solution();
  cout << sol.maxSumRangeQuery(nums, requests) << endl;

  return 0;
}