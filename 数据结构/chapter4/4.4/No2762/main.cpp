#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long continuousSubarrays(vector<int> &nums) {
    int n = nums.size();
    deque<int> deqmn, deqmx;
    int left = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      while (!deqmn.empty() && nums[deqmn.back()] > nums[i]) {
        deqmn.pop_back();
      }
      while (!deqmx.empty() && nums[deqmx.back()] < nums[i]) {
        deqmx.pop_back();
      }
      deqmn.push_back(i);
      deqmx.push_back(i);
      while (!deqmn.empty() && !deqmx.empty() &&
             nums[deqmx.front()] - nums[deqmn.front()] > 2) {
        if (nums[left] == nums[deqmn.front()]) {
          deqmn.pop_front();
        }
        if (nums[left] == nums[deqmx.front()]) {
          deqmx.pop_front();
        }
        left++;
      }
      ans += i - left + 1;
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {5, 4, 2, 4};
  Solution sol = Solution();
  cout << sol.continuousSubarrays(nums) << endl;

  return 0;
}