#include <climits>
#include <cmath>
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
  int minDepth(TreeNode *root) {
    int mn = INT_MAX;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *cur, int deep) {
      if (!cur) {
        return;
      }
      if (!cur->left && !cur->right) {
        mn = min(mn, deep);
      }
      dfs(cur->left, deep + 1);
      dfs(cur->right, deep + 1);
    };
    dfs(root, 1);
    return mn >= INT_MAX ? 0 : mn;
  }
};

signed main() {
  vector<int> node = {3, 9, 20, -1, -1, 15, 7};
  Solution sol;
  TreeNode *root = buildTree(node);
  cout << sol.minDepth(root) << endl;

  return 0;
}