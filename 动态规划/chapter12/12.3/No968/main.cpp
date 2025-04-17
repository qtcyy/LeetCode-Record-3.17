#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
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

const int INF = 0x3f3f3f3f;

class Solution {
public:
  int minCameraCover(TreeNode *root) {
    function<tuple<int, int, int>(TreeNode *)> dfs =
        [&](TreeNode *node) -> tuple<int, int, int> {
      if (!node) {
        return {INF, 0, 0};
      }
      auto [l_choose, l_by_fa, l_by_child] = dfs(node->left);
      auto [r_choose, r_by_fa, r_by_child] = dfs(node->right);
      int choose = min({l_choose, l_by_fa, l_by_child}) +
                   min({r_choose, r_by_fa, r_by_child}) + 1;
      int by_fa = min(l_choose, l_by_child) + min(r_choose, r_by_child);
      int by_child = min(
          {l_choose + r_by_child, l_by_child + r_choose, l_choose + r_choose});
      return {choose, by_fa, by_child};
    };
    auto [choose, _, by_child] = dfs(root);
    return max(choose, by_child);
  }
};

signed main() {
  vector<int> node = {0, 0, -1, 0, -1, 0, -1, -1, 0};
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.minCameraCover(root) << endl;

  return 0;
}