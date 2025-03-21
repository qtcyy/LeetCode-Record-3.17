#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {
    unordered_set<char> uni;
    vector<char> uno = {'a', 'e', 'i', 'o', 'u'};
    for (char &ch : uno) {
      uni.insert(ch);
    }
    int n = words.size();
    vector<int> count(n);
    for (int i = 0; i < n; ++i) {
      string word = words[i];
      if (uni.contains(*word.begin()) && uni.contains(*(word.end() - 1))) {
        count[i] = 1;
      }
    }
    partial_sum(count.begin(), count.end(), count.begin());
    vector<int> res;
    for (auto &q : queries) {
      res.push_back(count[q[1]] - (q[0] == 0 ? 0 : count[q[0] - 1]));
    }
    return res;
  }
};

signed main() {
  vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
  vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
  Solution sol = Solution();
  vector<int> ans = sol.vowelStrings(words, queries);
  for (auto &num : ans) {
    cout << num << ' ';
  }
  cout << endl;

  return 0;
}