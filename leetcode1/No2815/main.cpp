#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSum(vector<int> &nums) {
    map<int, priority_queue<int>> mp;
    int n = nums.size();
    auto getmax = [](int x) {
      int maxn = 0;
      while (x) {
        maxn = max(maxn, x % 10);
        x /= 10;
      }
      return maxn;
    };

    for (auto &num : nums) {
      int maxn = getmax(num);
      mp[maxn].push(num);
    }
    int ans = -1;
    for (auto &&[_, que] : mp) {
      if (que.size() <= 1) {
        continue;
      }
      int temp = que.top();
      que.pop();
      ans = max(ans, temp + que.top());
      que.push(temp);
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 2, 3, 4};
  Solution sol = Solution();
  cout << sol.maxSum(nums) << endl;

  return 0;
}