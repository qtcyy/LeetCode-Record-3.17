#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution2 {
public:
  vector<long long> distance(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> groups;
    for (int i = 0; i < n; ++i)
      groups[nums[i]].push_back(i);

    vector<long long> ans(n);
    long long s[n + 1];
    s[0] = 0;
    for (auto &[_, a] : groups) {
      int m = a.size();
      for (int i = 0; i < m; ++i)
        s[i + 1] = s[i] + a[i];
      for (int i = 0; i < m; ++i) {
        long long target = a[i];
        long long left = target * i - s[i];
        long long right = s[m] - s[i] - target * (m - i);
        ans[target] = left + right;
      }
    }
    return ans;
  }
};

class Solution {
public:
  vector<long long> distance(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, vector<long long>> cnt;
    for (int i = 0; i < n; i++) {
      cnt[nums[i]].push_back(i);
    }
    vector<long long> ans(n);
    vector<long long> pre(n + 1, 0);
    for (auto &&[_, arr] : cnt) {
      int n = arr.size();
      for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + arr[i];
      }
      for (int i = 0; i < n; i++) {
        long long target = arr[i];
        long long left = target * i - pre[i];
        long long right = pre[n] - pre[i + 1] - target * (n - i - 1);
        ans[target] = left + right;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 3, 1, 1, 2};
  Solution sol = Solution();
  vector<long long> ans = sol.distance(nums);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  return 0;
}