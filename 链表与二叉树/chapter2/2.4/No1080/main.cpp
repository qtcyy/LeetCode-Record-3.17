#include <functional>
#include <iostream>
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
public:
  TreeNode *sufficientSubset(TreeNode *root, int limit) {
    function<TreeNode *(TreeNode *, int)> dfs = [&](TreeNode *node,
                                                    int sum) -> TreeNode * {
      if (node->left == node->right) {
        if (sum + node->val < limit)
          return nullptr;
        else
          return node;
      }
      if (node->left)
        node->left = dfs(node->left, sum + node->val);
      if (node->right)
        node->right = dfs(node->right, sum + node->val);
      if (!node->left && !node->right) {
        return nullptr;
      }
      return node;
    };
    return dfs(root, 0);
  }
};

signed main() {
  vector<int> node = {1, 2, 3, 4, -99, -99, 7, 8, 9, -99, -99, 12, 13, -99, 14};
  TreeNode *root = buildTree(node);
  Solution sol;
  sol.sufficientSubset(root, 1);

  return 0;
}