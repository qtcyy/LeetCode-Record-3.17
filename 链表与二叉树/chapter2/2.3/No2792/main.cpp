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
  int countGreatEnoughNodes(TreeNode *root, int k) {
    int ans = 0;

    function<vector<int>(TreeNode *)> dfs = [&](TreeNode *node) -> vector<int> {
      if (!node) {
        return {};
      }

      vector<int> left = dfs(node->left);
      vector<int> right = dfs(node->right);

      vector<int> values;
      values.insert(values.end(), left.begin(), left.end());
      values.insert(values.end(), right.begin(), right.end());

      if (values.size() >= k) {
        sort(values.begin(), values.end());
        if (values.size() > k) {
          values.resize(k);
        }

        if (node->val > values.back()) {
          ans++;
        }
      }

      values.push_back(node->val);
      sort(values.begin(), values.end());
      if (values.size() > k) {
        values.resize(k);
      }

      return values;
    };

    dfs(root);
    return ans;
  }
};

signed main() {
  vector<int> node = {7, 6, 5, 4, 3, 2, 1};
  TreeNode *root = buildTree(node);
  int k = 2;
  Solution sol;
  cout << sol.countGreatEnoughNodes(root, k) << endl;

  return 0;
}