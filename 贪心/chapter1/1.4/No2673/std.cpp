#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minIncrements(int n, vector<int> &cost) {
    int operations = 0;

    // Process from bottom to top (excluding the root node)
    for (int i = n / 2; i > 0; i--) {
      int leftChild = 2 * i;
      int rightChild = 2 * i + 1;

      // If right child exceeds n, we don't have a right child (but this won't
      // happen in a full binary tree)
      if (rightChild <= n) {
        // Calculate the difference between the path sums of the two children
        int diff = abs(cost[leftChild - 1] - cost[rightChild - 1]);

        // Add the difference to the operations count
        operations += diff;

        // Update the parent node's value by adding the maximum path sum from
        // its children
        cost[i - 1] += max(cost[leftChild - 1], cost[rightChild - 1]);
      }
    }

    return operations;
  }
};

signed main() {
  int n = 7;
  vector<int> cost = {1, 5, 2, 2, 3, 3, 1};
  Solution sol;
  cout << sol.minIncrements(n, cost) << endl;

  return 0;
}