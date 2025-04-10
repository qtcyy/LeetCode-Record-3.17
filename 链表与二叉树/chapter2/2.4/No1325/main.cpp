#include <functional>
#include <iostream>
#include <queue>
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
  TreeNode *removeLeafNodes(TreeNode *root, int target) {
    function<TreeNode *(TreeNode *)> dfs = [&](TreeNode *node) -> TreeNode * {
      if (!node) {
        return nullptr;
      }

      node->left = dfs(node->left);
      node->right = dfs(node->right);

      if (!node->left && !node->right && node->val == target) {
        delete node;
        return nullptr;
      }

      return node;
    };

    return dfs(root);
  }
};

signed main() {
  vector<int> node = {1, 2, 3, 2, -1, 2, 4};
  int target = 2;
  TreeNode *root = buildTree(node);
  Solution sol;
  TreeNode *ans = sol.removeLeafNodes(root, target);

  return 0;
}