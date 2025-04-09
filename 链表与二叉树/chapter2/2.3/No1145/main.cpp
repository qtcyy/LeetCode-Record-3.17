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
  bool btreeGameWinningMove(TreeNode *root, int n, int x) {
    int lsz, rsz;
    function<int(TreeNode *)> dfs = [&](TreeNode *node) {
      if (!node) {
        return 0;
      }
      int left = dfs(node->left), right = dfs(node->right);
      if (node->val == x) {
        lsz = left;
        rsz = right;
      }
      return left + right + 1;
    };
    dfs(root);
    return max({lsz, rsz, n - 1 - lsz - rsz}) * 2 > n;
  }
};

signed main() {
  vector<int> node = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int n = 11, x = 3;
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << (sol.btreeGameWinningMove(root, n, x) ? "true" : "false") << endl;

  return 0;
}