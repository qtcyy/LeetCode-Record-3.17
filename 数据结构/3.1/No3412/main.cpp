#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  long long calculateScore(string s) {
    long long score = 0;
    vector<vector<int>> indices(26);

    for (int i = 0; i < (int)s.size(); ++i) {
      int idx = s[i] - 'a', mirror = 25 - idx;

      if (!indices[mirror].empty()) {
        score += ((long long)i - indices[mirror].back());
        indices[mirror].pop_back();
      } else {
        indices[idx].push_back(i);
      }
    }

    return score;
  }
};

signed main() {
  string s = "aczzx";
  Solution sol = Solution();
  cout << sol.calculateScore(s) << endl;

  return 0;
}