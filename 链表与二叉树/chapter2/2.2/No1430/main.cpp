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
  bool isValidSequence(TreeNode *root, vector<int> &arr) {
    bool flag = false;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *cur, int s) {
      if (!cur || flag) {
        return;
      }
      if (s >= arr.size() || arr[s] != cur->val) {
        return;
      }
      if (!cur->left && !cur->right && s == arr.size() - 1) {
        flag = true;
        return;
      }
      dfs(cur->left, s + 1);
      dfs(cur->right, s + 1);
    };
    dfs(root, 0);

    return flag;
  }
};

signed main() {
  vector<int> root = {0, 1, 0, 0, 1, 0, -1, -1, 1, 0, 0}, arr = {0, 1, 0, 1};
  TreeNode *node = buildTree(root);
  Solution sol;
  cout << (sol.isValidSequence(node, arr) ? "true" : "false") << endl;

  return 0;
}