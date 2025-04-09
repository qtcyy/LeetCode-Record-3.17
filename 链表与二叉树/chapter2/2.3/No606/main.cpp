#include <algorithm>
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
  string tree2str(TreeNode *root) {
    string ans;
    auto conv = [](int x) -> string {
      if (x == 0) {
        return "0";
      }
      string tmp;
      int p = x;
      x = abs(x);
      while (x) {
        tmp.push_back(x % 10 + '0');
        x /= 10;
      }
      if (p < 0) {
        tmp.push_back('-');
      }
      reverse(tmp.begin(), tmp.end());
      return tmp;
    };
    function<void(TreeNode *)> dfs = [&](TreeNode *node) {
      if (!node) {
        return;
      }
      ans += conv(node->val);
      if (node->left) {
        ans.push_back('(');
        dfs(node->left);
        ans.push_back(')');
      } else if (node->right) {
        ans += "()";
      }
      if (node->right) {
        ans.push_back('(');
        dfs(node->right);
        ans.push_back(')');
      }
    };
    dfs(root);
    return ans;
  }
};

signed main() {
  vector<int> node = {1, 2, 3, 4};
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.tree2str(root) << endl;

  return 0;
}