#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int maxNonOverlapping(vector<int> &nums, int target) {
    // pre[i]-pre[j-1]=target
    // pre[i]-target=pre[j-1] [i-j] pos=j-1
    // len=i-pos
    int n = nums.size();
    nums.insert(nums.begin(), 0);
    for (int i = 1; i <= n; i++) {
      nums[i] += nums[i - 1];
    }
    unordered_set<int> cnt = {0};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int val = nums[i] - target;
      if (cnt.contains(val)) {
        ans++;
        cnt.clear();
      }
      cnt.insert(nums[i]);
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {-1, 3, 5, 1, 4, 2, -9};
  int target = 6;
  Solution sol = Solution();
  cout << sol.maxNonOverlapping(nums, target) << endl;

  return 0;
}