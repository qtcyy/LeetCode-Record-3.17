#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck) {
    sort(deck.rbegin(), deck.rend());
    deque<int> dq{deck[0]};
    int n = deck.size();
    for (int i = 1; i < n; i++) {
      dq.push_front(dq.back());
      dq.pop_back();
      dq.push_front(deck[i]);
    }

    return vector<int>(dq.begin(), dq.end());
  }
};

signed main() {
  vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
  Solution sol = Solution();
  vector<int> ans = sol.deckRevealedIncreasing(deck);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}