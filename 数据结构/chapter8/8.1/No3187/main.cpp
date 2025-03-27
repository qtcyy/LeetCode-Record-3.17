#include <iostream>
#include <vector>
using namespace std;

class Fenwick {
  vector<int> sum;
  int n;

  inline int lowbit(int &x) { return x & (-x); }

public:
  Fenwick(int n) : sum(n), n(n) {}

  void update(int i, int k) {
    while (i < n) {
      sum[i] += k;
      i += lowbit(i);
    }
  }

  inline int query(int i) {
    int res = 0;
    while (i > 0) {
      res += sum[i];
      i -= lowbit(i);
    }
    return res;
  }
};

class Solution {
public:
  vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    Fenwick f(n);
    auto update = [&](const int &i, const int &val) {
      if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
        f.update(i, val);
      }
    };
    for (int i = 1; i < n - 1; i++) {
      update(i, 1);
    }
    vector<int> ans;
    for (auto &q : queries) {
      if (q[0] == 1) {
        if (q[2] - 1 < q[1]) {
          ans.push_back(0);
        } else {
          ans.push_back(f.query(q[2] - 1) - f.query(q[1]));
        }
      } else {
        int i = q[1];
        for (int j = max(1, i - 1); j <= min(n - 2, i + 1); j++) {
          update(i, -1);
        }
        nums[i] = q[2];
        for (int j = max(1, i - 1); j <= min(n - 2, i + 1); j++) {
          update(i, 1);
        }
      }
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {4, 1, 4, 2, 1, 5};
  vector<vector<int>> queries = {{2, 2, 4}, {1, 0, 2}, {1, 0, 4}};
  Solution sol;
  vector<int> ans = sol.countOfPeaks(nums, queries);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}