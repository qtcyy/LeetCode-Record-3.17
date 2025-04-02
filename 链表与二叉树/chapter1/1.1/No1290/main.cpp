#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *construct(const vector<int> &arr) {
  ListNode dummy(0);
  ListNode *cur = &dummy;
  for (auto &x : arr) {
    cur->next = new ListNode(x);
    cur = cur->next;
  }
  return dummy.next;
}

class Solution {
public:
  int getDecimalValue(ListNode *head) {
    vector<bool> arr;
    ListNode *cur = head;
    while (cur) {
      if (cur->val) {
        arr.push_back(true);
      } else {
        arr.push_back(false);
      }
      cur = cur->next;
    }
    int n = arr.size(), sum = 1, ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (arr[i]) {
        ans |= sum;
      }
      sum <<= 1;
    }
    return ans;
  }
};

signed main() {
  vector<int> head = {1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
  ListNode *node = construct(head);
  Solution sol;
  cout << sol.getDecimalValue(node) << endl;

  return 0;
}