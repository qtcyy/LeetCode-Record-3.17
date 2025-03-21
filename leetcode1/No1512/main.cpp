#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] == nums[j]) {
          ans++;
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 2, 3, 1, 1, 3};
  Solution sol = Solution();
  cout << sol.numIdenticalPairs(nums) << endl;

  return 0;
}