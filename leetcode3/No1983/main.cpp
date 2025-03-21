#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int widestPairOfIndices(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    nums1.insert(nums1.begin(), 0);
    nums2.insert(nums2.begin(), 0);
    for (int i = 1; i <= n; i++) {
      nums1[i] += nums1[i - 1];
      nums2[i] += nums2[i - 1];
      cout << nums1[i] << ' ' << nums2[i] << endl;
    }
    unordered_map<int, int> recorder = {{0, 0}};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int val = nums1[i] - nums2[i];
      if (recorder.contains(val)) {
        ans = max(ans, i - recorder[val]);
      } else {
        recorder[val] = i;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums1 = {0, 1, 1}, nums2 = {1, 0, 1};
  Solution sol = Solution();
  cout << sol.widestPairOfIndices(nums1, nums2) << endl;

  return 0;
}