#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  inline bool check(int x) {
    if (x <= 1) {
      return false;
    }
    for (int i = 2; i * i <= x; ++i) {
      if (x % i == 0) {
        return false;
      }
    }
    return true;
  }

public:
  int diagonalPrime(vector<vector<int>> &nums) {
    int n = nums.size();
    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (check(nums[i][i])) {
        ans = max(ans, nums[i][i]);
      }
      if (check(nums[i][n - i - 1])) {
        ans = max(ans, nums[i][n - i - 1]);
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> nums = {{1, 2, 3}, {5, 6, 7}, {9, 10, 11}};
  Solution sol = Solution();
  cout << sol.diagonalPrime(nums) << endl;

  return 0;
}