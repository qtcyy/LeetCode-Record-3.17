#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
  Node *son[26]{};
  bool end = false;
};

class Trie {
  Node *root = new Node();

  int find(string &word) {
    Node *cur = root;
    for (char &c : word) {
      c -= 'a';
      if (cur->son[c] == nullptr) {
        return 0;
      }
      cur = cur->son[c];
    }
    return cur->end ? 2 : 1;
  }

public:
  void insert(string &word) {
    Node *cur = root;
    for (char &c : word) {
      c -= 'a';
      if (cur->son[c] == nullptr) {
        cur->son[c] = new Node();
      }
      cur = cur->son[c];
    }
    cur->end = true;
  }

  bool search(string &word) { return find(word) == 2; }

  bool startWith(string &prefix) { return find(prefix) != 0; }
};

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    Trie trie;
    for (auto &word : products) {
      trie.insert(word);
    }
    string cur = "";
    for (char &c : searchWord) {
      cur += c;
    }
  }
};

signed main() {
  vector<string> products = {"mobile", "mouse", "moneypot", "monitor",
                             "mousepad"};
  string searchWord = "mouse";
  Solution sol;
  vector<vector<string>> ans = sol.suggestedProducts(products, searchWord);
  for (auto &row : ans) {
    for (auto &st : row) {
      cout << st << ' ';
    }
    cout << endl;
  }

  return 0;
}