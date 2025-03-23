#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> arr(n + 1);
    for (auto &q : queries) {
      arr[q[0]]++;
      arr[q[1] + 1]--;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
      if (nums[i] > sum) {
        return false;
      }
    }

    return true;
  }
};

signed main() {
  vector<int> nums = {1, 0, 1};
  vector<vector<int>> queries = {{0, 2}};
  Solution sol = Solution();
  cout << sol.isZeroArray(nums, queries) << endl;

  return 0;
}