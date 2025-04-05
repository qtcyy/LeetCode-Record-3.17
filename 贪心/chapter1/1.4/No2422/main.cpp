#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int n = nums.size();
    int i = 0, j = n - 1;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
      arr[i] = nums[i];
    }

    int ans = 0;
    while (i < j) {
      if (arr[i] == arr[j]) {
        ++i;
        --j;
      } else if (arr[i] > arr[j]) {
        arr[j - 1] += arr[j];
        --j;
        ++ans;
      } else {
        arr[i + 1] += arr[i];
        ++i;
        ++ans;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {4, 3, 2, 1, 2, 3, 1};
  Solution sol;
  cout << sol.minimumOperations(nums) << endl;

  return 0;
}