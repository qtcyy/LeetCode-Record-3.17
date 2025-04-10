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
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    int mx = -1;
    TreeNode *res;
    function<int(TreeNode *, int)> dfs = [&](TreeNode *node, int deep) {
      if (!node) {
        mx = max(mx, deep);
        return deep;
      }
      int left = dfs(node->left, deep + 1);
      int right = dfs(node->right, deep + 1);
      if (left == mx & right == mx) {
        res = node;
      }
      return max(left, right);
    };
    dfs(root, 0);
    return res;
  }
};

signed main() { vector<int> node = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4}; }