#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxArrayValue(vector<int> &nums) {
    int n = nums.size();
    vector<long long> arr;
    for (auto &x : nums) {
      arr.emplace_back(x);
    }
    for (int i = n - 2; i >= 0; i--) {
      if (arr[i] <= arr[i + 1]) {
        arr[i] += arr[i + 1];
      }
    }
    return ranges::max(arr);
  }
};

signed main() {
  vector<int> nums = {2, 3, 7, 9, 3};
  Solution sol;
  cout << sol.maxArrayValue(nums) << endl;

  return 0;
}