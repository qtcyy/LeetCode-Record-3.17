#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    int n = arr.size();
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + arr[i - 1];
    }
    int ans = 0;
    for (int i = k - 1; i < n; i++) {
      if ((pre[i + 1] - pre[i - k + 1]) * 1.0 / k >= threshold) {
        ++ans;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> arr = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
  int k = 3, threshold = 5;
  Solution sol;
  cout << sol.numOfSubarrays(arr, k, threshold) << endl;

  return 0;
}