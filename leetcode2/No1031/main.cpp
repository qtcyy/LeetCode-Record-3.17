#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    int n = nums.size();
    nums.insert(nums.begin(), 0);
    vector<int> presum(n, 0);
    for (int i = 1; i <= n; i++) {
      presum[i] = presum[i - 1] + nums[i];
    }
  }
};

signed main() {
  vector<int> nums = {0, 6, 5, 2, 2, 5, 1, 9, 4};
  Solution sol = Solution();
  cout << sol.maxSumTwoNoOverlap(nums, 1, 2) << endl;

  return 0;
}