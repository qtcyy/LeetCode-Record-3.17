#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
  int bricks, ladders;
  inline bool check(const int &mid, vector<int> needs) {
    priority_queue<pair<int, int>> q;
    for (int i = 1; i < mid; i++) {
      q.push(make_pair(needs[i], i));
    }
    int cnt = this->ladders;
    while (cnt && !q.empty()) {
      auto [_, pos] = q.top();
      q.pop();
      needs[pos] = 0;
      --cnt;
    }
    int sum = 0;
    for (int i = 1; i < mid; i++) {
      sum += needs[i];
    }
    return sum <= this->bricks;
  }

public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    this->bricks = bricks;
    this->ladders = ladders;
    int n = heights.size();
    vector<int> needs(n, 0);
    for (int i = 1; i < n; i++) {
      if (heights[i] > heights[i - 1]) {
        needs[i] = heights[i] - heights[i - 1];
      }
    }
    int l = 1, r = n + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid, needs)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l - 1;
  }
};

signed main() {
  vector<int> heights = {14, 3, 19, 3};
  int bricks = 17, ladders = 0;
  Solution sol = Solution();
  cout << sol.furthestBuilding(heights, bricks, ladders) << endl;

  return 0;
}