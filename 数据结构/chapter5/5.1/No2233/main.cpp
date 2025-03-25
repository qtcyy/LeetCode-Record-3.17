#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
  int maximumProduct(vector<int> &nums, int k) {
    /**
    a<b
    (a+k)*b=ab+b*k
    a*(b+k)=ab+a*k
    */
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &x : nums) {
      pq.push(x);
    }
    long long ans = 1;
    while (k--) {
      int val = pq.top();
      pq.pop();
      val++;
      pq.push(val);
    }
    while (!pq.empty()) {
      ans = (ans * pq.top()) % mod;
      pq.pop();
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {6, 3, 3, 2};
  int k = 2;
  Solution sol = Solution();
  cout << sol.maximumProduct(nums, k) << endl;

  return 0;
}