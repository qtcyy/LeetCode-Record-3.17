#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    int k = nums.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < k; i++) {
      for (auto &x : nums[i]) {
        arr.push_back(make_pair(x, i));
      }
    }
    sort(arr.begin(), arr.end());
    int n = arr.size();
    unordered_map<int, int> cnt;
    int left = 0;
    pair<int, int> ans = make_pair(arr[0].first, arr.back().first);
    for (int i = 0; i < n; i++) {
      ++cnt[arr[i].second];
      int len = n + 2;
      while (cnt.size() >= k) {
        len = min(len, i - left + 1);
        if (!--cnt[arr[left].second]) {
          cnt.erase(arr[left].second);
        }
        ++left;
      }

      if (len != n + 2) {
        pair<int, int> temp = make_pair(arr[i - len + 1].first, arr[i].first);

        if (temp.second - temp.first < ans.second - ans.first) {
          ans = temp;
        }
      }
    }

    vector<int> res(2);
    res[0] = ans.first;
    res[1] = ans.second;
    return res;
  }
};

signed main() {
  vector<vector<int>> nums = {
      {4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
  Solution sol;
  vector<int> ans = sol.smallestRange(nums);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}