#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numOfSubarrays(vector<int> &arr) {
    int n = arr.size();
    arr.insert(arr.begin(), 0);
    for (int i = 1; i <= n; ++i) {
      arr[i] += arr[i - 1];
    }
    long long ans = 0;
    const int mod = 1e9 + 7;
    int odd = 0, even = 1;
    for (int i = 1; i <= n; ++i) {
      if (arr[i] & 1) {
        ans += even;
        ++odd;
      } else {
        ans += odd;
        ++even;
      }
    }
    return ans % mod;
  }
};

signed main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  Solution sol = Solution();
  cout << sol.numOfSubarrays(arr) << endl;

  return 0;
}