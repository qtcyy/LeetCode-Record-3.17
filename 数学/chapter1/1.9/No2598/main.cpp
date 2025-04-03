#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int findSmallestInteger(vector<int> &nums, int value) {
    unordered_map<int, int> cnt;
    for (auto &x : nums) {
      ++cnt[(x % value + value) % value];
    }
    int mex = 0;
    while (cnt[mex % value]--) {
      ++mex;
    }
    return mex;
  }
};

signed main() {
  Solution sol;
  vector<int> nums = {1, -10, 7, 13, 6, 8};
  int value = 5;
  cout << sol.findSmallestInteger(nums, value) << endl;
}