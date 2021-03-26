/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
struct NodeStatus {
  int x;
  int y;
};
class Solution {
 public:
  NodeStatus dfs(TreeNode *root) {
    if (root == nullptr) {
      return {0, 0};
    }
    auto lRet = dfs(root->left);
    auto rRet = dfs(root->right);
    NodeStatus ret = {.x = lRet.y + rRet.y + root->val, .y = std::max(lRet.x, lRet.y) + std::max(rRet.x, rRet.y)};
    return ret;
  }
  int rob(TreeNode *root) {
    auto ret = dfs(root);
    return ret.x > ret.y ? ret.x : ret.y;
  }
};
//[4,1,null,2,null,3]
//4
//1  4, 2
//2  2, 3
//3  3, 0
