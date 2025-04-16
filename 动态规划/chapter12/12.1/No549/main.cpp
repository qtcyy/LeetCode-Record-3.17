#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// 根据层序遍历数组构建二叉树，-1表示空节点
TreeNode *buildTree(vector<int> &nums) {
  if (nums.empty() || nums[0] == -1)
    return nullptr;

  TreeNode *root = new TreeNode(nums[0]);
  queue<TreeNode *> q;
  q.push(root);

  int i = 1;
  while (!q.empty() && i < nums.size()) {
    TreeNode *curr = q.front();
    q.pop();

    // 处理左子节点
    if (i < nums.size()) {
      if (nums[i] != -1) {
        curr->left = new TreeNode(nums[i]);
        q.push(curr->left);
      }
      i++;
    }

    // 处理右子节点
    if (i < nums.size()) {
      if (nums[i] != -1) {
        curr->right = new TreeNode(nums[i]);
        q.push(curr->right);
      }
      i++;
    }
  }

  return root;
}

class Solution {
  int ans = 0;

  pair<int, int> dfs(TreeNode *node) {
    if (!node) {
      return {0, 0};
    }
    int dec = 1, inc = 1;
    if (node->left) {
      auto [leftDec, leftInc] = dfs(node->left);
      if (node->val == node->left->val + 1) {
        inc = max(inc, leftInc + 1);
      }
      if (node->val == node->left->val - 1) {
        dec = max(dec, leftDec + 1);
      }
    }
    if (node->right) {
      auto [rightDec, rightInc] = dfs(node->right);
      if (node->val == node->right->val + 1) {
        inc = max(inc, rightInc + 1);
      }
      if (node->val == node->right->val - 1) {
        dec = max(dec, rightDec + 1);
      }
    }
    ans = max(ans, inc + dec - 1);

    return {dec, inc};
  }

public:
  int longestConsecutive(TreeNode *root) {
    dfs(root);
    return ans;
  }
};

signed main() {
  vector<int> node = {2, 1, 3};
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.longestConsecutive(root) << endl;

  return 0;
}