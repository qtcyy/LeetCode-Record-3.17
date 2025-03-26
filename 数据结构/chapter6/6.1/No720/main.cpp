#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie {
private:
  vector<Trie *> children;
  bool isEnd;

public:
  Trie() {
    this->children = vector<Trie *>(26, nullptr);
    this->isEnd = false;
  }

  bool insert(const string &word) {
    Trie *node = this;
    for (const auto &ch : word) {
      int idx = ch - 'a';
      if (node->children[idx] == nullptr) {
        node->children[idx] = new Trie();
      }
      node = node->children[idx];
    }
    node->isEnd = true;
    return true;
  }

  bool find(const string &word) {
    Trie *node = this;
    for (const auto &ch : word) {
      int idx = ch - 'a';
      if (node->children[idx] == nullptr || !node->children[idx]->isEnd) {
        return false;
      }
      node = node->children[idx];
    }
    return node != nullptr && node->isEnd;
  }
};

class Solution {
public:
  string longestWord(vector<string> &words) {
    Trie trie;
    for (auto &word : words) {
      trie.insert(word);
    }
    string ans = "";
    for (auto &word : words) {
      if (trie.find(word)) {
        if (word.size() > ans.size() ||
            (words.size() == ans.size() && word < ans)) {
          ans = word;
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
  Solution sol;
  cout << sol.longestWord(words) << endl;

  return 0;
}