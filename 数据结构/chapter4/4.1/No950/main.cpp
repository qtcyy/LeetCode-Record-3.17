#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck) {}
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