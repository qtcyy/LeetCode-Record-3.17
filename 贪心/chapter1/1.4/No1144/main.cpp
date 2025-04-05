#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int movesToMakeZigzag(vector<int> &nums) {
    int n = nums.size();
    vector<int> arr(nums);
    int sum = 0, ans = 0;
    for (int i = 1; i < n; i++) {
      if (i & 1 && arr[i] <= arr[i - 1]) {
        ans += arr[i - 1] - arr[i] + 1;
        arr[i] = arr[i - 1] + 1;
      }
      if (!(i & 1) && arr[i] >= arr[i - 1]) {
        ans += arr[i] - arr[i - 1] + 1;
        arr[i] = arr[i - 1] - 1;
      }
    }
    arr = std::move(nums);
    for (int i = 0; i < n - 1; i++) {
      if (!(i & 1) && arr[i] <= arr[i + 1]) {
        sum += arr[i + 1] - arr[i] + 1;
        arr[i + 1] = arr[i] - 1;
      }
      if (i & 1 && arr[i] >= arr[i + 1]) {
        sum += arr[i] - arr[i + 1] - 1;
        arr[i + 1] = arr[i] + 1;
      }
    }
    return min(sum, ans);
  }
};

signed main() {
  vector<int> nums = {9, 6, 1, 6, 2};
  Solution sol;
  cout << sol.movesToMakeZigzag(nums) << endl;

  return 0;
}