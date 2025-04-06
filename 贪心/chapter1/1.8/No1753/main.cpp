#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
  int maximumScore(int a, int b, int c) {
    priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int ans = 0;
    while (pq.size() >= 2) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      ++ans;
      --a;
      --b;
      if (a) {
        pq.push(a);
      }
      if (b) {
        pq.push(b);
      }
    }
    if (pq.empty())
      return ans;
    else
      return ans + pq.top();
  }
};

class Solution2 {
public:
  int maximumScore(int a, int b, int c) {
    int sum = a + b + c;
    int mx = max({a, b, c});
    if (sum - mx < mx) {
      return sum - mx;
    } else {
      return sum / 2;
    }
  }
};

signed main() {
  int a = 4, b = 4, c = 6;
  Solution2 sol;
  cout << sol.maximumScore(a, b, c) << endl;

  return 0;
}