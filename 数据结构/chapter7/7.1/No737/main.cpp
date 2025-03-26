#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
  unordered_map<string, string> f;

  string find(string x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]);
  }

  void merge(string x, string y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    f[x] = y;
  }

public:
  bool areSentencesSimilarTwo(vector<string> &sentence1,
                              vector<string> &sentence2,
                              vector<vector<string>> &similarPairs) {
    if (sentence1.size() != sentence2.size()) {
      return false;
    }
    for (string &word : sentence1) {
      f[word] = word;
    }
    for (string &word : sentence2) {
      f[word] = word;
    }
    for (auto &pi : similarPairs) {
      f[pi[0]] = pi[0];
      f[pi[1]] = pi[1];
    }
    int n = sentence1.size();
    for (auto &pi : similarPairs) {
      merge(pi[0], pi[1]);
    }
    for (int i = 0; i < n; i++) {
      if (find(sentence1[i]) != find(sentence2[i])) {
        return false;
      }
    }
    return true;
  }
};

signed main() {
  vector<string> sentence1 = {"great", "acting", "skills"},
                 sentence2 = {"fine", "drama", "talent"};
  vector<vector<string>> similarPairs = {{"great", "good"},
                                         {"fine", "good"},
                                         {"drama", "acting"},
                                         {"skills", "talent"}};
  Solution sol;
  cout << sol.areSentencesSimilarTwo(sentence1, sentence2, similarPairs)
       << endl;
  return 0;
}