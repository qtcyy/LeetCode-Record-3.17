#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long makeSimilar(vector<int> &nums, vector<int> &target) {
    auto process = [](vector<int> &arr) {
      for (int &x : arr) {
        if (x & 1)
          x = -x;
      }
      ranges::sort(arr);
    };
    process(nums);
    process(target);
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += abs(nums[i] - target[i]);
    }
    return sum / 4;
  }
};

signed main() {
  vector<int> nums = {8, 12, 6}, target = {2, 14, 10};
  Solution sol;
  cout << sol.makeSimilar(nums, target) << endl;

  return 0;
}