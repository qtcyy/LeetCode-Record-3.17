#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getAverages(vector<int> &nums, int k) {
    int n = nums.size();
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
    vector<int> ans;
    if (k * 2 + 1 > n) {
      return vector<int>(n, -1);
    }
    for (int i = 0; i < k; i++) {
      ans.push_back(-1);
    }
    int len = k * 2 + 1;
    for (int i = len - 1; i < n; i++) {
      ans.push_back((pre[i + 1] - pre[i - len + 1]) / len);
    }
    for (int i = 0; i < k; i++) {
      ans.push_back(-1);
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {7, 4, 3, 9, 1, 8, 5, 2, 6};
  int k = 3;
  Solution sol;
  vector<int> ans = sol.getAverages(nums, k);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}