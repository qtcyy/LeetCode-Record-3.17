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
  vector<int> rightSideView(TreeNode *root) {
    vector<vector<int>> p;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *cur, int deep) {
      if (!cur) {
        return;
      }
      if (p.size() <= deep) {
        p.push_back({cur->val});
      } else {
        p[deep].push_back(cur->val);
      }
      dfs(cur->left, deep + 1);
      dfs(cur->right, deep + 1);
    };
    dfs(root, 0);
    vector<int> ans;
    for (auto &row : p) {
      ans.push_back(row.back());
    }
    return ans;
  }
};

class Solution2 {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *cur, int deep) {
      if (!cur) {
        return;
      }
      if (ans.size() == deep) {
        ans.push_back(cur->val);
      }
      dfs(cur->right, deep + 1);
      dfs(cur->left, deep + 1);
    };
    dfs(root, 0);
    return ans;
  }
};

signed main() {
  Solution2 sol;
  vector<int> node = {1, 2, 3, 4, -1, -1, -1, 5};
  TreeNode *root = buildTree(node);
  auto ans = sol.rightSideView(root);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}