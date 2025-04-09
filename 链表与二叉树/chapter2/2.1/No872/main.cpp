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
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> arr1, arr2;
    function<void(TreeNode *)> dfs1 = [&](TreeNode *cur) {
      if (!cur) {
        return;
      }
      if (!cur->left && !cur->right) {
        arr1.push_back(cur->val);
      }
      dfs1(cur->left);
      dfs1(cur->right);
    };
    function<void(TreeNode *)> dfs2 = [&](TreeNode *cur) {
      if (!cur) {
        return;
      }
      if (!cur->left && !cur->right) {
        arr2.push_back(cur->val);
      }
      dfs2(cur->left);
      dfs2(cur->right);
    };
    dfs1(root1);
    dfs2(root2);
    int n = arr1.size();
    if (n != arr2.size()) {
      return false;
    }
    for (int i = 0; i < n; i++) {
      if (arr1[i] != arr2[i]) {
        return false;
      }
    }
    return true;
  }
};

signed main() {
  vector<int> root1 = {3, 5, 1, 6, 2, 9, 8, -1, -1, 7, 4};
  TreeNode *tree1 = buildTree(root1);
  vector<int> root2 = {3, 5, 1, 6, 7, 4, 2, -1, -1, -1, -1, -1, -1, 9, 8};
  TreeNode *tree2 = buildTree(root2);
  Solution sol;
  cout << (sol.leafSimilar(tree1, tree2) ? "true" : "false") << endl;

  return 0;
}