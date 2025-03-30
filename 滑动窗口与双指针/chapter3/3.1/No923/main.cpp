#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
  int threeSumMulti(vector<int> &arr, int target) {
    int n = arr.size();
    long long ans = 0;
    ranges::sort(arr);
    for (int i = 0; i < n - 2; i++) {
      int k = target - arr[i];
      int left = i + 1, right = n - 1;
      while (left < right) {
        int val = arr[left] + arr[right];
        if (val < k) {

        } else if (val > k) {

        } else {
        }
      }
    }
  }
};

signed main() {
  vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
  int target = 8;
  Solution sol;
  cout << sol.threeSumMulti(arr, target) << endl;

  return 0;
}