#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long maximumSum(vector<int> &nums) {
    long long ans = 0;
    int n = nums.size();
    for (int i = 1; i <= n; i++) {
      long long sum = 0;
      for (int j = 1; i * j * j <= n; j++) {
        sum += nums[i * j * j - 1];
      }
      ans = max(ans, sum);
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {8, 10, 3, 8, 1, 13, 7, 9, 4};
  Solution sol;
  cout << sol.maximumSum(nums) << endl;

  return 0;
}