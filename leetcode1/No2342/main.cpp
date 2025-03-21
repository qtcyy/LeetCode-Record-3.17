#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumSum(vector<int> &nums) {
    map<int, priority_queue<int>> mp;
    int n = nums.size();
    auto getsum = [](int x) {
      int sum = 0;
      while (x) {
        sum += x % 10;
        x /= 10;
      }
      return sum;
    };

    for (auto &num : nums) {
      int sum = getsum(num);
      mp[sum].push(num);
    }
    int ans = -1;
    for (auto &&[_, que] : mp) {
      if (que.size() <= 1) {
        continue;
      }
      int tmp = que.top();
      que.pop();
      ans = max(ans, tmp + que.top());
      que.push(tmp);
    }
    return ans;
  }
};

signed main() {
  Solution sol = Solution();
  vector<int> nums = {18, 43, 36, 13, 7};
  cout << sol.maximumSum(nums) << endl;

  return 0;
}