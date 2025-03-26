#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct trie {
  int nex[1000000][26], cnt;
  bool exist[1000000];

  void insert(string &s) {
    int p = 0, n = s.length();
    for (int i = 0; i < n; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c])
        nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    exist[p] = true;
  }

  bool find(string &s) {
    int p = 0, n = s.length();
    for (int i = 0; i < n; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c])
        return false;
      p = nex[p][c];
    }
    return true;
  }
};

class Solution {
public:
  string replaceWords(vector<string> &dictionary, string sentence) {
    trie t;
    for (auto &dic : dictionary) {
      t.insert(dic);
    }
  }
};

signed main() {
  vector<string> dictionary = {"cat", "bat", "rat"};
  string sentence = "the cattle was rattled by the battery";
  Solution sol = Solution();
  cout << sol.replaceWords(dictionary, sentence) << endl;

  return 0;
}