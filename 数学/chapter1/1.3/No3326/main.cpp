#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 5;

vector<int> LFP(N);

auto calc = [] {
  for (int i = 2; i < N; i++) {
    if (!LFP[i]) {
      for (int j = i; j < N; j += i) {
        if (!LFP[j])
          LFP[j] = i;
      }
    }
  }
  return 0;
}();

class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] > nums[i + 1]) {
        nums[i] = LFP[nums[i]];
        if (nums[i] > nums[i + 1]) {
          return -1;
        }
        ++ans;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {25, 7};
  Solution sol;
  cout << sol.minOperations(nums) << endl;

  return 0;
}