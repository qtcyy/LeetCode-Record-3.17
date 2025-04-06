#include <iostream>
#include <numeric>
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

void printList(ListNode *head) {
  ListNode *cur = head;
  while (cur) {
    cout << cur->val << ' ';
    cur = cur->next;
  }
}

class Solution {
public:
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    ListNode *cur = head;
    while (cur->next) {
      int x = cur->val, y = cur->next->val;
      int d = gcd(x, y);
      ListNode *newNode = new ListNode(d);
      newNode->next = cur->next;
      cur->next = newNode;
      cur = newNode->next;
    }
    return head;
  }
};

signed main() {
  vector<int> head = {18, 6, 10, 3};
  ListNode *node = construct(head);
  Solution sol;
  ListNode *ans = sol.insertGreatestCommonDivisors(node);
  printList(ans);

  return 0;
}