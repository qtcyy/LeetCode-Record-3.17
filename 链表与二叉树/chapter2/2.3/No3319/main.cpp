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
  int kthLargestPerfectSubtree(TreeNode *root, int k) {
    vector<int> rec;
    function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int {
      if (!node) {
        return 0;
      }
      int left = dfs(node->left);
      int right = dfs(node->right);
      if (left < 0 || left != right) {
        return -1;
      }
      rec.push_back(left + 1);
      return left + 1;
    };
    dfs(root);
    if (k > rec.size()) {
      return -1;
    }
    ranges::nth_element(rec, rec.end() - k);
    return (1 << rec[rec.size() - k]) - 1;
  }
};

signed main() {
  vector<int> node = {5, 3, 6, 5, 2, 5, 7, 1, 8, -1, -1, 6, 8};
  int k = 2;
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.kthLargestPerfectSubtree(root, k) << endl;

  return 0;
}