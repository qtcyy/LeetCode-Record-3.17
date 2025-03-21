#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  inline bool check(int x) {
    if (x <= 1) {
      return false;
    }
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        return false;
      }
    }
    return true;
  }

public:
  int maximumPrimeDifference(vector<int> &nums) {
    int n = nums.size();
    int last = -1, first = -1;
    for (int i = 0; i < n; i++) {
      if (check(nums[i])) {
        if (first != -1) {
          last = i;
        } else {
          first = i;
        }
      }
    }
    return (last - first) < 0 ? 0 : (last - first);
  }
};

signed main() {
  vector<int> nums = {4, 2, 9, 5, 3};
  Solution sol = Solution();

  cout << sol.maximumPrimeDifference(nums) << endl;

  return 0;
}