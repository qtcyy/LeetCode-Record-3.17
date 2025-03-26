#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size();
    vector<tuple<int, int, int>> arr;
    for (int i = 0; i < n; i++) {
      arr.emplace_back(nums1[i], nums2[i], i);
    }
    ranges::sort(arr);
    vector<long long> ans(n);
    priority_queue<int, vector<int>, greater<>> pq;
    long long s = 0;
    for (int i = 0; i < n; i++) {
      auto &[x, y, idx] = arr[i];
      ans[idx] = i > 0 && x == get<0>(arr[i - 1]) ? ans[get<2>(arr[i - 1])] : s;
      s += y;
      pq.push(y);
      if (pq.size() > k) {
        s -= pq.top();
        pq.pop();
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums1 = {4, 2, 1, 5, 3}, nums2 = {10, 20, 30, 40, 50};
  int k = 2;
  Solution sol = Solution();
  vector<long long> ans = sol.findMaxSum(nums1, nums2, k);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}