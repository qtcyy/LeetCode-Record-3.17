#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int movesToMakeZigzag(vector<int> &nums) {
    int n = nums.size();
    vector<int> arr(nums);
    // 小大小
    arr.insert(arr.begin(), INT_MAX);
    if (n & 1) {
      arr.push_back(INT_MAX);
    }
    int sum = 0, ans = 0;
    for (int i = 1; i <= n; i += 2) {
      int mn = min(arr[i - 1], arr[i + 1]);
      if (arr[i] >= mn) {
        sum += arr[i] - mn + 1;
        arr[i] = mn - 1;
      }
    }
    // 大小大
    nums.insert(nums.begin(), INT_MAX);
    if (n % 2 == 0) {
      nums.push_back(INT_MAX);
    }
    for (int i = 2; i <= n; i += 2) {
      int mn = min(nums[i - 1], nums[i + 1]);
      if (arr[i] >= mn) {
        ans += nums[i] - mn + 1;
        nums[i] = mn - 1;
      }
    }
    return min(ans, sum);
  }
};

signed main() {
  vector<int> nums = {9, 6, 1, 6, 2};
  Solution sol;
  cout << sol.movesToMakeZigzag(nums) << endl;

  return 0;
}