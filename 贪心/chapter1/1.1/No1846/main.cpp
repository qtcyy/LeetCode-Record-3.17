#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    ranges::sort(arr);
    arr[0] = 1;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
      if (arr[i] - arr[i - 1] > 1) {
        arr[i] = arr[i - 1] + 1;
      }
    }
    return arr.back();
  }
};

signed main() {
  vector<int> arr = {2, 2, 1, 2, 1};
  Solution sol;
  cout << sol.maximumElementAfterDecrementingAndRearranging(arr) << endl;

  return 0;
}