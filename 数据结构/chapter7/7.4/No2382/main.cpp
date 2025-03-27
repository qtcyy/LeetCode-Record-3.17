#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> f;

  int find(int x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]);
  }

public:
  vector<long long> maximumSegmentSum(vector<int> &nums,
                                      vector<int> &removeQueries) {
    int n = nums.size();
    f.resize(n + 1);
    iota(f.begin(), f.end(), 0);
    vector<long long> ans(n), sum(n + 1, 0);
    ans[n] = 0;
    for (int i = n - 1; i > 0; i--) {
      int x = removeQueries[i];
      int to = find(x + 1);
      sum[to] += sum[x] + nums[x];
      f[x] = to;
      ans[i - 1] = max(ans[i], sum[to]);
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 2, 5, 6, 1}, removeQueries = {0, 3, 2, 4, 1};
  Solution sol;
  vector<long long> ans = sol.maximumSegmentSum(nums, removeQueries);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}