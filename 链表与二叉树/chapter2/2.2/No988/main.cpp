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
  string smallestFromLeaf(TreeNode *root) {
    string ans;
    for (int i = 0; i < 1e4; i++) {
      ans.push_back('z');
    }
    string s;
    function<void(TreeNode *)> dfs = [&](TreeNode *cur) {
      if (!cur) {
        return;
      }
      s.push_back(cur->val + 'a');
      if (!cur->left && !cur->right) {
        string tmp(s.rbegin(), s.rend());
        ans = min(ans, tmp);
      }
      dfs(cur->left);
      dfs(cur->right);
      s.pop_back();
    };
    dfs(root);

    return ans;
  }
};

signed main() {
  vector<int> node = {25, 1, 3, 1, 3, 0, 2};
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.smallestFromLeaf(root) << endl;

  return 0;
}