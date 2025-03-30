#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getStrongest(vector<int> &arr, int k) {
    int n = arr.size();
    int left = 0, right = n - 1;
    vector<int> ans;
    ranges::sort(arr);
    int m = arr[(n - 1) / 2];
    while (left < right && ans.size() < k) {
      if (abs(arr[left] - m) <= abs(arr[right] - m)) {
        ans.push_back(arr[right--]);
      } else {
        ans.push_back(arr[left++]);
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> arr = {6, 7, 11, 7, 6, 8};
  int k = 5;
  Solution sol;
  vector<int> ans = sol.getStrongest(arr, k);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}