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
  int countPairs(TreeNode *root, int distance) {
    int ans = 0;
    function<vector<int>(TreeNode *)> dfs = [&](TreeNode *node) -> vector<int> {
      if (!node) {
        return {};
      }
      if (!node->left && !node->right) {
        return {0};
      }
      vector<int> rec;
      auto left = dfs(node->left);
      for (auto &x : left) {
        if (++x > distance) {
          continue;
        }
        rec.push_back(x);
      }
      auto right = dfs(node->right);
      for (auto &x : right) {
        if (++x > distance) {
          continue;
        }
        rec.push_back(x);
      }
      for (auto &l : left)
        for (auto &r : right) {
          if (l + r <= distance)
            ++ans;
        }
      return rec;
    };
    dfs(root);
    return ans;
  }
};

signed main() {
  vector<int> node = {1, 2, 3, 4, 5, 6, 7};
  int dis = 3;
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.countPairs(root, dis) << endl;

  return 0;
}